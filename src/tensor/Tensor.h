//
// Created by Carson Fricke on 5/17/2020 6:03pm PST
//

#ifndef _TENSOR_H__
#define _TENSOR_H__

#include "Shape.h"

namespace Tensor {


	template<typename T>
	class Tensor {
		private:

			size_t size; // total number of elements in the Tensor

			T* iterable; // contents of the tensor

			Shape shape; // The size of the tensor divided by dimension

			T* brodcast_iterable; // iterable used for brodcasting other values to the same size

			void brodcast_to_mem_recursive(Tensor<T> iterable, size_t depth, size_t dim_difference, size_t host_index, size_t iterable_index) { 
				
				// ensures recursion stops when tensor tips are reached
				if (depth < this->shape.dims) {
					
					// ensures that if iterable tensor has less dims that they are not accessed until later
					if (depth < dim_difference) {
						
						// recur once for every item in the current shape dimention, selected by depth
						// this runs before the iterable tensor is accessable
						for (size_t shape_index = 0; shape_index < this->shape.shape[depth]; shape_index++) {
							brodcast_to_mem_recursive(iterable,
							                          depth + 1, 
							                          dim_difference, 
							                          host_index * this->shape.shape[depth] + shape_index, 
							                          0);
						}
					} 
					else {
						
						// recur once for every item in the current shape dimention, selected by depth
						// this runs only if the iterable tensor can now be accessed
						for (size_t shape_index = 0; shape_index < this->shape.shape[depth]; shape_index++) {
							brodcast_to_mem_recursive(iterable,
							                          depth + 1, 
							                          dim_difference, host_index * this->shape.shape[depth] + shape_index, 
							                          iterable_index * iterable.shape.shape[depth - dim_difference] + (iterable.shape.shape[depth] == 1) ? 0 : shape_index);
						}
					}
					
				}
				else {
					// copies the value from the appropriate iterable's index to the brodcast_iterables index
					this->brodcast_iterable[host_index] = iterable.iterable[iterable_index];
				}

			} // recursive brodcast helper function

			void brodcast_to_mem(Tensor<T> iterable) {
				brodcast_to_mem_recursive(iterable, 0, this->shape.dims - iterable.shape.dims, 0, 0);
			}

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
				  brodcast_iterable(new T[1]) {}

			Tensor(size_t size)
				: size(size),
				  iterable(new T[size]),
				  shape(size),
				  brodcast_iterable(new T[size]) {}

			Tensor(Shape shape)
				: size(shape.size),
				  iterable(new T[shape.size]),
				  shape(shape),
				  brodcast_iterable(new T[shape.size]) {}

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

			bool is_brodcastable(Tensor<T> iterable) {
				return this->shape.is_brodcastible(iterable.shape);
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