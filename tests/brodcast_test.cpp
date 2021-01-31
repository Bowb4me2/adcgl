#include <iostream>

#include <swing.h>

#include <tensor/operator/elementwise/Add.h>

#include <string>


int main() {

	scalar_t a[5] = { 1, 2, 3, 4, 5 };

	size_t b[5] = { 1, 2, 3, 4, 5 };

	swing::tensor::Tensor<scalar_t> tensor1(a);

	swing::tensor::Shape shape2(b);

	swing::tensor::Tensor<scalar_t> tensor2(shape2);

	std::cout << tensor2 << "\n";

	// bugfix this
	swing::tensor::oper::add(tensor2, { tensor2, tensor1 });

	std::cout << "Tensor brodcast_iterable[0]: " << tensor2.get_brodcast_iterable()[0] << "\n";
	std::cout << "t2  " << tensor2 << "\n";

	std::string in;

	std::cin >> in;

	return 0;
}
