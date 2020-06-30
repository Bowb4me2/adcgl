//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Add.h"

#include "../tensor/host/operators/operators.h"

namespace Operator {

	void Add::get_operation(Tensor::Tensor<float>& out) {
		
		for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {
			
			Tensor::operate<float>(out, this->inputs[input_index - 1], this->inputs[input_index], Tensor::Operators::add<float>);
		}
	}

	void Add::get_jacobian(Tensor::TensorArray<float>& out) {
		
	}

} // namespace Operator
