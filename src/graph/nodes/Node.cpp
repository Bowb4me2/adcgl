//
// Created by Carson Fricke on 6/20/2020 2:08pm PST
//

#include "Node.h"

namespace Graph {

	namespace Node {

		void Node::clear_visited() {
			this->visited = false;

			for (size_t parent_index = 0; parent_index < this->parents_size; parent_index++) {
				this->parents[parent_index].clear_visited();
			}
		}

		NodeArray& Node::get_parents() {
			return this->parents;
		}

		NodeArray& Node::get_children() {
			return this->children;
		}

		Tensor::TensorArray<float> Node::get_parents_contents()
		{

			Tensor::TensorArray<float> parents_contents;

			for (size_t parent_index = 0; parent_index < this->parents_size; parent_index++) {
				parents_contents.push_back(this->parents[parent_index].contents);
			}

			return parents_contents;
		}

		Tensor::TensorArray<float> Node::get_children_grads()
		{
			
			Tensor::TensorArray<float> children_contents;

			for (size_t child_index = 0; child_index < this->children_size; child_index++) {
				children_contents.push_back(this->children[child_index].grads);
			}
			
			return children_contents;
		}

	} // namespace Node

} // namespace Graph
