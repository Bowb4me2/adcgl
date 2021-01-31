//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#include "Sink.h"


namespace swing {

	namespace graph {

		namespace node {

			Sink::Sink(tensor::Tensor<scalar_t>& contents, oper::Operator& operation)
				: Node(contents),
				operation(operation) {
			}

			void Sink::init_input() {

				bool parents_are_visited = true;
				for (size_t parent_index = 0; parent_index < this->parents.get_size(); parent_index++) {
					parents_are_visited = parents_are_visited && this->parents[parent_index].is_visited();
				}

				if (parents_are_visited) {

					this->visited = true;

					// init operator here
					// make it add an 1 grad so that things can be backpropped from sinks

					tensor::Tensor<> sink_grad_1({ 1 });

					this->operation.add_grad(sink_grad_1);

					this->operation.init(this->contents.get_shape());
				}
			}

			void Sink::init_grad() {

				this->visited = true;

				// init operator here

				for (size_t parent_index = 0; parent_index < this->parents.get_size(); parent_index++) {

					this->parents[parent_index].add_out_grad(this->grads[parent_index]);

					this->parents[parent_index].init_grad();
				}

			}

			void Sink::add_input(tensor::Tensor<scalar_t>& input) {
				this->operation.add_input(input);
			}

			void Sink::add_in_grad(tensor::Tensor<scalar_t>& grad) {
				this->grads.push_back(grad);
			}

			void Sink::add_out_grad(tensor::Tensor<scalar_t>& grad) {
				// shouldent ever run because nothing will backprop grads here
			}

			void Sink::forward() {

				bool parents_are_visited = true;
				for (size_t parent_index = 0; parent_index < this->parents.get_size(); parent_index++) {
					parents_are_visited = parents_are_visited && this->parents[parent_index].is_visited();
				}

				if (parents_are_visited) {

					this->visited = true;

					// perform operation here
					this->operation.get_operation(this->contents);

				}

			}

			void Sink::backward() {

				this->visited = true;

				// make sure to fill grads appropriatly
				// something like this->operation.get_grads(this->grads)
				this->operation.differentiate(this->grads);

				for (size_t parent_index = 0; parent_index < this->parents.get_size(); parent_index++) {
					this->parents[parent_index].backward();
				}
			}

		} // namespace swing::graph::node

	} // namespace swing::graph

} // namespace swing