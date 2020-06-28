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
		
		void Sink::add_input(Tensor::Tensor<float>& input) {
			this->operation.add_input(input);
		}
		
		void Sink::add_grad(Tensor::Tensor<float>& grad) {

		}

		void Sink::forward() {
			
			bool parents_are_visited = true;
			for (size_t parent_index = 0; parent_index < this->parents_size; parent_index++) {
				parents_are_visited = parents_are_visited && this->parents[parent_index].is_visited();
			}

			if (parents_are_visited) {

				this->visited = true;

				// perform operation here

			}

		}

		void Sink::backward() {

			this->visited = true;

			// perform operation here

			for (size_t parent_index = 0; parent_index < this->children_size; parent_index++) {
				this->parents[parent_index].add_grad(this->grads[parent_index]);

				this->parents[parent_index].backward();
			}

		}

	} // namespace Graph::Node

} // namespace Graph