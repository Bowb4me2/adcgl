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

			public:

				void operator()(Tensor<T>& out, Tensor<T>& arg0, Tensor<T>& arg1) {

					validate(out.shape, arg0.shape, arg1.shape);

					if (requires_brodcast(out.shape, arg0.shape, arg1.shape)) {

						if (arg0.is_brodcastable(arg1)) {

							arg0.brodcast_to_mem(arg1);

							procedure(out.iterable, arg0.iterable, arg0.brodcast_iterable, out.shape, arg0.shape, arg1.shape);
						}
						else if (arg1.is_brodcastable(arg0)) {

							arg1.brodcast_to_mem(arg0);

							procedure(out.iterable, arg1.brodcast_iterable, arg1.iterable, out.shape, arg0.shape, arg1.shape);
						}
					}
					else {

						procedure(out.iterable, arg0.iterable, arg1.iterable, out.shape, arg0.shape, arg1.shape);
					}
				}

		}; // class Tensor::Operators::TensorOperator
		
	} // namespace Tensor::Operators

} // namespace Tensor


#endif // end guards
