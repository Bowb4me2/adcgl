//
// Created by Carson Fricke on 5/20/2020 4:36pm PST
//

#ifndef __ELEMENTWISE_OPS_H__
#define __ELEMENTWISE_OPS_H__

namespace Tensor {

	namespace Operators {

		 
		template<typename T>
		void add(T* out, T* arg0, T* arg1, size_t size) {
			for (size_t index = 0; index < size; index++) {
				out[index] = arg0[index] + arg1[index];
			}
		}

		template<typename T>
		void sub(T* out, T* arg0, T* arg1) {
			for (size_t index = 0; index < size; index++) {
				out[index] = arg0[index] - arg1[index];
			}
		}

		template<typename T>
		void mul(T* out, T* arg0, T* arg1) {
			for (size_t index = 0; index < size; index++) {
				out[index] = arg0[index] * arg1[index];
			}
		}

		template<typename T>
		void div(T* out, T* arg0, T* arg1) {
			for (size_t index = 0; index < size; index++) {
				out[index] = arg0[index] / arg1[index];
			}
		}

	} // namespace Tensor::Operators

} // namespace Tensor

#endif // end guards