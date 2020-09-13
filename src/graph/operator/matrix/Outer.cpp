//
// Created by Carson Fricke on 9/12/2020 1:47pm PST
//

#include "Outer.h"

#include "../../../tensor/operator/matrix/Outer.h"

namespace Graph {

	namespace Operator {

		void Outer::get_operation(Tensor::Tensor<scalar_t>& out) {

			for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

				Tensor::Operator::outer(out, this->inputs[input_index - 1], this->inputs[input_index]);

				//Tensor::operate<float>(out, this->inputs[input_index - 1], this->inputs[input_index], Tensor::Operators::add<float>);
			}
		}

		void Outer::get_jacobian(Tensor::TensorArray<scalar_t>& out) {

		}

		void Outer::init(Tensor::Shape operation_shape) {

			std::cout << this->inputs.get_size() << " : Outer\n";

			this->operation_shape = operation_shape;

			this->aggregate_grad = Tensor::Tensor<scalar_t>(operation_shape);

			construct_jacobians();

			//Tensor::Shape shape = Tensor::Shape::concatenate();

			//Tensor::HTensor<float>& jacobian(shape);

			//this->constants.push_back(jacobian);
		}

	} // namespace Graph::Operator

} // namespace Graph