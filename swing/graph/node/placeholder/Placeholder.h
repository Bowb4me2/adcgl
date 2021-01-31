//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#ifndef __GRAPH_NODE_PLACEHOLDER_H__
#define __GRAPH_NODE_PLACEHOLDER_H__

#include "../Node.h"
#include "../../operator/Operator.h"


namespace swing {

	namespace graph {

		namespace node {

			class Placeholder : public Node {

			protected:

				oper::Operator& operation;

			public:

				Placeholder(tensor::Tensor<scalar_t>& contents,oper::Operator& operation);

				void init_input() override;

				void init_grad() override;

				void add_input(tensor::Tensor<scalar_t>& input) override;

				void add_in_grad(tensor::Tensor<scalar_t>& grad) override;

				void add_out_grad(tensor::Tensor<scalar_t>& grad) override;

				void forward() override;

				void backward() override;

			}; // class swing::graph::node::Placeholder

		} // namespace swing::graph::node

	} // namespace swing::graph

} // namespace swing

#endif // end guards