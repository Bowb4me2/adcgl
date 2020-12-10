//
// Created by Carson Fricke on 9/17/2020 10:08pm PST
//


#include "MSE.h"

#include "../../../tensor/operator/elementwise/Mul.h"
#include "../../../tensor/operator/elementwise/Sub.h"
#include "../../../tensor/operator/elementwise/Sum.h"

namespace Graph {

	namespace Operator {

		void MSE::get_operation(Tensor::Tensor<scalar_t>& out) {

			Tensor::Operator::sub(this->constants[0], { this->inputs[0], this->inputs[1] });
			Tensor::Operator::mul(this->constants[0], { this->constants[0], this->constants[0] });
			Tensor::Operator::sum(out, { this->constants[0] });
		}

		void MSE::populate_local_grads() {
			
			// jacobian for first input
			Tensor::Operator::sub(this->local_grads[0], { this->inputs[0], this->inputs[1] });
			Tensor::Operator::mul(this->local_grads[0], { this->local_grads[0], this->constants[1] });

			// jacobian for second input
			Tensor::Operator::sub(this->local_grads[1], { this->inputs[1], this->inputs[0] });
			Tensor::Operator::mul(this->local_grads[1], { this->local_grads[1], this->constants[1] });
		}
		
		void MSE::construct_constants() {

			if (this->inputs[0].get_shape().size >= this->inputs[1].get_shape().size) {
				this->constants.push_back(Tensor::Tensor<scalar_t>(this->inputs[0].get_shape()));
			}
			else {
				this->constants.push_back(Tensor::Tensor<scalar_t>(this->inputs[1].get_shape()));
			}
			
			this->constants.push_back(Tensor::Tensor<scalar_t>({2.0}));
		}

	} // namespace Graph::Operator

} // namespace Graph