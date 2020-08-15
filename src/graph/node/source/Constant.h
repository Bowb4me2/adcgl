//
// Created by Carson Fricke on 6/21/2020 2:38pm PST
//

#ifndef __GRAPH_NODE_CONSTANT_H__
#define __GRAPH_NODE_CONSTANT_H__

#include "Source.h"

namespace Graph {

	namespace Node {

		class Constant : public Source {

			public:

				Constant(Tensor::Tensor<float>& contents);

		}; // class Source

	} // namespace Graph::Node

} // namespace Graph

#endif // end guards