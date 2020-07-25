//
// Created by Carson Fricke on 5/17/2020 6:27pm PST
//

#include "Shape.h"

namespace Tensor {

	unsigned int& Shape::operator[](int index) {
		if (index >= this->size) {
			throw "out of bounds";
		}
		return this->shape[index];
	}

	Shape::Shape()
		: size(1),
		shape(new unsigned int(1)),
		dims(1) {}

	Shape::Shape(size_t size)
		: size(size),
		shape(new unsigned int(size)),
		dims(1) {}

	bool Shape::is_brodcastable(Shape shape) {

		// the difference between the number of dimentions
		auto dims_difference = this->dims - shape.get_dims();

		// check to make sure that the patern shape has more dimentions than the brodcaster
		if (dims_difference < 0) {
			return false;
		}

		// assumes the host of the method has more dims.
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

	Shape Shape::concatenate(Shape arg0, Shape arg1) {
		
		size_t new_shape_dims = arg0.dims + arg1.dims;

		Shape shape(arg0.size * arg1.size);

		shape.dims = new_shape_dims;

		unsigned int* new_shape = new unsigned int[new_shape_dims];

		for (size_t new_shape_index = 0; new_shape_index < arg0.dims; new_shape_index++) {
			new_shape[new_shape_index] = arg0.shape[new_shape_index];
		}

		for (size_t new_shape_index = 0; new_shape_index < arg1.dims; new_shape_index++) {
			new_shape[new_shape_index + arg0.dims] = arg1.shape[new_shape_index];
		}

		shape.shape = new_shape;

		return shape;
	}

	size_t Shape::get_size() {
		return this->size;
	}

	unsigned int* Shape::get_shape() {
		return this->shape;
	}

	size_t Shape::get_dims() {
		return this->dims;
	}

} // namespace Tensor