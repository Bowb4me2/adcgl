//
// Created by Carson Fricke on 6/21/2020 2:38pm PST
//

#ifndef __GRAPH_NODE_CONSTANT_H__
#define __GRAPH_NODE_CONSTANT_H__

#include "Source.h"


namespace swing {

	namespace graph {

		namespace node {

			class Constant : public Source {

			public:

				Constant(tensor::Tensor<scalar_t>& contents);

			}; // class swing::graph::node::Constant

		} // namespace swing::graph::node

	} // namespace swing::graph

} // namespace swing

#endif // end guards