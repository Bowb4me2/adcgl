//
// Created by Carson Fricke on 6/23/2020 2:43pm PST
//

#include "Operator.h"



namespace Operator {
					
	void Operator::add_input(Tensor::Tensor<float>& input) {
		this->inputs.push_back(input);
	}

	void Operator::add_grad(Tensor::Tensor<float>& grad) {
		this->grads.push_back(grad);
	}

	void Operator::clear() {
		this->inputs.clear();

		this->grads.clear();
	}

} // namespace Operator
