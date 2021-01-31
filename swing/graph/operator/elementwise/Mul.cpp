//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Mul.h"

#include "../../../tensor/operator/elementwise/Mul.h"

namespace swing {

	namespace graph {

		namespace oper {

			void Mul::get_operation(tensor::Tensor<scalar_t>& out) {

				for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

					tensor::oper::mul(out, { this->inputs[input_index - 1], this->inputs[input_index] });
				}
			}

			void Mul::populate_local_grads() {

				this->local_grads[0] = this->inputs[1];

				this->local_grads[1] = this->inputs[0];
			}

			void Mul::construct_constants() {

			}

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing
