//
// Created by Carson Fricke on 12/24/2020 1:26pm PST
//

#include "Reduce.h"

namespace swing {

	namespace tensor {

		namespace oper {

			template<typename T>
			void Reduce<T>::pointer_procedure(
				T* target,
				Shape target_shape,
				T* tensor_pointers[1],
				Shape shapes[1],
				int&& dims
			) {


				for (uint64_t target_index = 0; target_index < target_shape.size) {

					for (uint64_t)

				}

			}

			template<typename T>
			void Reduce<T>::validate(
				T* target,
				Shape target_shape,
				T* tensor_pointers[1],
				Shape shapes[1],
				int&& dims
			) {

				for (uint64_t index = 0; index < target_shape.dims; index++) {

				}

			}

			template<typename T>
			void Reduce<T>::settup_directives(
				T* target_contents,
				Shape target_shape,
				T* tensor_contents[1],
				Shape shapes[1],
				T* (&modified_tensor_contents)[1],
				Shape(&modified_shapes)[1],
				int&& dims
			) {

			}


		} // namespace swing::tensor::oper

	} // namespace swing::tensor

} // namespace swing