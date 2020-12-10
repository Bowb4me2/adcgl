//
// Created by Carson Fricke on 9/18/2020 11:14am PST
//


#include "Sum.h"

#include <cstdarg>


namespace Tensor {

	namespace Operator {

		template<typename T>
		void Sum<T>::pointer_procedure(
			T* target,
			Shape target_shape,
			T* tensor_pointers[1],
			Shape shapes[1]
		) {
			for (int64_t i = 0; i < shapes[0].size; i++) {
				target[0] += tensor_pointers[0][i];
			}
		}

		template<typename T>
		void Sum<T>::validate(
			T* target_contents,
			Shape target_shape,
			T* tensor_contents[1],
			Shape shapes[1]
		) {

			if (target_shape.size != 1) {
				throw "sum must evaluate to to a scalar";
			}

		}

		template<typename T>
		void Sum<T>::settup_directives(
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
		template class Sum<int>;
		template class Sum<float>;
		template class Sum<double>;
		template class Sum<unsigned int>;


	} // namespace Tensor::Operator

} // namespace Tensor