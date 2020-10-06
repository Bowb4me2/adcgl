//
// Created by Carson Fricke on 6/21/2020 2:38pm PST
//

#ifndef __GRAPH_NODE_CONSTANT_H__
#define __GRAPH_NODE_CONSTANT_H__

#include "Source.h"

using scalar_t = Tensor::scalar_t;

namespace Graph {

	namespace Node {

		class Constant : public Source {

			public:

				Constant(Tensor::Tensor<scalar_t>& contents);

		}; // class Source

	} // namespace Graph::Node

} // namespace Graph

#endif // end guards