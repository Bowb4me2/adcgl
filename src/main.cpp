
#include <iostream>

#include "tensor/Tensor.h"

#include "tensor/Shape.h"

#include "tensor/TensorArray.h"

int main() {

	std::cout << "word\n";

	unsigned int a[5] = { 1, 2, 3, 4, 5 };

	Tensor::Tensor<unsigned int> tensor(a);

	Tensor::TensorArray<unsigned int> tensor_array;

	tensor_array.push_back(tensor);

	tensor_array.push_back(tensor);

	std::cout << tensor[2] << " " << tensor_array[0][2] << "\n";

	tensor_array[0][2] = 1;

	std::cout << tensor[2] << " " << tensor_array[1][2] << "\n";

	return 0;
}