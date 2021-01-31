//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Div.h"

#include "../../../tensor/operator/elementwise/Div.h"
#include "../../../tensor/operator/elementwise/Square.h"

namespace swing {

	namespace graph {

		namespace oper {

			void Div::get_operation(tensor::Tensor<scalar_t>& out) {

				for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

					tensor::oper::div(
						out,
						{ this->inputs[input_index - 1], this->inputs[input_index] }
					);
				}
			}

			void Div::populate_local_grads() {

				tensor::oper::div(
					this->local_grads[0],
					{ this->constants[0], this->inputs[1] }
				);

				tensor::oper::square(
					this->local_grads[1],
					{ this->inputs[1] }
				);

				tensor::oper::div(
					this->local_grads[1],
					{ this->inputs[0], this->local_grads[1] }
				);

				tensor::oper::div(
					this->local_grads[1],
					{ this->local_grads[1], this->constants[1] }
				);

			}

			void Div::construct_constants() {

				tensor::Tensor<> constant_1({ 1 });

				tensor::Tensor<> constant_minus_1({ -1 });

				this->constants.push_back(constant_1);

				this->constants.push_back(constant_minus_1);
			}

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing
