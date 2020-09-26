//
// Created by Carson Fricke on 5/17/2020 6:03pm PST
//

#ifndef __TENSOR_TENSOR_H__
#define __TENSOR_TENSOR_H__

constexpr size_t MAX_BRODCAST_SPACE_ALLOC = 10000;


#include "Shape.h"
#include "device/Device.h"


namespace Tensor {
	
	typedef double scalar_t;

	namespace Operator {
		
		template<typename T>
		class Operator;
	}

	template<typename T=scalar_t/*, Device::Device I=0*/>
	class Tensor {

		private:

			size_t size; // total number of elements in the Tensor

			T* iterable; // contents of the tensor

			Shape shape; // The size of the tensor divided by dimension

			static T* brodcast_iterable; // iterable used for brodcasting other values to the same size

			void brodcast_to_mem_recursive(Tensor<T>& iterable, size_t depth, size_t dim_difference, size_t host_index, size_t iterable_index, Shape& shape) {

				// ensures recursion stops when tensor tips are reached
				if (depth < shape.dims) {

					// ensures that if iterable tensor has less dims that they are not accessed until later
					if (depth < dim_difference) {

						// recur once for every item in the current shape dimention, selected by depth
						// this runs before the iterable tensor is accessable
						for (size_t shape_index = 0; shape_index < shape.shape[depth]; shape_index++) {
							brodcast_to_mem_recursive(iterable,
								depth + 1,
								dim_difference,
								host_index * shape.shape[depth] + shape_index,
								0, 
								shape);
						}
					}
					else {

						// recur once for every item in the current shape dimention, selected by depth
						// this runs only if the iterable tensor can now be accessed
						for (size_t shape_index = 0; shape_index < shape.shape[depth]; shape_index++) {
							brodcast_to_mem_recursive(iterable,
								depth + 1,
								dim_difference, host_index * shape.shape[depth] + shape_index,
								iterable_index * iterable.shape[depth - dim_difference] + (iterable.shape[depth] == 1) ? 0 : shape_index, 
								shape);
						}
					}

				}
				else {
					// copies the value from the appropriate iterable's index to the brodcast_iterables index
					this->brodcast_iterable[host_index] = iterable.iterable[iterable_index];
				}

			} // recursive brodcast helper function

			template<typename T>
			friend class Operator::Operator;

			void brodcast_to_mem(Tensor<T>& iterable) {
				brodcast_to_mem_recursive(iterable, 0, this->shape.dims - iterable.shape.dims, 0, 0, this->shape);
			}

			void brodcast_to_mem(Tensor<T>& iterable, Shape& shape) {
				brodcast_to_mem_recursive(iterable, 0, this->shape.dims - iterable.shape.dims, 0, 0, shape);
			}

			Tensor(T* location, Shape shape) 
				: size(shape.size), 
				  iterable(location), 
				  shape(shape) {
				


			}

		public:

			template<typename T>
			friend std::ostream& operator<<(std::ostream& os, const Tensor<T>& tensor);

			// implement this
			void operator[](size_t index) {
				/*
				if (index >= this->shape.shape[0] || index < 0) {
					throw "index outside of tensor range, out of bounds exception";
				}

				if (this->size == 1) {
					return Tensor<T>(this->iterable, this->shape);
				}

				size_t shape_array[this->shape.dims - 1];

				for (size_t shape_index = 1; shape_index < this->shape.dims; shape_index++) {
					shape_array[shape_index - 1] = this->shape.shape[shape_index];
				}

				Shape shape(shape_array);

				T* location = &this->iterable[shape.size * index];

				return Tensor<T>(location, shape);*/
			}

			Tensor()
				: size(1),
				  iterable(new T[1]),
				  shape(1) {

				  fill(T(0));
			}

			Tensor(size_t size)
				: size(size),
				  iterable(new T[size]),
				  shape(size) {

				  fill(T(0));
			}

			Tensor(Shape shape)
				: size(shape.size),
				  iterable(new T[shape.size]),
				  shape(shape) {

				  fill(T(0));
			}

