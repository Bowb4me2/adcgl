//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#ifndef __GRAPH_NODE_SOURCE_H__
#define __GRAPH_NODE_SOURCE_H__

#include "..\Node.h"


namespace swing {

	namespace graph {

		namespace node {

			class Source : public Node {

			protected:

			public:

				Source(tensor::Tensor<scalar_t>& contents);

				void init_input() override;

				void init_grad() override;

				void add_input(tensor::Tensor<scalar_t>& input) override;

				void add_in_grad(tensor::Tensor<scalar_t>& grad) override;

				void add_out_grad(tensor::Tensor<scalar_t>& grad) override;

				void forward() override;

				void backward() override;

			}; // class swing::graph::node::Source

		} // namespace swing::graph::node

	} // namespace swing::graph

} // namespace swing

#endif // end guards