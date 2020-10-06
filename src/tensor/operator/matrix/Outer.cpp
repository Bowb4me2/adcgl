//
// Created by Carson Fricke on 8/14/2020 8:32pm PST
//


#include "Outer.h"

namespace Tensor {

	namespace Operator {
	
		template<typename T> 
		void Outer<T>::procedure(T* target, T* arg0, T* arg1, Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			for (size_t arg1_index = 0; arg1_index < arg1_shape.size; arg1_index++) {
				for (size_t arg0_index = 0; arg0_index < arg0_shape.size; arg0_index++) {
					target[arg1_index * arg0_shape.size + arg0_index] = arg0[arg0_index] * arg1[arg1_index];
				}
			}
		}

		template<typename T>
		void Outer<T>::validate(Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			
			if (arg0_shape.dims + arg1_shape.dims > target_shape.dims) {
				throw "too many dims";
			}

			if (arg0_shape.size * arg1_shape.size > target_shape.size) {
				throw "argument sizes are too large";
			}

			if (!target_shape.is_brodcastable(arg0_shape)) {
				throw "arg0 is of incompatible shape";
			}

			if (!target_shape.is_brodcastable(arg1_shape)) {
				throw "arg1 is of incompatible shape";
			}
		}

		template<typename T>
		bool Outer<T>::requires_brodcast(Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			return !target_shape.is_equal(Shape::concatenate(arg0_shape, arg1_shape));
		}

		template<typename T>
		bool Outer<T>::brodcast_which(Shape target_shape, Shape arg0_shape, Shape arg1_shape) {
			
			if (arg0_shape.size < arg1_shape.size && arg0_shape.dims <= arg1_shape.dims) {
				return true;
			}
			else if (arg1_shape.size > arg0_shape.size && arg1_shape.dims <= arg0_shape.dims) {
				return false;
			}
			else {
				throw "Arguments are incompatible";
			}
		}

		template<typename T>
		Shape Outer<T>::brodcast_shape(Shape target_shape, Shape arg0_shape, Shape arg1_shape, bool which) {
			
			Shape shape_to_brodcast_to;

			size_t* shape = nullptr;

			size_t dim_difference;

			if (which) {
				
				dim_difference = target_shape.dims - arg1_shape.dims;

				shape = new size_t[dim_difference];

				for (size_t shape_index = 0; shape_index < dim_difference; shape_index++) {
					shape[shape_index] = target_shape[shape_index];
				}
			}
			else {
				
				dim_difference = target_shape.dims - arg0_shape.dims;

				shape = new size_t[dim_difference];

				for (size_t shape_index = 0; shape_index < dim_difference; shape_index++) {
					shape[shape_index] = target_shape[shape_index + arg0_shape.dims];
				}
			}
			
			shape_to_brodcast_to = Shape(shape, dim_difference);

			return shape_to_brodcast_to;
		}

		// explicit instantiations
		template class Outer<int>;
		template class Outer<float>;
		template class Outer<double>;
		template class Outer<unsigned int>;

	} // namespace Tensor::Operator

} // namespace Tensor
