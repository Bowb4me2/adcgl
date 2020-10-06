//
// Created by Carson Fricke on 9/18/2020 11:08am PST
//


#ifndef __GRAPH_OPERATOR_SUM_H__
#define __GRAPH_OPERATOR_SUM_H__

#include "../Operator.h"

namespace Graph {

	namespace Operator {

		class Sum : public Operator {

		public:

			void get_operation(Tensor::Tensor<scalar_t>& out) override;

			void get_jacobian(Tensor::TensorArray<scalar_t>& out) override;

			void init(Tensor::Shape operation_shape) override;

		}; // class Graph::Operator::Sum

	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards