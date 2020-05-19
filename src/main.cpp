
#include <iostream>

#include "tensor/Tensor.h"

#include "tensor/Shape.h"

#include "tensor/TensorArray.h"

int main() {

	std::cout << "word\n";

	unsigned int a[5] = { 1, 2, 3, 4, 5 };

	Tensor::Shape s(a);

	Tensor::Tensor<int> t1(s);

	Tensor::Tensor<int> t2(a);

	Tensor::TensorArray<int> ar1;

	ar1.push_back(t1);

	ar1.push_back(t2);

	std::cout << ar1[1] << " " << &t2;

	return 0;
}