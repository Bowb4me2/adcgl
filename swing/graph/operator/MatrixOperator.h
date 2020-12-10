//
// Created by Carson Fricke on 10/12/2020 10:35pm PST
//

#include "Operator.h"

#ifndef __GRAPH_OPERATOR_MATRIXOPERATOR__
#define __GRAPH_OPERATOR_MATRIXOPERATOR__

namespace Graph {

	namespace Operator {

		class MatrixOperator : public Operator {

		protected:

			void construct_local_grads() override;

		public:

			void calc_grad(Tensor::TensorArray<scalar_t>& target) override;

		}; // class Graph::Operator::MatrixOperator


	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards
