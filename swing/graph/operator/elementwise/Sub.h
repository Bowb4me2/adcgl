//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#ifndef __GRAPH_OPERATOR_SUB_H__
#define __GRAPH_OPERATOR_SUB_H__

#include "../Operator.h"

namespace Graph {

	namespace Operator {

		class Sub : public Operator {

		public:

			void get_operation(Tensor::Tensor<scalar_t>& out) override;

			void get_jacobians(Tensor::TensorArray<scalar_t>& out) override;

			void init(Tensor::Shape operation_shape) override;

		}; // class Graph::Operator::Sub

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards