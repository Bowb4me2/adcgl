//
// Created by Carson Fricke on 7/29/2020 5:55pm PST
//


#ifndef __MATRIX_OPS_H__
#define __MATRIX_OPS_H__

namespace Tensor {

	namespace Operators {


		template<typename T>
		void dot(T* out, T* arg0, T* arg1, size_t arg0_size, size_t out_size) {
			for (size_t out_index = 0; out_index < out_size; out_index++) {
				for (size_t arg0_index = 0; arg0_index < arg0_size; arg0_index++) {
					out[out_index] += arg0[arg0_index] * arg1[out_index * arg0_size + arg0_index];
				}
			}
		}

		template<typename T>
		void outer(T* out, T* arg0, T* arg1, size_t arg0_size, size_t arg1_size) {
			for (size_t arg1_index = 0; arg1_index < arg1_size; arg1_index++) {
				for (size_t arg0_index = 0; arg0_index < arg0_size; arg0_index++) {
					out[arg1_index * arg0_size + arg0_index] = arg0[arg0_index] * arg1[arg1_index];
				}
			}
		}

		

	} // namespace Tensor::Operators

} // namespace Tensor

#endif // end guards