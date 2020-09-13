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
			// fix
			if (arg0_shape.dims + arg1_shape.dims > out_shape.dims) {
				throw "too many dims";
			}

			if (arg0_shape.size * arg1_shape.size > out_shape.size) {
				throw "argument sizes are too large";
			}

			if (!out_shape.is_brodcastable(arg0_shape)) {
				throw "arg0 is of incompatible shape";
			}

			if (!out_shape.is_brodcastable(arg1_shape)) {
				throw "arg1 is of incompatible shape";
			}
		}

		template<typename T>
		bool Dot<T>::requires_brodcast(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			// fix
			bool temp = arg0_shape.is_equal(Shape::concatenate(out_shape, arg1_shape));

			bool temp = arg1_shape.is_equal(Shape::concatenate(out_shape, arg0_shape));

			return !out_shape.is_equal(Shape::concatenate(arg0_shape, arg1_shape));
		}

		template<typename T>
		bool Dot<T>::brodcast_which(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			//fix
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
		Shape Dot<T>::brodcast_shape(Shape out_shape, Shape arg0_shape, Shape arg1_shape, bool which) {
			//fix
			Shape shape_to_brodcast_to;

			size_t* shape = nullptr;

			size_t dim_difference;

			if (which) {

				dim_difference = out_shape.dims - arg1_shape.dims;

				shape = new size_t[dim_difference];

				for (size_t shape_index = 0; shape_index < dim_difference; shape_index++) {
					shape[shape_index] = out_shape[shape_index];
				}
			}
			else {

				dim_difference = out_shape.dims - arg0_shape.dims;

				shape = new size_t[dim_difference];

				for (size_t shape_index = 0; shape_index < dim_difference; shape_index++) {
					shape[shape_index] = out_shape[shape_index + arg0_shape.dims];
				}
			}

			shape_to_brodcast_to = Shape(shape, dim_difference);

			return shape_to_brodcast_to;
		}

		// explicit instantiations
		template class Dot<int>;
		template class Dot<float>;
		template class Dot<double>;
		template class Dot<unsigned int>;

	} // namespace Tensor::Operator

} // namespace Tensor
