//
// Created by Carson Fricke on 8/14/2020 8:32pm PST
//


#include "Outer.h"

namespace swing {

	namespace tensor {

		namespace oper {

			template<typename T>
			void Outer<T>::pointer_procedure(
				T* target,
				Shape target_shape,
				T* tensor_pointers[2],
				Shape shapes[2]
			) {
				for (int64_t i = 0; i < target_shape.size; i++) {
					target[i] = tensor_pointers[0][i] + tensor_pointers[1][i];
				}
			}

			template<typename T>
			void Outer<T>::validate(
				T* target_contents,
				Shape target_shape,
				T* tensor_contents[2],
				Shape shapes[2]
			) {


			}

			template<typename T>
			void Outer<T>::settup_directives(
				T* target_contents,
				Shape target_shape,
				T* tensor_contents[2],
				Shape shapes[2],
				T* (&modified_tensor_contents)[2],
				Shape(&modified_shapes)[2]
			) {

				// no brodcast needed
				modified_shapes[0] = shapes[0];
				modified_shapes[1] = shapes[1];

				modified_tensor_contents[0] = tensor_contents[0];
				modified_tensor_contents[1] = tensor_contents[1];

			}

			// explicit instantiations
			template class Outer<int>;
			template class Outer<float>;
			template class Outer<double>;
			template class Outer<unsigned int>;

		} // namespace swing::tensor::oper

	} // namespace swing::tensor

}
