#include <iostream>

#include <adcgl.h>

#include <tensor/tensor_operators/cpu/elementwise_ops.h>

#include <string>


int main() {

	unsigned int a[5] = { 1, 2, 3, 4, 5 };

	Tensor::Tensor<unsigned int> tensor1(a);

	Tensor::Shape shape2(a);

	Tensor::Tensor<unsigned int> tensor2(shape2);

	std::cout << tensor2[0] << "\n";

	// bugfix this
	Tensor::operate<unsigned int>(tensor2, tensor2, tensor1, Tensor::Operators::add);

	std::cout << "Tensor brodcast_iterable[0]: " << tensor2.get_brodcast_iterable()[0] << "\n";
	std::cout << "t2 contents " << tensor2[0] << "\n";
	std::cout << "t2 contents " << tensor2[2] << "\n";

	std::string in;

	std::cin >> in;

	return 0;
}
