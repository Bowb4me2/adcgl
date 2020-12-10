//
// Created by Carson Fricke on 9/12/2020 1:47pm PST
//

#include "Outer.h"

#include "../../../tensor/operator/matrix/Outer.h"

namespace Graph {

	namespace Operator {

		void Outer::get_operation(Tensor::Tensor<scalar_t>& out) {

			for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

				Tensor::Operator::outer(out, { this->inputs[input_index - 1], this->inputs[input_index] });

				//Tensor::operate<float>(out, this->inputs[input_index - 1], this->inputs[input_index], Tensor::Operators::add<float>);
			}
		}

		void Outer::populate_local_grads() {

		}

		void Outer::construct_constants() {

		}

	} // namespace Graph::Operator

} // namespace Graph