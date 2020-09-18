//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Div.h"

#include "../../../tensor/operator/elementwise/Div.h"

namespace Graph {

	namespace Operator {

		void Div::get_operation(Tensor::Tensor<scalar_t>& out) {

			for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

				Tensor::Operator::div(out, this->inputs[input_index - 1], this->inputs[input_index]);
			}
		}

		void Div::get_jacobian(Tensor::TensorArray<scalar_t>& out) {

		}

		void Div::init(Tensor::Shape operation_shape) {

			this->operation_shape = operation_shape;

			this->aggregate_grad = Tensor::Tensor<scalar_t>(operation_shape);

			construct_jacobians();
		}

	} // namespace Graph::Operator

} // namespace Graph
