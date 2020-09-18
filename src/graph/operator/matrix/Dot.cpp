//
// Created by Carson Fricke on 9/17/2020 10:38am PST
//


#include "Dot.h"

#include "../../../tensor/operator/matrix/Dot.h"

namespace Graph {

	namespace Operator {

		void Dot::get_operation(Tensor::Tensor<scalar_t>& out) {

			for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

				Tensor::Operator::dot(out, this->inputs[input_index - 1], this->inputs[input_index]);

				//Tensor::operate<float>(out, this->inputs[input_index - 1], this->inputs[input_index], Tensor::Operators::add<float>);
			}
		}

		void Dot::get_jacobian(Tensor::TensorArray<scalar_t>& out) {

		}

		void Dot::init(Tensor::Shape operation_shape) {

			this->operation_shape = operation_shape;

			this->aggregate_grad = Tensor::Tensor<scalar_t>(operation_shape);

			construct_jacobians();
		}

	} // namespace Graph::Operator

} // namespace Graph