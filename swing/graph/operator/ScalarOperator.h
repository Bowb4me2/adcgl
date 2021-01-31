//
// Created by Carson Fricke on 10/12/2020 10:35pm PST
//

#include "Operator.h"

#ifndef __GRAPH_OPERATOR_SCALAROPERATOR__
#define __GRAPH_OPERATOR_SCALAROPERATOR__

namespace swing {

	namespace graph {

		namespace oper {

			class ScalarOperator : public Operator {

			protected:

				void construct_local_grads() override;

			public:

				void calc_grad(tensor::TensorArray<scalar_t>& target) override;

			}; // class swing::graph::oper::ScalarOperator

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing

#endif // end guards
