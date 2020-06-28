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

				size_t parents_size;

				size_t children_size;

				NodeArray parents;

				NodeArray children;

			public:

				Node(Tensor::Tensor<float>& contents);

				static void link(Node& parent, Node& child);
				
				void reset_visited();

				void reset_grad();

				void full_reset();

				virtual void add_input(Tensor::Tensor<float>& input) = 0;

				virtual void add_grad(Tensor::Tensor<float>& grad) = 0;

				virtual void forward() = 0;

				virtual void backward() = 0;

				bool is_visited();

				NodeArray& get_parents();

				NodeArray& get_children();

		}; // class Node

	} // namespace Graph::Node
	
} // namespace Graph

#endif // end guards