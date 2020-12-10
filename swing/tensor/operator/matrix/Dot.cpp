//
// Created by Carson Fricke on 9/7/2020 12:53pm PST
//


#include "Dot.h"

namespace Tensor {

	namespace Operator {
	
		template<typename T>
		void Dot<T>::pointer_procedure(
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
		void Dot<T>::validate(
			T* target_contents,
			Shape target_shape,
			T* tensor_contents[2],
			Shape shapes[2]
		) {

		}

		template<typename T>
		void Dot<T>::settup_directives(
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
		template class Dot<int>;
		template class Dot<float>;
		template class Dot<double>;
		template class Dot<unsigned int>;

	} // namespace Tensor::Operator

} // namespace Tensor
