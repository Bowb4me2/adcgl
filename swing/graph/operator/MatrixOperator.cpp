//
// Created by Carson Fricke on 10/12/2020 10:35pm PST
//

#include "MatrixOperator.h"
#include "../../tensor/operator/matrix/Dot.h"

namespace Graph {

	namespace Operator {

		void MatrixOperator::construct_local_grads() {

			Tensor::Shape jacobian_shape;

			Tensor::Tensor<scalar_t>* jacobian;

			for (size_t jacobian_index = 0; jacobian_index < this->inputs.get_size(); jacobian_index++) {

				jacobian_shape = Tensor::Shape::concatenate(this->operation_shape, this->inputs[jacobian_index].get_shape());

				jacobian = new Tensor::Tensor<scalar_t>(jacobian_shape);

				this->local_grads.push_back(*jacobian);

			}
		}

		void MatrixOperator::calc_grad(Tensor::TensorArray<scalar_t>& target) {
			
			// multiply via dot product the aggregate gradiant by the jacobian for each input tensor, and return that to the out array
			for (size_t jacobian_index = 0; jacobian_index < this->local_grads.get_size(); jacobian_index++) {
				Tensor::Operator::dot(target[jacobian_index], { this->aggregate_grad, this->local_grads[jacobian_index] });
			}
		}

	} // namespace Graph::Operator

} // namespace Graph
