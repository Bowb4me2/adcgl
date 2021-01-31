//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#ifndef __GRAPH_OPERATOR_ADD_H__
#define __GRAPH_OPERATOR_ADD_H__

#include "../VectorOperator.h"

namespace swing {

	namespace graph {

		namespace oper {

			class Add : public VectorOperator {

			protected:

				void populate_local_grads() override;

				void construct_constants() override;

			public:

				void get_operation(tensor::Tensor<scalar_t>& out) override;

			}; // class wsing::graph::oper::Add

		} // namespace wsing::graph::oper

	} // namespace wsing::graph

} // namespace swing

#endif // end guards