//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Sub.h"

#include "../../../tensor/operator/elementwise/Sub.h"

namespace Graph {

	namespace Operator {

		void Sub::get_operation(Tensor::Tensor<scalar_t>& out) {

			for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

				Tensor::Operator::sub(out, { this->inputs[input_index - 1], this->inputs[input_index] });
			}
		}

		void Sub::populate_local_grads() {

		}

		void Sub::construct_constants() {

		}

	} // namespace Graph::Operator

} // namespace Graph
