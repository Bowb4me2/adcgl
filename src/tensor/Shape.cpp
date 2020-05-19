//
// Created by Carson Fricke on 5/17/2020 6:27pm PST
//

#include "Shape.h"

Tensor::Shape::Shape()
	: size(1),
	  shape(new unsigned int(1)),
	  dims(1) {}

Tensor::Shape::Shape(size_t size)
	: size(size),
	  shape(new unsigned int(size)),
	  dims(1) {}

size_t Tensor::Shape::get_size()
{
	return this->size;
}

unsigned int* Tensor::Shape::get_shape()
{
	return this->shape;
}

size_t Tensor::Shape::get_dims()
{
	return this->dims;
}
