//
// Created by Carson Fricke on 6/20/2020 2:08pm PST
//


#ifndef __NODE_H__
#define __NODE_H__

#include "../../tensor/Tensor.h"
#include "../../tensor/TensorArray.h"
#include "NodeArray.h"

namespace Graph {

	namespace Node {
	
		class Node {

			protected:

				bool visited;

				Tensor::Tensor<float>& contents;

				Tensor::TensorArray<float> grads;

				NodeArray parents;

				NodeArray children;

			public:

				Node(Tensor::Tensor<float>& contents);

				virtual void init_input() = 0;

				virtual void init_grad() = 0;

				static void link(Node& parent, Node& child);

				void reset_visited();

				virtual void add_input(Tensor::Tensor<float>& input) = 0;

				virtual void add_grad(Tensor::Tensor<float>& grad) = 0;

				virtual void forward() = 0;

				virtual void backward() = 0;

				bool is_visited();

				Tensor::Tensor<float>& get_contents();

				NodeArray& get_parents();

				NodeArray& get_children();

		}; // class Node

	} // namespace Graph::Node
	
} // namespace Graph

#endif // end guards