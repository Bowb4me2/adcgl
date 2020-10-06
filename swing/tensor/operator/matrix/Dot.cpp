//
// Created by Carson Fricke on 9/7/2020 12:53pm PST
//


#include "Dot.h"

namespace Tensor {

	namespace Operator {
	
		template<typename T> 
		void Dot<T>::procedure(T* target, T* arg0, T* arg1, Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			if (arg1_shape.size >= arg0_shape.size) {
				for (size_t target_index = 0; target_index < target_shape.size; target_index++) {
					for (size_t arg0_index = 0; arg0_index < arg0_shape.size; arg0_index++) {
						target[target_index] += arg0[arg0_index] * arg1[target_index * arg0_shape.size + arg0_index];
					}
				}
			}
			else {
				for (size_t target_index = 0; target_index < target_shape.size; target_index++) {
					for (size_t arg1_index = 0; arg1_index < arg1_shape.size; arg1_index++) {
						target[target_index] += arg1[arg1_index] * arg0[target_index * arg1_shape.size + arg1_index];
					}
				}
			}
		}

		template<typename T>
		void Dot<T>::validate(Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			
			//std::ctarget << arg0_shape.is_brodcastable(target_shape) << " " << arg0_shape.is_brodcastable(arg1_shape)) << "\n";			
			// fix maybe
			Shape arg1_composite = Shape::concatenate(arg1_shape, target_shape);

			Shape arg0_composite = Shape::concatenate(arg0_shape, target_shape);

			if (arg0_shape.is_brodcastable(arg1_composite)) {
				

			}
			else if (arg1_shape.is_brodcastable(arg0_composite)) {
			}
			else {
				

				throw "tensor shapes are incompatible for brodcast";
			}
		}

		template<typename T>
		bool Dot<T>::requires_brodcast(Shape target_shape, Shape arg0_shape, Shape arg1_shape) {

			return target_shape.dims != (arg0_shape.dims > arg1_shape.dims ? 
				arg0_shape.dims - arg1_shape.dims :
				arg1_shape.dims - arg0_shape.dims);
		}

		template<typename T>
		bool Dot<T>::brodcast_which(Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			return arg0_shape.dims > arg1_shape.dims;
		}

		template<typename T>
		Shape Dot<T>::brodcast_shape(Shape target_shape, Shape arg0_shape, Shape arg1_shape, bool which) {
			
			if (which) {
				return Shape::concatenate(target_shape, arg1_shape);
			}
			else {
				return Shape::concatenate(target_shape, arg0_shape);
			}
			
		}

		// explicit instantiations
		template class Dot<int>;
		template class Dot<float>;
		template class Dot<double>;
		template class Dot<unsigned int>;

	} // namespace Tensor::Operator

} // namespace Tensor
