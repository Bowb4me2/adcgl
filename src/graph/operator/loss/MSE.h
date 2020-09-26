//
// Created by Carson Fricke on 9/17/2020 10:08pm PST
//

#ifndef __GRAPH_OPERATOR_MSE_H__
#define __GRAPH_OPERATOR_MSE_H__

#include "../Operator.h"

namespace Graph {

	namespace Operator {

		// mean squared error
		class MSE : public Operator {

		public:

			void get_operation(Tensor::Tensor<scalar_t>& out) override;

			void get_jacobians(Tensor::TensorArray<scalar_t>& out) override;

			void init(Tensor::Shape operation_shape) override;

			void aggregate_grads(Tensor::TensorArray<scalar_t>& out) override;

		}; // class Graph::Operator::MSE

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards