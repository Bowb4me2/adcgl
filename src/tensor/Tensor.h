//
// Created by Carson Fricke on 5/17/2020 6:03pm PST
//

#ifndef _TENSOR_H__
#define _TENSOR_H__

#include "Shape.h"

#include <iostream>

namespace Tensor {


	template<typename T>
	class Tensor {
		private:

			size_t size; // total number of elements in the Tensor

			T* iterable; // contents of the tensor

			Shape shape; // The size of the tensor divided by dimension

			T* brodcaster_iterable; // iterable used for brodcasting other values to the same size

		public:

			T& operator[](int index) {
				if (index >= this->size || index < 0) {
					throw "index outside of tensor range, out of bounds exception";
				}

				return this->iterable[index];
			}

			Tensor()
				: size(1),
				  iterable(new T[1]),
				  shape(1),
				  brodcaster_iterable(new T[1]) {}

			Tensor(size_t size)
				: size(size),
				  iterable(new T[size]),
				  shape(size),
				  brodcaster_iterable(new T[size]) {}

			Tensor(Shape shape)
				: size(shape.get_size()),
				  iterable(new T[shape.get_size()]),
				  shape(shape),
				  brodcaster_iterable(shape.get_size()) {}

			template<size_t N>
			Tensor(const T(&iterable)[N])
				: size(N),
				  iterable(new T[N]),
				  shape(N),
				  brodcaster_iterable(new T[N]) {
				
				for (size_t i = 0; i < N; i++) {
					this->iterable[i] = iterable[i];
				}
			
			}

			bool is_brodcastable(Tensor<T> iterable) {
				return this->shape.is_brodcastible(iterable.get_shape());
			}

			size_t get_size() {
				return this->size;
			} 

			Shape& get_shape() {
				return this->shape;
			}

	}; // class Tensor::Tensor<T>

} // namespace Tensor


#endif // end guards