//
// Created by Carson Fricke on 9/17/2020 10:38am PST
//

#ifndef __GRAPH_OPERATOR_DOT_H__
#define __GRAPH_OPERATOR_DOT_H__

#include "../MatrixOperator.h"

namespace swing {

	namespace graph {

		namespace oper {

			class Dot : public MatrixOperator {

			protected:

				void populate_local_grads() override;

				void construct_constants() override;

			public:

				void get_operation(tensor::Tensor<scalar_t>& out) override;

			}; // class swing::graph::oper::Dot

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing

#endif // end guards