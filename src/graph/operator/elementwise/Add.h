//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#ifndef __GRAPH_OPERATOR_ADD_H__
#define __GRAPH_OPERATOR_ADD_H__

#include "../Operator.h"

namespace Graph {

	namespace Operator {

		class Add : public Operator {

		public:

			void get_operation(Tensor::Tensor<scalar_t>& out) override;

			void get_jacobian(Tensor::TensorArray<scalar_t>& out) override;

			void init(Tensor::Shape operation_shape) override;

		}; // class Graph::Operator::Add

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards