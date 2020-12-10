//
// Created by Carson Fricke on 10/12/2020 10:35pm PST
//

#include "Operator.h"

#ifndef __GRAPH_OPERATOR_SCALAROPERATOR__
#define __GRAPH_OPERATOR_SCALAROPERATOR__

namespace Graph {

	namespace Operator {

		class ScalarOperator : public Operator {

		protected:

			void construct_local_grads() override;

		public:

			void calc_grad(Tensor::TensorArray<scalar_t>& target) override;

		}; // class Graph::Operator::ScalarOperator


	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards
