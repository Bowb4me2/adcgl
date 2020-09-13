//
// Created by Carson Fricke on 9/12/2020 1:47pm PST
//

#ifndef __GRAPH_OPERATOR_OUTER_H__
#define __GRAPH_OPERATOR_OUTER_H__

#include "../Operator.h"

namespace Graph {

	namespace Operator {

		class Outer : public Operator {

		public:

			void get_operation(Tensor::Tensor<scalar_t>& out) override;

			void get_jacobian(Tensor::TensorArray<scalar_t>& out) override;

			void init(Tensor::Shape operation_shape) override;

		}; // class Graph::Operator::Outer

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards