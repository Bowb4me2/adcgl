//
// Created by Carson Fricke on 10/12/2020 10:35pm PST
//

#include "Operator.h"

#ifndef __GRAPH_OPERATOR_VECTOROPERATOR__
#define __GRAPH_OPERATOR_VECTOROPERATOR__

namespace Graph {

	namespace Operator {
		
		class VectorOperator : public Operator {

			private:

				Tensor::TensorArray<scalar_t> downsampled_aggregate_grads;

			protected:

				void construct_local_grads() override;

			public:

				void calc_grad(Tensor::TensorArray<scalar_t>& target) override;

		}; // class Graph::Operator::VectorOperator


	} // namespace Graph::Operator

} // namespace Graph

#endif // end guards
