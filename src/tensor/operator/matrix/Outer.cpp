//
// Created by Carson Fricke on 8/14/2020 8:32pm PST
//


#include "Outer.h"

namespace Tensor {

	namespace Operator {
	
		template<typename T> 
		void Outer<T>::procedure(T* out, T* arg0, T* arg1, Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			for (size_t arg1_index = 0; arg1_index < arg1_shape.size; arg1_index++) {
				for (size_t arg0_index = 0; arg0_index < arg0_shape.size; arg0_index++) {
					out[arg1_index * arg0_shape.size + arg0_index] = arg0[arg0_index] * arg1[arg1_index];
				}
			}
		}

		template<typename T>
		void Outer<T>::validate(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			if (!(out_shape.is_brodcastable(arg0_shape) || out_shape.is_brodcastable(arg1_shape))) {
				throw "input sizes are incompatible";
			}
		}

		template<typename T>
		bool Outer<T>::requires_brodcast(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			return !arg0_shape.is_equal(arg1_shape);
		}

		template<typename T>
		bool Outer<T>::brodcast_which(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			return false;
		}

		template<typename T>
		Shape Outer<T>::brodcast_shape(Shape out_shape, Shape arg0_shape, Shape arg1_shape, bool which)
		{
			return Shape();
		}

		// explicit instantiations
		template class Outer<int>;
		template class Outer<float>;
		template class Outer<double>;
		template class Outer<unsigned int>;

	} // namespace Tensor::Operator

} // namespace Tensor
