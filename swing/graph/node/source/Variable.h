//
// Created by Carson Fricke on 6/21/2020 2:38pm PST
//

#ifndef __GRAPH_NODE_VARIABLE_H__
#define __GRAPH_NODE_VARIABLE_H__

#include "Source.h"


namespace swing {

	namespace graph {

		namespace node {

			class Variable : public Source {

			public:

				Variable(tensor::Tensor<scalar_t>& contents);

			}; // class swing::graph::node::source

		} // namespace swing::graph::node

	} // namespace swing::graph

} // namespace swing

#endif // end guards