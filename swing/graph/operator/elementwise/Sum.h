//
// Created by Carson Fricke on 9/18/2020 11:08am PST
//


#ifndef __GRAPH_OPERATOR_SUM_H__
#define __GRAPH_OPERATOR_SUM_H__

#include "../ScalarOperator.h"

namespace Graph {

	namespace Operator {

		class Sum : public ScalarOperator {

			protected:

				void populate_local_grads() override;

				void construct_constants() override;

			public:

				void get_operation(Tensor::Tensor<scalar_t>& out) override;

		}; // class Graph::Operator::Sum

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards