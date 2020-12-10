//
// Created by Carson Fricke on 10/12/2020 10:35pm PST
//

#include "VectorOperator.h"
#include "../../tensor/operator/elementwise/Mul.h"

namespace Graph {

	namespace Operator {
		
		void VectorOperator::construct_local_grads() {

			Tensor::Shape grad_shape;

			Tensor::Tensor<scalar_t>* grad;

			Tensor::Tensor<scalar_t>* downsampled_aggregate_grad;

			for (size_t grad_index = 0; grad_index < this->inputs.get_size(); grad_index++) {

				grad_shape = this->inputs[grad_index].get_shape();

				grad = new Tensor::Tensor<scalar_t>(grad_shape);

				this->local_grads.push_back(*grad);

				if (this->operation_shape.is_equal(grad_shape)) {
					this->downsampled_aggregate_grads.push_back(this->aggregate_grad);
				}
				else {

					downsampled_aggregate_grad = new Tensor::Tensor<scalar_t>(grad_shape);

					this->downsampled_aggregate_grads.push_back(*downsampled_aggregate_grad);
				}

			}
		}

		void VectorOperator::calc_grad(Tensor::TensorArray<scalar_t>& target) {
			
			for (size_t grad_index = 0; grad_index < this->local_grads.get_size(); grad_index++) {
				
				// downsample sum operation here
				if (this->operation_shape.is_equal(this->local_grads[grad_index].get_shape())) {
					// downsample sum 
				}
				
				Tensor::Operator::mul(
					target[grad_index], 
					{ this->downsampled_aggregate_grads[grad_index], this->local_grads[grad_index] }
				);
			}
		}

	} // namespace Graph::Operator

} // namespace Graph
