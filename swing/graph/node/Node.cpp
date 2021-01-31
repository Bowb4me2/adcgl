//
// Created by Carson Fricke on 6/20/2020 2:08pm PST
//

#include "Node.h"


namespace swing {

	namespace graph {

		namespace node {

			Node::Node(tensor::Tensor<scalar_t>& contents)
				: visited(false),
				contents(contents) {
			}

			void Node::reset_visited() {
				this->visited = false;
			}



			bool Node::is_visited() {
				return this->visited;
			}

			tensor::Tensor<scalar_t>& Node::get_contents() {
				return this->contents;
			}

			NodeArray& Node::get_parents() {
				return this->parents;
			}

			NodeArray& Node::get_children() {
				return this->children;
			}

			void link(Node& parent, Node& child) {

				parent.children.push_back(child);

				child.parents.push_back(parent);
			}

		} // namespace swing::graph::node

	} // namespace swing::graph

} // namespace swing
