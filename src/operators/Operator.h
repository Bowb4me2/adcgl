//
// Created by Carson Fricke on 6/23/2020 2:43pm PST
//

#ifndef __OPERATOR_H__
#define __OPERATOR_H__

#include "../tensor/Tensor.h"
#include "../tensor/TensorArray.h"


namespace Operator {
			
	class Operator {

		protected:

			Tensor::TensorArray<float> inputs;

			Tensor::TensorArray<float> grads;

			Tensor::TensorArray<float> constants;					

		public:

			virtual void get_operation(Tensor::Tensor<float>& out) = 0;

			virtual void get_jacobian(Tensor::TensorArray<float>& out) = 0;

			void add_input(Tensor::Tensor<float>& input);

			void add_grad(Tensor::Tensor<float>& grad);

			void clear();

			void init();

	}; // class Graph::Node::Operator::Operator

} // namespace Graph::Node::Operator


#endif // end guards