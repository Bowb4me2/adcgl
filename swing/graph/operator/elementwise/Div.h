//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#ifndef __GRAPH_OPERATOR_DIV_H__
#define __GRAPH_OPERATOR_DIV_H__

#include "../VectorOperator.h"

namespace Graph {

	namespace Operator {

		class Div : public VectorOperator {

			protected:

				void populate_local_grads() override;

				void construct_constants() override;

			public:

				void get_operation(Tensor::Tensor<scalar_t>& out) override;

		}; // class Graph::Operator::Div

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards