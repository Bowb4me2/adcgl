//
// Created by Carson Fricke on 6/20/2020 2:08pm PST
//

#include "Node.h"

namespace Graph {

	namespace Node {
		
		Node::Node(Tensor::Tensor<float>& contents)
			: visited(false),
			  contents(contents),
			  parents_size(0), 
			  children_size(0) {
		}

		void Node::link(Node& parent, Node& child) {

			parent.children.push_back(child);

			child.parents.push_back(parent);
		}

		void Node::reset_visited() {
			this->visited = false;

			for (size_t parent_index = 0; parent_index < this->parents_size; parent_index++) {
				this->parents[parent_index].reset_visited();
			}
		}

		void Node::reset_grad() {
			this->grads.clear();

			for (size_t parent_index = 0; parent_index < this->parents_size; parent_index++) {
				this->parents[parent_index].reset_visited();
			}
		}

		void Node::full_reset() {
			this->visited = false;

			this->grads.clear();

			

			for (size_t parent_index = 0; parent_index < this->parents_size; parent_index++) {
				this->parents[parent_index].reset_visited();
			}
		}

		bool Node::is_visited() {
			return this->visited;
		}

		NodeArray& Node::get_parents() {
			return this->parents;
		}

		NodeArray& Node::get_children() {
			return this->children;
		}


	} // namespace Node

} // namespace Graph
