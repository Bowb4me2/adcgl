//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#include "Sink.h"


namespace Graph {

	namespace Node {
		
		Sink::Sink(Tensor::Tensor<float>& contents, Operator::Operator& operation)
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
				this->operation.init(this->contents.get_shape());
			}
		}

		void Sink::init_grad() {

			this->visited = true;

			// init operator here

			for (size_t parent_index = 0; parent_index < this->children.get_size(); parent_index++) {
				this->parents[parent_index].add_out_grad(this->grads[parent_index]);

				this->parents[parent_index].init_grad();
			}

		}
		
		void Sink::add_input(Tensor::Tensor<float>& input) {
			this->operation.add_input(input);
		}
		
		void Sink::add_in_grad(Tensor::Tensor<float>& grad) {
			this->grads.push_back(grad);
		}

		void Sink::add_out_grad(Tensor::Tensor<float>& grad) {
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

			// perform operation here

			for (size_t parent_index = 0; parent_index < this->children.get_size(); parent_index++) {

				this->parents[parent_index].backward();
			}

		}

	} // namespace Graph::Node

} // namespace Graph