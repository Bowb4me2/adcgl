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

			Tensor::Operator::sub(this->constants[0], this->inputs[0], this->inputs[1]);
			Tensor::Operator::mul(this->constants[0], this->constants[0], this->constants[0]);
			Tensor::Operator::sum(out, this->constants[0]);
		}

		void MSE::get_jacobians(Tensor::TensorArray<scalar_t>& out) {
			
			// jacobian for first input
			Tensor::Operator::sub(out[0], this->inputs[0], this->inputs[1]);
			Tensor::Operator::mul(out[0], out[0], this->constants[1]);

			// jacobian for second input
			Tensor::Operator::sub(out[1], this->inputs[1], this->inputs[0]);
			Tensor::Operator::mul(out[1], out[1], this->constants[1]);

		}
		
		void MSE::init(Tensor::Shape operation_shape) {

			this->operation_shape = operation_shape;

			this->aggregate_grad = Tensor::Tensor<scalar_t>(operation_shape);

			if (this->inputs[0].get_shape().size >= this->inputs[1].get_shape().size) {
				this->constants.push_back(Tensor::Tensor<scalar_t>(this->inputs[0].get_shape()));
			}
			else {
				this->constants.push_back(Tensor::Tensor<scalar_t>(this->inputs[1].get_shape()));
			}
			
			this->constants.push_back(Tensor::Tensor<scalar_t>(1));

			this->constants[1].fill(2);

			construct_jacobians();

			for (size_t jacobian_index = 0; jacobian_index < this->jacobians.get_size(); jacobian_index++) {
				jacobians[jacobian_index].collapse_ones();
			}

		}

		void MSE::aggregate_grads(Tensor::TensorArray<scalar_t>& out) {

			get_jacobians(out);
		}

	} // namespace Graph::Operator

} // namespace Graph