//
// Created by Carson Fricke on 9/17/2020 10:08pm PST
//

#ifndef __GRAPH_OPERATOR_MSE_H__
#define __GRAPH_OPERATOR_MSE_H__

#include "../ScalarOperator.h"

namespace Graph {

	namespace Operator {

		// mean squared error
		class MSE : public ScalarOperator {

			protected:

				void populate_local_grads() override;

				void construct_constants() override;

			public:

				void get_operation(Tensor::Tensor<scalar_t>& out) override;

		}; // class Graph::Operator::MSE

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards