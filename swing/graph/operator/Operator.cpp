//
// Created by Carson Fricke on 6/23/2020 2:43pm PST
//

#include "Operator.h"
#include "../../tensor/operator/elementwise/Add.h"
#include "../../tensor/operator/matrix/Dot.h"

namespace swing {

	namespace graph {

		namespace oper {

			/*void Operator::construct_jacobians() {

				Tensor::Shape jacobian_shape;

				Tensor::Tensor<scalar_t>* jacobian;

				for (size_t jacobian_index = 0; jacobian_index < this->inputs.get_size(); jacobian_index++) {

					jacobian_shape = Tensor::Shape::concatenate(this->operation_shape, this->inputs[jacobian_index].get_shape());

					jacobian = new Tensor::Tensor<scalar_t>(jacobian_shape);

					this->local_grads.push_back(*jacobian);

				}

			}*/

			void Operator::init(tensor::Shape operation_shape) {

				this->operation_shape = operation_shape;

				this->aggregate_grad = tensor::Tensor<scalar_t>(operation_shape);

				construct_local_grads();

				construct_constants();

			}

			void Operator::aggregate_grads() {

				for (size_t grad_index = 0; grad_index < this->grads.get_size(); grad_index++) {
					tensor::oper::add(this->aggregate_grad, { this->aggregate_grad, this->grads[grad_index] });
				}
			}

			void Operator::differentiate(tensor::TensorArray<scalar_t>& target) {

				// right here, sinks dont have grads, make sinks populate their grads with a one
				aggregate_grads();

				populate_local_grads();

				calc_grad(target);
			}

			void Operator::add_input(tensor::Tensor<scalar_t>& input) {
				this->inputs.push_back(input);
			}

			void Operator::add_grad(tensor::Tensor<scalar_t>& grad) {
				this->grads.push_back(grad);
			}

			void Operator::clear() {

				this->inputs.clear();

				this->grads.clear();
			}

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing
