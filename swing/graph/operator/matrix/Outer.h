//
// Created by Carson Fricke on 9/12/2020 1:47pm PST
//

#ifndef __GRAPH_OPERATOR_OUTER_H__
#define __GRAPH_OPERATOR_OUTER_H__

#include "../MatrixOperator.h"

namespace Graph {

	namespace Operator {

		class Outer : public MatrixOperator {

			protected:

				void populate_local_grads() override;

				void construct_constants() override;

			public:

				void get_operation(Tensor::Tensor<scalar_t>& out) override;

		}; // class Graph::Operator::Outer

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards