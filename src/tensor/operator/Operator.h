//
// Created by Carson Fricke on 8/12/2020 11:26am PST
//

#ifndef __TENSOR_OPERATOR_H__
#define __TENSOR_OPERATOR_H__

#include "../Tensor.h"

typedef double scalar_t;


namespace Tensor {

	namespace Operator {
	
		template <typename T=scalar_t>
		class Operator {

			protected:

				virtual void procedure(T* target, T* arg0, T* arg1, Shape target_shape, Shape arg0_shape, Shape arg1_shape) = 0;
				
				virtual void validate(Shape target_shape, Shape arg0_shape, Shape arg1_shape) = 0;

				virtual bool requires_brodcast(Shape target_shape, Shape arg0_shape, Shape arg1_shape) = 0;

				virtual bool brodcast_which(Shape target_shape, Shape arg0_shape, Shape arg1_shape) = 0;

				virtual Shape brodcast_shape(Shape target_shape, Shape arg0_shape, Shape arg1_shape, bool which) = 0;

				// after validation, ensures all args are propperly brodcast to their respective shapes
				void brodcast_pragma(
					Tensor<T>& target,
					Tensor<T>& arg0,
					Tensor<T>& arg1,
					T** target_iterable,
					T** arg0_iterable,
					T** arg1_iterable,
					Shape& target_shape,
					Shape& arg0_shape,
					Shape& arg1_shape) {

					if (!requires_brodcast(target.shape, arg0.shape, arg1.shape)) {
						
						*target_iterable = target.iterable;
						*arg0_iterable = arg0.iterable;
						*arg1_iterable = arg1.iterable;

						target_shape = target.shape;
						arg0_shape = arg0.shape;
						arg1_shape = arg1.shape;
					}
					else {

						bool which_arg_to_brodcast = brodcast_which(target.shape, arg0.shape, arg1.shape);

						Shape brodcast_to_shape = brodcast_shape(target.shape, arg0.shape, arg1.shape, which_arg_to_brodcast);

						if (which_arg_to_brodcast) {

							target.brodcast_to_mem(arg0, brodcast_to_shape);

							*target_iterable = target.iterable;
							*arg0_iterable = target.brodcast_iterable;
							*arg1_iterable = arg1.iterable;

							target_shape = target.shape;
							arg0_shape = brodcast_to_shape;
							arg1_shape = arg1.shape;
						}
						else {

							target.brodcast_to_mem(arg1, brodcast_to_shape);

							*target_iterable = target.iterable;
							*arg0_iterable = arg0.iterable;
							*arg1_iterable = target.brodcast_iterable;

							target_shape = target.shape;
							arg0_shape = arg0.shape;
							arg1_shape = brodcast_to_shape;
						}
					}
				}
				
				inline void operation(Tensor<T>& target, Tensor<T>& arg0, Tensor<T>& arg1) {
					
					validate(target.shape, arg0.shape, arg1.shape);

					T* target_iterable = nullptr;
					T* arg0_iterable = nullptr;
					T* arg1_iterable = nullptr;


					Shape target_shape;
					Shape arg0_shape;
					Shape arg1_shape;

					brodcast_pragma(
						target,
						arg0,
						arg1,
						&target_iterable,
						&arg0_iterable,
						&arg1_iterable,
						target_shape,
						arg0_shape,
						arg1_shape);

					procedure(
						target_iterable,
						arg0_iterable,
						arg1_iterable,
						target_shape,
						arg0_shape,
						arg1_shape);
				}

			public:

				void operator()(Tensor<T>& target, Tensor<T>& arg0, Tensor<T>& arg1) {
					operation(target, arg0, arg1);
				}

		}; // class Tensor::Operators::TensorOperator
		
	} // namespace Tensor::Operators

} // namespace Tensor


#endif // end guards
