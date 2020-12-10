//
// Created by Carson Fricke on 9/17/2020 10:38am PST
//

#ifndef __GRAPH_OPERATOR_DOT_H__
#define __GRAPH_OPERATOR_DOT_H__

#include "../MatrixOperator.h"

namespace Graph {

	namespace Operator {

		class Dot : public MatrixOperator {

			protected:

				void populate_local_grads() override;

				void construct_constants() override;

			public:

				void get_operation(Tensor::Tensor<scalar_t>& out) override;

		}; // class Graph::Operator::Dot

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards