//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Add.h"

#include "../../../tensor/operator/elementwise/Add.h"

namespace Graph {

	namespace Operator {

		void Add::get_operation(Tensor::Tensor<scalar_t>& out) {

			for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

				Tensor::Operator::add(out, { this->inputs[input_index - 1], this->inputs[input_index] });
			}
		}

		void Add::populate_local_grads() {

		}

		void Add::construct_constants() {

			for (size_t index = 0; index < this->local_grads.get_size(); index++) {
				this->local_grads[index].fill(1);
			}
		}

	} // namespace Graph::Operator

} // namespace Graph