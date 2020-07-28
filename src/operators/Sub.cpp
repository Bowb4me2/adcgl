//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Sub.h"

#include "../tensor/tensor_operators/cpu/operators.h"

namespace Operator {

	void Sub::get_operation(Tensor::Tensor<float>& out) {

		for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

			Tensor::operate<float>(out, this->inputs[input_index - 1], this->inputs[input_index], Tensor::Operators::sub<float>);
		}
	}

	void Sub::get_jacobian(Tensor::TensorArray<float>& out) {
	
	}

	void Sub::init(Tensor::Shape operation_shape) {
		
		std::cout << this->inputs.get_size() << " : Sub\n";

		this->operation_shape = operation_shape;
		
		construct_jacobians();
	}

} // namespace Operator
