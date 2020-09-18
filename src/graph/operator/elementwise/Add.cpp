//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Add.h"

#include "../../../tensor/operator/elementwise/Add.h"

namespace Graph {

	namespace Operator {

		void Add::get_operation(Tensor::Tensor<scalar_t>& out) {

			for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

				Tensor::Operator::add(out, this->inputs[input_index - 1], this->inputs[input_index]);
			}
		}

		void Add::get_jacobian(Tensor::TensorArray<scalar_t>& out) {

		}

		void Add::init(Tensor::Shape operation_shape) {

			this->operation_shape = operation_shape;

			this->aggregate_grad = Tensor::Tensor<scalar_t>(operation_shape);

			construct_jacobians();

			//Tensor::Shape shape = Tensor::Shape::concatenate();

			//Tensor::HTensor<float>& jacobian(shape);

			//this->constants.push_back(jacobian);
		}

	} // namespace Graph::Operator

} // namespace Graph