			template<size_t N>
			Tensor(const T(&iterable)[N])
				: size(N),
				  iterable(new T[N]),
				  shape(N) {

				for (size_t i = 0; i < N; i++) {
					this->iterable[i] = iterable[i];
				}
			}

			void fill(T fill_contents) {
				
				for (size_t index = 0; index < this->size; index++) {
					this->iterable[index] = fill_contents;
				}
			}

			template<size_t N>
			void fill(const T(&iterable)[N]) {

				for (size_t i = 0; i < N; i++) {
					this->iterable[i] = iterable[i];
				}
			}

			Tensor<T>* clone() {
				
				Tensor<T>* tensor = new Tensor<T>(this->shape);

				//for (size_t item_index = 0; item_index < this->size; item_index++) {
				//	tensor->iterable[item_index] = this->iterable[item_index];
				//}

				return tensor;
			}

			void clear_iterable() {
				fill(T(0))
			}

			// remove ones
			void collapse_ones() {
				
				size_t non_one_values = 0;

				size_t* shape_array;

				for (size_t shape_index = 0; shape_index < this->shape.dims; shape_index++) {
					if (this->shape.shape[shape_index] != 1) {
						non_one_values++;
					}
				}
				if (non_one_values > 0) {
					shape_array = new size_t[non_one_values];

					size_t new_shape_index = 0;

					for (size_t old_shape_index = 0; old_shape_index < this->shape.dims; old_shape_index++) {
						if (this->shape.shape[old_shape_index] != 1) {
							shape_array[new_shape_index] = this->shape.shape[old_shape_index];
							new_shape_index++;
						}
					}

					this->shape.dims = non_one_values;

				}
				else {
					shape_array = new size_t;

					*shape_array = 1;

					this->shape.dims = 1;
				}

				delete[] this->shape.shape;

				this->shape.shape = shape_array;

			}

			void clear_brodcast_iterable() {
				
				for (size_t brodcast_iterable_index = 0; brodcast_iterable_index < SIZE_MAX; brodcast_iterable_index++) {
					this->brodcast_iterable[brodcast_iterable_index] = T(0);
				}
			}

			inline bool is_brodcastable(Tensor<T>& iterable) {
				return this->shape.is_brodcastable(iterable.shape);
			}

			inline size_t get_size() {
				return this->size;
			} 

			inline Shape get_shape() {
				return this->shape;
			}

			T* get_iterable() {
				return this->iterable;
			}

			T* get_brodcast_iterable() {
				return this->brodcast_iterable;
			}

			

	}; // class Tensor::Tensor<T>

	// explicit instantiation of brodcast iterable
	template<typename T>
	T* Tensor<T>::brodcast_iterable = new T[MAX_BRODCAST_SPACE_ALLOC];

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Tensor<T>& tensor) {

		os << typeid(tensor).name() << "( " << tensor.shape << " ){ ";

		for (size_t iterable_index = 0; iterable_index < tensor.size - 1; iterable_index++) {
			os << tensor.iterable[iterable_index] << ", ";
		}

		os << tensor.iterable[tensor.size - 1] << " }";

		return os;
	}
	
	static size_t indicies_to_index(size_t* indicies, Shape shape) {

		size_t true_index = 0;

		size_t pivot = 1;

		for (size_t dim_index = shape.dims; dim_index > 0; dim_index--) {

			true_index += indicies[dim_index - 1] * pivot;

			pivot *= shape.shape[dim_index - 1];
		}

		return true_index;
	}

	static size_t* index_to_indicies(size_t index, Shape shape) {
		
		size_t* indicies = new size_t[shape.dims];


		size_t mod_index = index;
		size_t pivot_descending = shape.size;
		size_t individual_index;

		for (size_t dim_index = 0; dim_index < shape.dims; dim_index++) {

			pivot_descending /= shape.shape[dim_index];

			individual_index = mod_index / pivot_descending;
			indicies[dim_index] = individual_index;
			
			mod_index -= (pivot_descending * individual_index);
		}

		return indicies;
	}

} // namespace Tensor


#endif // end guards