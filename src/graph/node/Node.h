//
// Created by Carson Fricke on 6/20/2020 2:08pm PST
//


#ifndef __GRAPH_NODE_NODE_H__
#define __GRAPH_NODE_NODE_H__

#include "../../tensor/Tensor.h"
#include "../../tensor/TensorArray.h"
#include "NodeArray.h"

using scalar_t = Tensor::scalar_t;

namespace Graph {

	namespace Node {
	
		class Node {

			protected:

				bool visited;

				Tensor::Tensor<scalar_t>& contents;

				// elements corospond to each parent of this node
				// each element matches the shape of its respective parent

				Tensor::TensorArray<scalar_t> grads;

				NodeArray parents;

				NodeArray children;

			public:

				Node(Tensor::Tensor<scalar_t>& contents);

				virtual void init_input() = 0;

				virtual void init_grad() = 0;

				static void link(Node& parent, Node& child);

				void reset_visited();

				virtual void add_input(Tensor::Tensor<scalar_t>& input) = 0;

				virtual void add_in_grad(Tensor::Tensor<scalar_t>& grad) = 0;

				virtual void add_out_grad(Tensor::Tensor<scalar_t>& grad) = 0;

				virtual void forward() = 0;

				virtual void backward() = 0;

				bool is_visited();

				Tensor::Tensor<scalar_t>& get_contents();

				NodeArray& get_parents();

				NodeArray& get_children();

		}; // class Node

	} // namespace Graph::Node
	
} // namespace Graph

#endif // end guards