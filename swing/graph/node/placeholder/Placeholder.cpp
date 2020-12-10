//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#include "Placeholder.h"


namespace Graph {

	namespace Node {

		Placeholder::Placeholder(Tensor::Tensor<scalar_t>& contents, Operator::Operator& operation) 
			: Node(contents), 
			  operation(operation) {
			
		}

		
		void Placeholder::init_input() {

			// verifies that all parent nodes have had values propegated into them.
			bool parents_are_visited = true;
			for (size_t parent_index = 0; parent_index < this->parents.get_size(); parent_index++) {
				parents_are_visited = parents_are_visited && this->parents[parent_index].is_visited();
			}

			if (parents_are_visited) {

				this->visited = true;

				// init operator here
				this->operation.init(this->contents.get_shape());

				for (size_t child_index = 0; child_index < this->children.get_size(); child_index++) {
					
					this->children[child_index].add_input(this->contents);

					this->children[child_index].add_in_grad(*this->contents.clone());

					this->children[child_index].init_input();
				}
			}
		}

		void Placeholder::init_grad() {

			// verifies that all child nodes have had values propegated into them.
			bool children_are_visited = true;
			for (size_t child_index = 0; child_index < this->children.get_size(); child_index++) {
				children_are_visited = children_are_visited && this->children[child_index].is_visited();
			}

			if (children_are_visited) {

				this->visited = true;

				// init operator here

				for (size_t parent_index = 0; parent_index < this->parents.get_size(); parent_index++) {
					
					this->parents[parent_index].add_out_grad(this->grads[parent_index]);
					
					this->parents[parent_index].init_grad();
				}
			}
		}
		
		void Placeholder::add_input(Tensor::Tensor<scalar_t>& input) {
			this->operation.add_input(input);
		}

		void Placeholder::add_in_grad(Tensor::Tensor<scalar_t>& grad) {
			this->grads.push_back(grad);
		}

		void Placeholder::add_out_grad(Tensor::Tensor<scalar_t>& grad) {
			this->operation.add_grad(grad);

		}
		
		void Placeholder::forward() {
			
			// verifies that all parent nodes have had values propegated into them.
			bool parents_are_visited = true;
			for (size_t parent_index = 0; parent_index < this->parents.get_size(); parent_index++) {
				parents_are_visited = parents_are_visited && this->parents[parent_index].is_visited();
			}

			if (parents_are_visited) {
				
				this->visited = true;

				// perform operation here
				this->operation.get_operation(this->contents);

				for (size_t child_index = 0; child_index < this->children.get_size(); child_index++) {

					this->children[child_index].forward();
				}
			}
		}

		void Placeholder::backward() {			

			// verifies that all child nodes have had values propegated into them.
			bool children_are_visited = true;
			for (size_t child_index = 0; child_index < this->children.get_size(); child_index++) {
				children_are_visited = children_are_visited && this->children[child_index].is_visited();
			}

			if (children_are_visited) {

				

				this->visited = true;

				// perform operation here
				
				this->operation.differentiate(this->grads);



				for (size_t parent_index = 0; parent_index < this->parents.get_size(); parent_index++) {
					
					this->parents[parent_index].backward();
				}
			}
		}
	
	} // namespace Graph::Node

} // namespace Graph