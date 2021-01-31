//
// Created by Carson Fricke on 10/12/2020 10:35pm PST
//

#include "ScalarOperator.h"
#include "../../tensor/operator/elementwise/Mul.h"

namespace swing {

	namespace graph {

		namespace oper {

			void ScalarOperator::construct_local_grads() {

				tensor::Shape grad_shape;

				tensor::Tensor<scalar_t>* grad;

				for (size_t grad_index = 0; grad_index < this->inputs.get_size(); grad_index++) {

					grad_shape = this->inputs[grad_index].get_shape();

					grad = new tensor::Tensor<scalar_t>(grad_shape);

					this->local_grads.push_back(*grad);
				}
			}

			void ScalarOperator::calc_grad(tensor::TensorArray<scalar_t>& target) {

				for (size_t grad_index = 0; grad_index < this->local_grads.get_size(); grad_index++) {
					tensor::oper::mul(target[grad_index], { this->aggregate_grad, this->local_grads[grad_index] });
				}
			}

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing
