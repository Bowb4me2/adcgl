//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Sub.h"

#include "../tensor/host/operators/operators.h"

namespace Operator {



	void Sub::get_operation(Tensor::Tensor<float>& out) {

		for (size_t input_index = 0; input_index < this->inputs.get_size(); input_index++) {

			Tensor::operate<float>(out, out, this->inputs[input_index], Tensor::Operators::sub<float>);

		}

	}

	void Sub::get_jacobian(Tensor::TensorArray<float>& out) {
	
	}

} // namespace Operator
