//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#include "Source.h"

namespace Graph {
	
	namespace Node {
		
		Source::Source(Tensor::Tensor<float>& contents) 
			: Node(contents) {

		}

		void Source::init_input() {

			this->visited = true;

			// init operator here

			for (size_t child_index = 0; child_index < this->children.get_size(); child_index++) {
				this->children[child_index].add_input(this->contents);

				this->children[child_index].init_input();
			}

		}

		void Source::init_grad() {

			bool children_are_visited = true;
			for (size_t child_index = 0; child_index < this->parents.get_size(); child_index++) {
				children_are_visited = children_are_visited && this->parents[child_index].is_visited();
			}


			if (children_are_visited) {

				this->visited = true;

				// init operator here

			}

		}

		void Source::add_input(Tensor::Tensor<float>& input) {
			// does nothing lol	
		}

		void Source::add_grad(Tensor::Tensor<float>& grad) {
			this->grads.push_back(grad);
		}
		
		void Source::forward() {
		
			this->visited = true;

			// perform operation here

			for (size_t child_index = 0; child_index < this->children.get_size(); child_index++) {
				this->children[child_index].add_input(this->contents);
				
				this->children[child_index].forward();
			}

		}

		void Source::backward() {

			bool children_are_visited = true;
			for (size_t child_index = 0; child_index < this->parents.get_size(); child_index++) {
				children_are_visited = children_are_visited && this->parents[child_index].is_visited();
			}


			if (children_are_visited) {
				 
				this->visited = true;
				
				// operation here

			}

		}
	
	} // namespace Graph::Node

} // namespace Graph