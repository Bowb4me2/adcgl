//
// Created by Carson Fricke on 10/2/2020 9:12pm PST
//

#include <Tensor.h>

namespace Tensor {

	// 
	// brodcast directives
	// 
	template<typename T>
	void Tensor<T>::brodcast_to_mem_recursive(
		T* iterable,
		Shape& host_shape,
		size_t depth, 
		size_t dim_difference, 
		size_t host_index, 
		size_t iterable_index, 
		Shape& shape
	) {

		// ensures recursion stops when tensor tips are reached
		if (depth < shape.dims) {

			// ensures that if iterable tensor has less dims that they are not accessed until later
			if (depth < dim_difference) {

				// recur once for every item in the current shape dimention, selected by depth
				// this runs before the iterable tensor is accessable
				for (size_t shape_index = 0; shape_index < shape.shape[depth]; shape_index++) {
					brodcast_to_mem_recursive(
						iterable,
						host_shape, 
						depth + 1,
						dim_difference,
						host_index * shape.shape[depth] + shape_index,
						0,
						shape
					);
				}
			}
			else {

				// recur once for every item in the current shape dimention, selected by depth
				// this runs only if the iterable tensor can now be accessed
				for (size_t shape_index = 0; shape_index < shape.shape[depth]; shape_index++) {
					brodcast_to_mem_recursive(
						iterable,
						host_shape, 
						depth + 1,
						dim_difference, host_index * shape.shape[depth] + shape_index,
						iterable_index * host_shape[depth - dim_difference] + (host_shape[depth] == 1) ? 0 : shape_index,
						shape
					);
				}
			}

		}
		else {
			// copies the value from the appropriate iterable's index to the brodcast_iterables index
			brodcast_iterable[host_index] = iterable[iterable_index];
		}
	} // recursive brodcast helper function

	template<typename T>
	void Tensor<T>::brodcast_to_mem(Tensor<T>& iterable) {
		brodcast_to_mem_recursive(iterable.iterable, iterable.shape, 0, this->shape.dims - iterable.shape.dims, 0, 0, this->shape);
	}

	template<typename T>
	void Tensor<T>::brodcast_to_mem(Tensor<T>& iterable, Shape& shape) {
		brodcast_to_mem_recursive(iterable.iterable, iterable.shape, 0, shape.dims - iterable.shape.dims, 0, 0, shape);
	}

	// 
	// constructors
	// 
	template<typename T>
	Tensor<T>::Tensor()
		: size(1),
		iterable(new T[1]),
		shape(1) {

		fill(T(0));
	}

	template<typename T>
	Tensor<T>::Tensor(size_t size)
		: size(size),
		iterable(new T[size]),
		shape(size) {

		fill(T(0));
	}

	template<typename T>
	Tensor<T>::Tensor(Shape shape)
		: size(shape.size),
		iterable(new T[shape.size]),
		shape(shape) {

		fill(T(0));
	}

	template<typename T>
	Tensor<T>::Tensor(T* location, Shape shape)
		: size(shape.size),
		iterable(location),
		shape(shape) {

	}

	// 
	// generators
	// 
	template<typename T>
	Tensor<T>* Tensor<T>::clone() {

		Tensor<T>* tensor = new Tensor<T>(this->shape);

		//for (size_t item_index = 0; item_index < this->size; item_index++) {
		//	tensor->iterable[item_index] = this->iterable[item_index];
		//}

		return tensor;
	}

	template<typename T>
	Tensor<T> Tensor<T>::operator[](size_t index) {

		if (index >= this->shape.shape[0] || index < 0) {
			throw "index outside of tensor range, out of bounds exception";
		}

		Shape output_shape;

		size_t new_index;

		if (this->shape.dims > 1) {

			size_t* new_shape(&this->shape.shape[1]);

			output_shape = Shape(new_shape, this->shape.dims - 1);

			new_index = index * output_shape.size;
		}
		else {

			output_shape = Shape(1);

			new_index = index;
		}

		return Tensor<T>(&this->iterable[new_index], output_shape);
	}

	template<typename T>
	Tensor<T> Tensor<T>::transpose_() {

		return Tensor();
	}

	template<typename T>
	Tensor<T> Tensor<T>::transpose_(size_t* target_transpositions) {

		return Tensor();
	}

	// 
	// modifiers 
	// 
	template<typename T>
	void Tensor<T>::fill(T fill_contents) {

		for (size_t index = 0; index < this->size; index++) {
			this->iterable[index] = fill_contents;
		}
	}

	template<typename T>
	void Tensor<T>::clear_iterable() {
		fill(T(0));
	}

	// remove excess 1 dimentions from shape
	template<typename T>
	void Tensor<T>::collapse_ones() {

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

	template<typename T>
	void Tensor<T>::clear_brodcast_iterable() {

		for (size_t brodcast_iterable_index = 0; brodcast_iterable_index < SIZE_MAX; brodcast_iterable_index++) {
			this->brodcast_iterable[brodcast_iterable_index] = T(0);
		}
	}

	template<typename T>
	void Tensor<T>::transpose() {
		
		size_t* reverse = new size_t[this->shape.dims];

		for (size_t index = 0; index < this->shape.dims; index++) {
		
			reverse[this->shape.dims - index - 1] = index;
		}

		transpose(reverse);

		delete[] reverse;
	}

	template<typename T>
	void Tensor<T>::transpose(size_t* target_trasnpositions) {
		
		size_t* indicies;

		size_t* new_indicies = new size_t[this->shape.dims];

		size_t new_index;

		Shape new_shape(this->shape);

		T temp;
		
		reorder(new_shape.shape, this->shape.shape, target_trasnpositions, this->shape.dims);

		T* new_iterable = new T[this->size];

		for (size_t index = 0; index < this->size; index++) {
			
			indicies = index_to_indicies(index, new_shape);

			// reorder indicies
			// likely something broken here

			reorder(new_indicies, indicies, target_trasnpositions, this->shape.dims);
			
			new_index = indicies_to_index(new_indicies, this->shape);

			// swap index and new_index

			new_iterable[index] = this->iterable[new_index];
			

		}
		delete[] this->iterable;

		this->iterable = new_iterable;

		this->shape = new_shape;

	}

	// 
	// getters
	// 
	template<typename T>
	inline bool Tensor<T>::is_brodcastable(Tensor<T>& iterable) {
		return this->shape.is_brodcastable(iterable.shape);
	}

	template<typename T>
	const inline size_t Tensor<T>::get_size() {
		return this->size;
	}

	template<typename T>
	inline Shape Tensor<T>::get_shape() {
		return this->shape;
	}

	template<typename T>
	T* Tensor<T>::get_iterable() {
		return this->iterable;
	}

	template<typename T>
	T* Tensor<T>::get_brodcast_iterable() {
		return this->brodcast_iterable;
	}

	// 
	// explicit Tensor instantiations
	// 
	template class Tensor<scalar_t>;
	template class Tensor<unsigned int>;
	template class Tensor<int>;
	template class Tensor<float>;
	template class Tensor<double>;

} // namespace Tensor
