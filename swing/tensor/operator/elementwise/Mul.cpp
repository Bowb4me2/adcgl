//
// Created by Carson Fricke on 8/14/2020 8:32pm PST
//


#include "Mul.h"

namespace Tensor {

	namespace Operator {

		template<typename T>
		void Mul<T>::pointer_procedure(
			T* target,
			Shape target_shape,
			T* tensor_pointers[2],
			Shape shapes[2]
		) {
			for (int64_t i = 0; i < target_shape.size; i++) {
				target[i] = tensor_pointers[0][i] * tensor_pointers[1][i];
			}
		}

		template<typename T>
		void Mul<T>::validate(
			T* target_contents,
			Shape target_shape,
			T* tensor_contents[2],
			Shape shapes[2]
		) {

			if (
				!(target_shape.is_equal(shapes[0]) ||
				target_shape.is_equal(shapes[1]))
			) {
				throw "tensor_arg shapes are incompatible with target shape";
			}

		}

		template<typename T>
		void Mul<T>::settup_directives(
			T* target_contents,
			Shape target_shape,
			T* tensor_contents[2],
			Shape shapes[2],
			T* (&modified_tensor_contents)[2],
			Shape(&modified_shapes)[2]
		) {

			if (target_shape.is_equal(shapes[1]) && !target_shape.is_equal(shapes[0])) {

				modified_shapes[0] = shapes[1];
				modified_shapes[1] = shapes[1];

				modified_tensor_contents[0] = brodcast_pointer(tensor_contents[0], shapes[0], shapes[1]);
				modified_tensor_contents[1] = tensor_contents[1];

			}
			else if (target_shape.is_equal(shapes[0]) && !target_shape.is_equal(shapes[1])) {

				modified_shapes[0] = shapes[0];
				modified_shapes[1] = shapes[0];

				modified_tensor_contents[0] = tensor_contents[0];
				modified_tensor_contents[1] = brodcast_pointer(tensor_contents[1], shapes[0], shapes[0]);
			}
			else {

				// no brodcast needed
				modified_shapes[0] = shapes[0];
				modified_shapes[1] = shapes[1];

				modified_tensor_contents[0] = tensor_contents[0];
				modified_tensor_contents[1] = tensor_contents[1];
			}

		}

		// explicit instantiations
		template class Mul<int>;
		template class Mul<float>;
		template class Mul<double>;
		template class Mul<unsigned int>;

	} // namespace Tensor::Operator

} // namespace Tensor