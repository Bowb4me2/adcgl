//
// Created by Carson Fricke on 6/23/2020 2:43pm PST
//

#include "Operator.h"


namespace Operator {
	
	void Operator::construct_jacobians() {
		
		Tensor::Shape jacobian_shape;

		Tensor::Tensor<float>* jacobian;

		for (size_t jacobian_index = 0; jacobian_index < this->inputs.get_size(); jacobian_index++) {
			
			jacobian_shape = Tensor::Shape::concatenate(this->operation_shape, this->inputs[jacobian_index].get_shape());
			
			jacobian = new Tensor::Tensor<float>(jacobian_shape);

			this->jacobians.push_back(*jacobian);
		}

		// for (size_t i = 0; i < this->jacobians.get_size(); i++) {
		//	
		//	std::cout << this->jacobians[i].get_shape()[0] << ", " << this->jacobians[i].get_shape()[1] << " \n";
		//}

	}

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
