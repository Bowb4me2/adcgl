
#include <iostream>

#include "tensor/Tensor.h"

#include "tensor/Shape.h"

int main() {

	std::cout << "word\n";

	unsigned int a[5] = { 1, 2, 3, 4, 5 };

	Tensor::Shape s(a);

	Tensor::Tensor<int> t1(s);

	Tensor::Tensor<int> t2(a);

	std::cout << s.get_size() << " " << t2.get_size();

	return 0;
}