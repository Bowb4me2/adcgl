//
// Created by Carson Fricke on 5/17/2020 6:03pm PST
//

#ifndef _TENSOR_H__
#define _TENSOR_H__

#include "Shape.h"

namespace Tensor {
	
	template<typename T>
	class Tensor {
	
		protected:

			template<typename T>
			friend static void operate(Tensor<T>& out, Tensor<T>& arg0, Tensor<T>& arg1, void (*operation)(T*, T*, T*, size_t));

			size_t size; // total number of elements in the Tensor

			T* iterable; // contents of the tensor

			Shape shape; // The size of the tensor divided by dimension

			T* brodcast_iterable; // iterable used for brodcasting other values to the same size

			virtual void brodcast_to_mem(Tensor<T>& iterable) = 0;
			
			virtual void operate(Tensor<T>& out, void (*operation)(T*, T*, T*, size_t)) = 0;

		public:

			Tensor()
				: size(1),
				iterable(new T[1]),
				shape(1),
				brodcast_iterable(new T[1]) {
			}

			Tensor(size_t size)
				: size(size),
				iterable(new T[size]),
				shape(size),
				brodcast_iterable(new T[size]) {
			}

			Tensor(Shape shape)
				: size(shape.size),
				iterable(new T[shape.size]),
				shape(shape),
				brodcast_iterable(new T[shape.size]) {
			}

			template<size_t N>
			Tensor(const T(&iterable)[N])
				: size(N),
				iterable(new T[N]),
				shape(N),
				brodcast_iterable(new T[N]) {

				for (size_t i = 0; i < N; i++) {
					this->iterable[i] = iterable[i];
				}

			}

			virtual void fill(T) = 0;

			virtual T& operator[](int index) = 0;

			bool is_brodcastable(Tensor<T>& iterable) {
				return this->shape.is_brodcastable(iterable.shape);
			}

			size_t get_size() {
				return this->size;
			} 

			Shape& get_shape() {
				return this->shape;
			}

			virtual T* get_iterable() = 0;

			virtual T* get_brodcast_iterable() = 0;

	}; // class Tensor::Tensor<T>

	template<typename T>
	static void operate(Tensor<T>& out, Tensor<T>& arg0, Tensor<T>& arg1, void (*operation)(T*, T*, T*, size_t)) {
		if (arg0.is_brodcastable(arg1)) {
			arg0.brodcast_to_mem(arg1);

			arg0.operate(out, operation);
		}
		else if (arg1.is_brodcastable(arg0)) {
			arg1.brodcast_to_mem(arg0);

			arg1.operate(out, operation);
		}
		else {
			throw "Tensors are not brodcastable togther";
		}
	}

} // namespace Tensor


#endif // end guards