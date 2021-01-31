//
// Created by Carson Fricke on 12/10/2020 2:24pm PST
//


#include "Square.h"

#include <cstdarg>


namespace swing {

	namespace tensor {

		namespace oper {

			template<typename T>
			void Square<T>::pointer_procedure(
				T* target,
				Shape target_shape,
				T* tensor_pointers[1],
				Shape shapes[1]
			) {
				for (int64_t i = 0; i < shapes[0].size; i++) {
					target[i] = tensor_pointers[0][i] * tensor_pointers[0][i];
				}
			}

			template<typename T>
			void Square<T>::validate(
				T* target_contents,
				Shape target_shape,
				T* tensor_contents[1],
				Shape shapes[1]
			) {

				if (!target_shape.is_equal(shapes[0])) {
					throw "square requires target and input to be the same shape";
				}
			}

			template<typename T>
			void Square<T>::settup_directives(
				T* target_contents,
				Shape target_shape,
				T* tensor_contents[1],
				Shape shapes[1],
				T* (&modified_tensor_contents)[1],
				Shape(&modified_shapes)[1]
			) {

				// no brodcast needed
				modified_shapes[0] = shapes[0];
				modified_shapes[1] = shapes[1];

				modified_tensor_contents[0] = tensor_contents[0];
				modified_tensor_contents[1] = tensor_contents[1];

			}

			// explicit instantiations
			template class Square<int>;
			template class Square<float>;
			template class Square<double>;
			template class Square<unsigned int>;


		} // namespace swing::tensor::oper

	} // namespace swing::tensor

} // namespace swing