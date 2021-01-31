//
// Created by Carson Fricke on 9/12/2020 1:47pm PST
//

#ifndef __GRAPH_OPERATOR_OUTER_H__
#define __GRAPH_OPERATOR_OUTER_H__

#include "../MatrixOperator.h"

namespace swing {

	namespace graph {

		namespace oper {

			class Outer : public MatrixOperator {

			protected:

				void populate_local_grads() override;

				void construct_constants() override;

			public:

				void get_operation(tensor::Tensor<scalar_t>& out) override;

			}; // class swing::graph::oper::Outer

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing

#endif // end guards