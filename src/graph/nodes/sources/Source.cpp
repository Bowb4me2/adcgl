//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#include "Source.h"

namespace Graph {
	
	namespace Node {
	
		Tensor::Tensor<float> Source::forward() {
		
			this->visited = true;

			// perform operation here

			for (size_t child_index = 0; child_index < this->children_size; child_index++) {
				this->children[child_index].forward();
			}

		}

		Tensor::Tensor<float> Source::backward() {

			bool children_are_visited = true;
			for (size_t child_index = 0; child_index < this->parents_size; child_index++) {
				children_are_visited = children_are_visisted && this->parents[child_index].visited;
			}


			if (children_are_visited) {
				 
				this->visited = true;
				
				// operation here

			}

		}
	
	} // namespace Graph::Node

} // namespace Graph