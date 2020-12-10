#include <iostream>

#include <swing.h>

#include "../swing/tensor/operator/elementwise/Add.h"
#include "../swing/tensor/operator/elementwise/Sub.h"

#include <stdlib.h>



int main() {


	Tensor::Tensor<> target({0, 0, 0});

	Tensor::Tensor<> arg0({ 1 });

	Tensor::Tensor<> arg1({ 3, 2, 1 });

	Tensor::Operator::sub(target, {arg0, arg1});

	std::cout << target;

}