//
// Created by Carson Fricke on 5/17/2020 6:27pm PST
//

#include "Shape.h"

namespace Tensor {

	std::ostream& operator<<(std::ostream& os, const Shape& shape) {
		
		os << "Shape[ ";

		for (size_t dim_index = 0; dim_index < shape.dims - 1; dim_index++) {
			os << shape.shape[dim_index] << ", ";
		}
		
		os << shape.shape[shape.dims - 1] << " ]";

		return os;
	}

	bool Shape::is_equal(Shape shape) {
		
		if (this->dims != shape.dims) {
			return false;
		}

		for (size_t shape_index = 0; shape_index < this->dims; shape_index++) {
			if (this->shape[shape_index] != shape.shape[shape_index]) {
				return false;
			}
		}

		return true;
	}

	size_t& Shape::operator[](int index) {
		
		if (index >= this->size) {
			
			throw "out of bounds";
		}

		return this->shape[index];
	}

	Shape::Shape()
		: size(1),
		shape(new size_t(1)),
		dims(1) {}

	Shape::Shape(Shape& shape) 
		: size(shape.size), 
		shape(new size_t[shape.dims]), 
		dims(shape.dims) {

		for (size_t shape_index = 0; shape_index < this->dims; shape_index++) {
			this->shape[shape_index] = shape.shape[shape_index];
		}
	}

	Shape::Shape(size_t size)
		: size(size),
		shape(new size_t(size)),
		dims(1) {}

	// checks if shape can be brodcast to this
	bool Shape::is_brodcastable(Shape shape) {

		// the difference between the number of dimentions
		long long dims_difference = this->dims - shape.dims;

		// check to make sure that the patern shape has more dimentions than the brodcaster
		if (dims_difference < 0) {
			return false;
		}

		// compare the sizes starting with the trailin dimention,
		// if they are not equal or the neither shape dimention is equal to 1 
		// then the two arrays are unbrodcastable
		for (long long dims_index = shape.dims - 1; dims_index >= 0; dims_index--) {

			if (shape.shape[dims_index] != this->shape[dims_index + dims_difference] &&
				shape.shape[dims_index] != 1) {
				return false;
			}
		}

		return true;
	}

	void Shape::reshape(Shape shape) {

		if (shape.size != this->size) {
			throw "error, sizes dont match";
		}

		this->dims = shape.dims;

		this->shape = shape.shape;

	}

	void Shape::collapse(size_t max_collapseable=1) {


	}

	void Shape::collapse_left() {
		if (this->dims > 2) {

			size_t* shape_array = this->shape;

			delete[] this->shape;

			this->shape = new size_t[this->dims - 1];

			this->dims -= 1;

			this->shape[0] = shape_array[0] * shape_array[1];

			for (size_t shape_index = 1; shape_index < this->dims; shape_index++) {
				this->shape[shape_index] = shape_array[shape_index + 1];
			}
		}
		else {
			throw "Too few dims to collapse";
		}
	}

	void Shape::collapse_right() {
		if (this->dims > 2) {
			
			size_t* shape_array = this->shape;

			delete[] this->shape;

			this->shape = new size_t[this->dims - 1];

			this->dims -= 1;

			this->shape[this->dims - 1] = shape_array[this->dims] * shape_array[this->dims - 1];

			for (size_t shape_index = 0; shape_index < this->dims - 1; shape_index++) {
				this->shape[shape_index] = shape_array[shape_index];
			}
		}
		else {
			throw "Too few dims to collapse";
		}
	}

	Shape Shape::concatenate(Shape arg0, Shape arg1) {
		
		size_t new_shape_dims = arg0.dims + arg1.dims;

		Shape shape(arg0.size * arg1.size);

		shape.dims = new_shape_dims;

		size_t* new_shape = new size_t[new_shape_dims];

		for (size_t new_shape_index = 0; new_shape_index < arg1.dims; new_shape_index++) {
			new_shape[new_shape_index] = arg1.shape[new_shape_index];
		}

		for (size_t new_shape_index = 0; new_shape_index < arg0.dims; new_shape_index++) {
			new_shape[new_shape_index + arg1.dims] = arg0.shape[new_shape_index];
		}

		shape.shape = new_shape;

		return shape;
	}

} // namespace Tensor