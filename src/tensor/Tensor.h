//
// Created by Carson Fricke on 5/17/2020 6:03pm PST
//

#ifndef __TENSOR_TENSOR_H__
#define __TENSOR_TENSOR_H__

constexpr size_t MAX_TENSOR_SIZE = 100000;


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

			void brodcast_to_mem_recursive(Tensor<T>& iterable, size_t depth, size_t dim_difference, size_t host_index, size_t iterable_index, Shape& shape); /*{

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
			}*/ // recursive brodcast helper function

			template<typename T>
			friend class Operator::Operator;

			void brodcast_to_mem(Tensor<T>& iterable);

			void brodcast_to_mem(Tensor<T>& iterable, Shape& shape);

			Tensor(T* location, Shape shape);

		public:

			template<typename T>
			friend std::ostream& operator<<(std::ostream& os, const Tensor<T>& tensor);

			Tensor<T> operator[](size_t index);

			Tensor();

			Tensor(size_t size);

			Tensor(Shape shape);

			template<size_t N>
			Tensor(const T(&iterable)[N])
				: size(N),
				iterable(new T[N]),
				shape(N) {

				for (size_t i = 0; i < N; i++) {
					this->iterable[i] = iterable[i];
				}
			}

			void fill(T fill_contents);

			template<size_t N>
			void fill(const T(&iterable)[N]) {

				for (size_t i = 0; i < N; i++) {
					this->iterable[i] = iterable[i];
				}
			}

			Tensor<T>* clone();

			void clear_iterable() {
				fill(T(0));
			}

			// remove ones from shape, removing excess dims
			void collapse_ones();

			void clear_brodcast_iterable();

			inline bool is_brodcastable(Tensor<T>& iterable);

			inline size_t get_size();

			inline Shape get_shape();

			T* get_iterable();

			T* get_brodcast_iterable();

	}; // class Tensor::Tensor<T>

	// explicit instantiation of brodcast iterable
	template<typename T>
	T* Tensor<T>::brodcast_iterable = new T[MAX_TENSOR_SIZE];

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