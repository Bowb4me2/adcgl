//
// Created by Carson Fricke on 8/14/2020 8:32pm PST
//


#include "Sub.h"

namespace Tensor {

	namespace Operator {

		template<typename T>
		void Sub<T>::procedure(T* target, T* arg0, T* arg1, Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			for (size_t index = 0; index < target_shape.size; index++) {
				target[index] = arg0[index] - arg1[index];
			}
		}

		template<typename T>
		void Sub<T>::validate(Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			if (!(target_shape.is_brodcastable(arg0_shape) || target_shape.is_brodcastable(arg1_shape))) {
				throw "input sizes are incompatible";
			}
		}

		template<typename T>
		bool Sub<T>::requires_brodcast(Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			return !arg0_shape.is_equal(arg1_shape);
		}

		template<typename T>
		bool Sub<T>::brodcast_which(Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			
			if (target_shape.is_equal(arg1_shape)) {
				if (target_shape.is_brodcastable(arg0_shape)) {
					return true;
				}
				else {
					throw "not brodcastable";
				}
			}
			else if (target_shape.is_equal(arg0_shape)) {
				if (target_shape.is_brodcastable(arg1_shape)) {
					return false;
				}
				else {
					throw "not brodcastable";
				}
			}
		}

		template<typename T>
		Shape Sub<T>::brodcast_shape(Shape target_shape, Shape arg0_shape, Shape arg1_shape, bool which)
		{
			return target_shape;
		}
		
		// explicit instantiations
		template class Sub<int>;
		template class Sub<float>;
		template class Sub<double>;
		template class Sub<unsigned int>;


	} // namespace Tensor::Operator

} // namespace Tensor
