//
// Created by Carson Fricke on 6/20/2020 2:08pm PST
//


#ifndef __GRAPH_NODE_NODE_H__
#define __GRAPH_NODE_NODE_H__

#include "../../tensor/Tensor.h"
#include "../../tensor/TensorArray.h"
#include "NodeArray.h"


namespace swing {

	namespace graph {

		namespace node {

			class Node {

				protected:

					bool visited;

					tensor::Tensor<scalar_t>& contents;

					// elements corospond to each parent of this node
					// each element matches the shape of its respective parent
					tensor::TensorArray<scalar_t> grads;

					NodeArray parents;

					NodeArray children;

					friend void link(Node& parent, Node& child);

				public:

					Node(tensor::Tensor<scalar_t>& contents);

					virtual void init_input() = 0;

					virtual void init_grad() = 0;

					void reset_visited();

					virtual void add_input(tensor::Tensor<scalar_t>& input) = 0;

					virtual void add_in_grad(tensor::Tensor<scalar_t>& grad) = 0;

					virtual void add_out_grad(tensor::Tensor<scalar_t>& grad) = 0;

					virtual void forward() = 0;

					virtual void backward() = 0;

					bool is_visited();

					tensor::Tensor<scalar_t>& get_contents();

					NodeArray& get_parents();

					NodeArray& get_children();

			}; // class swing::graph::node::Node

			void link(Node& parent, Node& child);

		} // namespace swing::graph::node

	} // namespace swing::graph

} // namespace swing

#endif // end guards