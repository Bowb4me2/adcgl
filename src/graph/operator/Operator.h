//
// Created by Carson Fricke on 6/23/2020 2:43pm PST
//

#ifndef __GRAPH_OPERATOR_OPERATOR_H__
#define __GRAPH_OPERATOR_OPERATOR_H__

#include "../../tensor/Tensor.h"
#include "../../tensor/TensorArray.h"
#include <iostream>

using scalar_t = Tensor::scalar_t;

namespace Graph {

	namespace Operator {

		class Operator {

		protected:

			Tensor::Shape operation_shape;

			Tensor::TensorArray<scalar_t> inputs;

			Tensor::TensorArray<scalar_t> grads;

			Tensor::Tensor<scalar_t> aggregate_grad;

			Tensor::TensorArray<scalar_t> constants;

			Tensor::TensorArray<scalar_t> jacobians;

			void construct_jacobians();

		public:

			virtual void get_operation(Tensor::Tensor<scalar_t>& out) = 0;

			virtual void get_jacobian(Tensor::TensorArray<scalar_t>& out) = 0;

			void aggregate_grads(Tensor::TensorArray<scalar_t>& out);

			void add_input(Tensor::Tensor<scalar_t>& input);

			void add_grad(Tensor::Tensor<scalar_t>& grad);

			void clear();

			virtual void init(Tensor::Shape operation_shape) = 0;

		}; // class Graph::Node::Operator::Operator

	} // namespace Graph::Node::Operator

}  // namespace Graph

#endif // end guards