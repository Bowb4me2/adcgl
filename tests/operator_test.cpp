#include <iostream>

#include <swing.h>

#include "../swing/tensor/operator/elementwise/Add.h"
#include "../swing/tensor/operator/elementwise/Sub.h"

#include "../swing/graph/operator/loss/MSE.h"
#include "../swing/graph/operator/elementwise/Add.h"
#include "../swing/graph/operator/elementwise/Mul.h"
#include "../swing/graph/operator/elementwise/Div.h"

#include "../swing/tensor/TensorStorage.h"

#include <stdlib.h>



int main() {

	swing::tensor::TensorStorage test_storage({ 2, 3, 4 });

	auto x = test_storage.as_strided({ 4, 3, 2 }, {1, 4, 12});

	

	x.enforce_internal_contiguity();


	swing::tensor::Tensor<> target_tensor({ 1, 1, 1 });

	swing::tensor::Tensor<> variable_tensor1({ 1, 1, 1 });

	swing::tensor::Tensor<> variable_tensor2({ 2, 2, 2 });

	swing::tensor::Tensor<> placeholder_tensor({ 0, 0, 0 });

	swing::tensor::Tensor<> error_tensor({0});

	swing::graph::node::Constant target(target_tensor);

	swing::graph::node::Variable variable1(variable_tensor1);

	swing::graph::node::Variable variable2(variable_tensor2);

	swing::graph::node::Placeholder placeholder(placeholder_tensor, swing::graph::oper::Div());

	swing::graph::node::Sink error(error_tensor, swing::graph::oper::MSE());

	swing::graph::GraphBuilder model_builder;

	model_builder.add_node(target);

	model_builder.add_node(variable1);

	model_builder.add_node(variable2);

	model_builder.add_node(placeholder);

	model_builder.add_node(error);

	swing::graph::node::link(target, error);

	swing::graph::node::link(placeholder, error);

	swing::graph::node::link(variable1, placeholder);

	swing::graph::node::link(variable2, placeholder);

	swing::graph::DCGraph model(model_builder);

	model.forward();

	std::cout << "error " << error_tensor << "\n";

	std::cout << "target " << target_tensor << "\n";

	std::cout << "calculated value "<< placeholder_tensor << "\n";

	model.backward();

}