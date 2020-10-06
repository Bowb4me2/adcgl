//
// Created by Carson Fricke on 6/21/2020 2:38pm PST
//

#ifndef __GRAPH_NODE_VARIABLE_H__
#define __GRAPH_NODE_VARIABLE_H__

#include "Source.h"

using scalar_t = Tensor::scalar_t;

namespace Graph {

	namespace Node {

		class Variable : public Source {

			public:

				Variable(Tensor::Tensor<scalar_t>& contents);

		}; // class Source

	} // namespace Graph::Node

} // namespace Graph

#endif // end guards