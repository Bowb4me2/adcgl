//
// Created by Carson Fricke on 9/18/2020 11:14am PST
//


#include "Sum.h"

#include <cstdarg>


namespace Tensor {

	namespace Operator {

		template<typename T>
		void Sum<T>::procedure(T* out, T* arg0, T* arg1, Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			for (size_t index = 0; index < arg0_shape.size; index++) {
				out[0] += arg0[index];
			}
		}

		template<typename T>
		void Sum<T>::validate(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			if (out_shape.size != 1) {
				throw "output shape must be a scalar";
			}
		}

		template<typename T>
		bool Sum<T>::requires_brodcast(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			return false;
		}

		template<typename T>
		bool Sum<T>::brodcast_which(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			return false;
		}

		template<typename T>
		Shape Sum<T>::brodcast_shape(Shape out_shape, Shape arg0_shape, Shape arg1_shape, bool which) {
			return out_shape;
		}

		template<typename T>
		void Sum<T>::operator()(Tensor<T>& out, Tensor<T>& arg0) {

			operation(out, arg0, Tensor<T>(0));
		}

		// explicit instantiations
		template class Sum<int>;
		template class Sum<float>;
		template class Sum<double>;
		template class Sum<unsigned int>;


	} // namespace Tensor::Operator

} // namespace Tensor