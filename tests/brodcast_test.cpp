#include <iostream>

#include <adcgl.h>

#include <string>


int main() {

	unsigned int a[5] = { 1, 2, 3, 4, 5 };

	Tensor::Tensor<unsigned int> tensor1(a);

	Tensor::Shape shape2(a);

	Tensor::Tensor<unsigned int> tensor2(shape2);

	std::string in;

	std::cin >> in;

	return 0;
}
