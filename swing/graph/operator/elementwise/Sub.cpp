//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Sub.h"

#include "../../../tensor/operator/elementwise/Sub.h"

namespace swing {

	namespace graph {

		namespace oper {

			void Sub::get_operation(tensor::Tensor<scalar_t>& out) {

				for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

					tensor::oper::sub(out, { this->inputs[input_index - 1], this->inputs[input_index] });
				}
			}

			void Sub::populate_local_grads() {

				this->local_grads[0].fill(1);

				this->local_grads[1].fill(-1);
			}

			void Sub::construct_constants() {

			}

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing
