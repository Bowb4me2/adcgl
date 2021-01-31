//
// Created by Carson Fricke on 9/17/2020 10:38am PST
//

#include "Dot.h"

#include "../../../tensor/operator/matrix/Dot.h"

namespace swing {

	namespace graph {

		namespace oper {

			void Dot::get_operation(tensor::Tensor<scalar_t>& out) {

				tensor::oper::dot(out, { this->inputs[0], this->inputs[1] });

				//for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

				//	Tensor::Operator::dot(out, this->inputs[input_index - 1], this->inputs[input_index]);
				//}
			}

			void Dot::populate_local_grads() {

			}

			void Dot::construct_constants() {

			}

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing