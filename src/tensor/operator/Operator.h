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

				virtual void procedure(T* out, T* arg0, T* arg1, Shape out_shape, Shape arg0_shape, Shape arg1_shape) = 0;
				
				virtual void validate(Shape out_shape, Shape arg0_shape, Shape arg1_shape) = 0;

				virtual bool requires_brodcast(Shape out_shape, Shape arg0_shape, Shape arg1_shape) = 0;

				virtual bool brodcast_which(Shape out_shape, Shape arg0_shape, Shape arg1_shape) = 0;

				virtual Shape brodcast_shape(Shape out_shape, Shape arg0_shape, Shape arg1_shape, bool which) = 0;

				// after validation, ensures all args are propperly brodcast to their respective shapes
				void brodcast_pragma(
					Tensor<T>& out,
					Tensor<T>& arg0,
					Tensor<T>& arg1,
					T** out_iterable,
					T** arg0_iterable,
					T** arg1_iterable,
					Shape& out_shape,
					Shape& arg0_shape,
					Shape& arg1_shape) {

					if (!requires_brodcast(out.shape, arg0.shape, arg1.shape)) {
						
						*out_iterable = out.iterable;
						*arg0_iterable = arg0.iterable;
						*arg1_iterable = arg1.iterable;

						out_shape = out.shape;
						arg0_shape = arg0.shape;
						arg1_shape = arg1.shape;
					}
					else {

						bool which_arg_to_brodcast = brodcast_which(out.shape, arg0.shape, arg1.shape);

						Shape brodcast_to_shape = brodcast_shape(out.shape, arg0.shape, arg1.shape, which_arg_to_brodcast);

						if (which_arg_to_brodcast) {

							out.brodcast_to_mem(arg0, brodcast_to_shape);

							*out_iterable = out.iterable;
							*arg0_iterable = out.brodcast_iterable;
							*arg1_iterable = arg1.iterable;

							out_shape = out.shape;
							arg0_shape = brodcast_to_shape;
							arg1_shape = arg1.shape;
						}
						else {

							out.brodcast_to_mem(arg1, brodcast_to_shape);

							*out_iterable = out.iterable;
							*arg0_iterable = arg0.iterable;
							*arg1_iterable = out.brodcast_iterable;

							out_shape = out.shape;
							arg0_shape = arg0.shape;
							arg1_shape = brodcast_to_shape;
						}
					}
				}

			public:

				void operator()(Tensor<T>& out, Tensor<T>& arg0, Tensor<T>& arg1) {

					validate(out.shape, arg0.shape, arg1.shape);

					T* out_iterable = nullptr;
					T* arg0_iterable = nullptr;
					T* arg1_iterable = nullptr;

					
					Shape out_shape;
					Shape arg0_shape;
					Shape arg1_shape;

					brodcast_pragma(
						out, 
						arg0, 
						arg1, 
						&out_iterable, 
						&arg0_iterable, 
						&arg1_iterable, 
						out_shape, 
						arg0_shape, 
						arg1_shape);

					procedure(
						out_iterable,
						arg0_iterable,
						arg1_iterable,
						out_shape,
						arg0_shape,
						arg1_shape);
				}

		}; // class Tensor::Operators::TensorOperator
		
	} // namespace Tensor::Operators

} // namespace Tensor


#endif // end guards
