//
// Created by Carson Fricke on 9/17/2020 10:08pm PST
//

#ifndef __GRAPH_OPERATOR_MSE_H__
#define __GRAPH_OPERATOR_MSE_H__

#include "../ScalarOperator.h"

namespace swing {

	namespace graph {

		namespace oper {

			// mean squared error
			class MSE : public ScalarOperator {

			protected:

				void populate_local_grads() override;

				void construct_constants() override;

			public:

				void get_operation(tensor::Tensor<scalar_t>& out) override;

			}; // class swing::graph::oper::MSE

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing

#endif // end guards