//
// Created by Carson Fricke on 6/23/2020 2:43pm PST
//

#ifndef __GRAPH_OPERATOR_OPERATOR_H__
#define __GRAPH_OPERATOR_OPERATOR_H__

#include "../../tensor/Tensor.h"
#include "../../tensor/TensorArray.h"
#include <iostream>


namespace swing {

	namespace graph {

		namespace oper {

			class Operator {

			protected:

				tensor::Shape operation_shape;

				tensor::TensorArray<scalar_t> inputs;


				// the grad of each child with respect to this op.
				tensor::TensorArray<scalar_t> grads;

				tensor::Tensor<scalar_t> aggregate_grad;

				tensor::TensorArray<scalar_t> constants;

				tensor::TensorArray<scalar_t> local_grads;

				virtual void construct_local_grads() = 0;

				virtual void construct_constants() = 0;

				virtual void populate_local_grads() = 0;

			public:

				virtual void get_operation(tensor::Tensor<scalar_t>& target) = 0;

				void init(tensor::Shape operation_shape);

				void aggregate_grads();

				void differentiate(tensor::TensorArray<scalar_t>& target);

				virtual void calc_grad(tensor::TensorArray<scalar_t>& target) = 0;

				void add_input(tensor::Tensor<scalar_t>& input);

				void add_grad(tensor::Tensor<scalar_t>& grad);

				void clear();

			}; // class swing::graph::node::oper::Operator

		} // namespace swing::graph::node::oper

	}  // namespace swing::graph

} // namespace swing

#endif // end guards