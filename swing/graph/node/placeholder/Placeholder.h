//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#ifndef __GRAPH_NODE_PLACEHOLDER_H__
#define __GRAPH_NODE_PLACEHOLDER_H__

#include "../Node.h"
#include "../../operator/Operator.h"

using scalar_t = Tensor::scalar_t;

namespace Graph {

	namespace Node {

		class Placeholder : public Node {

			protected:

				Operator::Operator& operation;

			public:

				Placeholder(Tensor::Tensor<scalar_t>& contents, Operator::Operator& operation);

				void init_input() override;

				void init_grad() override;

				void add_input(Tensor::Tensor<scalar_t>& input) override;

				void add_in_grad(Tensor::Tensor<scalar_t>& grad) override;

				void add_out_grad(Tensor::Tensor<scalar_t>& grad) override;

				void forward() override;

				void backward() override;

		}; // class Placeholder

	} // namespace Graph::Node

} // namespace Graph

#endif // end guards