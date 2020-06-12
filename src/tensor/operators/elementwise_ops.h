//
// Created by Carson Fricke on 5/20/2020 4:36pm PST
//

#ifndef __ELEMENTWISE_OPS_H__
#define __ELEMENTWISE_OPS_H__

#include "../Tensor.h"

namespace Tensor {

	namespace Operators {

		template<typename T>
		void add(Tensor<T>& out, Tensor<T>& arg0, Tensor<T>& arg1) {
			if (arg0.is_brodcastable(arg1)) {
				

			} else if (arg1.is_brodcastable(arg0)) {
				

			} else {
				throw "Tensors are of incompatible Shapes, cannot be brodcast";
			}
		}

		template<typename T>
		void sub(Tensor<T>& out, Tensor<T>& arg0, Tensor<T>& arg1) {

		}

		template<typename T>
		void mul(Tensor<T>& out, Tensor<T>& arg0, Tensor<T>& arg1) {
			
		}

		template<typename T>
		void div(Tensor<T>& out, Tensor<T>& arg0, Tensor<T>& arg1) {

		}

	} // namespace Tensor::Operators

} // namespace Tensor

#endif // end guards