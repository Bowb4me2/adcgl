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

				Tensor::Tensor<float>& grads;

				size_t parents_size;

				size_t children_size;

				NodeArray& parents;

				NodeArray& children;

			public:

				void clear_visited();

				virtual Tensor::Tensor<float> forward() = 0;

				virtual Tensor::Tensor<float> backward() = 0;

				NodeArray& get_parents();

				NodeArray& get_children();

				Tensor::TensorArray<float> get_parents_contents();

				Tensor::TensorArray<float> get_children_grads();

		}; // class Node

	} // namespace Graph::Node
	
} // namespace Graph

#endif // end guards