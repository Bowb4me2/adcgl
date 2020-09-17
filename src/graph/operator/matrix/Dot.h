//
// Created by Carson Fricke on 9/17/2020 10:38am PST
//

#ifndef __GRAPH_OPERATOR_DOT_H__
#define __GRAPH_OPERATOR_DOT_H__

#include "../Operator.h"

namespace Graph {

	namespace Operator {

		class Dot : public Operator {

		public:

			void get_operation(Tensor::Tensor<scalar_t>& out) override;

			void get_jacobian(Tensor::TensorArray<scalar_t>& out) override;

			void init(Tensor::Shape operation_shape) override;

		}; // class Graph::Operator::Dot

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards