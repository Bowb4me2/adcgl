//
// Created by Carson Fricke on 9/7/2020 12:53pm PST
//


#include "Dot.h"

namespace Tensor {

	namespace Operator {
	
		template<typename T> 
		void Dot<T>::procedure(T* out, T* arg0, T* arg1, Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			for (size_t out_index = 0; out_index < out_shape.size; out_index++) {
				for (size_t arg0_index = 0; arg0_index < arg0_shape.size; arg0_index++) {
					out[out_index] += arg0[arg0_index] * arg1[out_index * arg0_shape.size + arg0_index];
				}
			}
		}

		template<typename T>
		void Dot<T>::validate(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			if (!(out_shape.is_brodcastable(arg0_shape) || out_shape.is_brodcastable(arg1_shape))) {
				throw "input sizes are incompatible";
			}
		}

		template<typename T>
		bool Dot<T>::requires_brodcast(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			return !arg0_shape.is_equal(arg1_shape);
		}

		template<typename T>
		bool Dot<T>::brodcast_which(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			return false;
		}

		template<typename T>
		Shape Dot<T>::brodcast_shape(Shape out_shape, Shape arg0_shape, Shape arg1_shape, bool which)
		{
			return Shape();
		}

		// explicit instantiations
		template class Dot<int>;
		template class Dot<float>;
		template class Dot<double>;
		template class Dot<unsigned int>;

	} // namespace Tensor::Operator

} // namespace Tensor
