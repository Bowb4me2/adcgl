//
// Created by Carson Fricke on 9/17/2020 10:08pm PST
//


#include "MSE.h"

#include "../../../tensor/operator/elementwise/Square.h"
#include "../../../tensor/operator/elementwise/Mul.h"
#include "../../../tensor/operator/elementwise/Sub.h"
#include "../../../tensor/operator/elementwise/Sum.h"

namespace swing {

	namespace graph {

		namespace oper {

			void MSE::get_operation(tensor::Tensor<scalar_t>& out) {

				tensor::oper::sub(this->constants[0], { this->inputs[0], this->inputs[1] });
				tensor::oper::square(this->constants[0], { this->constants[0] });
				tensor::oper::sum(out, { this->constants[0] });
			}

			void MSE::populate_local_grads() {

				// local jacobian for first input
				tensor::oper::sub(this->local_grads[0], { this->inputs[0], this->inputs[1] });
				tensor::oper::mul(this->local_grads[0], { this->local_grads[0], this->constants[1] });

				// local jacobian for second input
				tensor::oper::sub(this->local_grads[1], { this->inputs[1], this->inputs[0] });
				tensor::oper::mul(this->local_grads[1], { this->local_grads[1], this->constants[1] });
			}

			void MSE::construct_constants() {

				if (this->inputs[0].get_shape().size >= this->inputs[1].get_shape().size) {
					this->constants.push_back(tensor::Tensor<scalar_t>(this->inputs[0].get_shape()));
				}
				else {
					this->constants.push_back(tensor::Tensor<scalar_t>(this->inputs[1].get_shape()));
				}

				this->constants.push_back(tensor::Tensor<scalar_t>({ 2.0 }));
			}

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing