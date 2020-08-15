//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Add.h"

#include "../../tensor/operator/cpu/operators.h"

namespace Graph {

	namespace Operator {

		void Add::get_operation(Tensor::Tensor<float>& out) {

			for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

				Tensor::operate<float>(out, this->inputs[input_index - 1], this->inputs[input_index], Tensor::Operators::add<float>);
			}
		}

		void Add::get_jacobian(Tensor::TensorArray<float>& out) {

		}

		void Add::init(Tensor::Shape operation_shape) {

			std::cout << this->inputs.get_size() << " : Add\n";

			this->operation_shape = operation_shape;

			this->aggregate_grad = Tensor::Tensor<float>(operation_shape);

			construct_jacobians();

			//Tensor::Shape shape = Tensor::Shape::concatenate();

			//Tensor::HTensor<float>& jacobian(shape);

			//this->constants.push_back(jacobian);
		}

	} // namespace Graph::Operator

} // namespace Graph