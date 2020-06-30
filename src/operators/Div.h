//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#ifndef __DIV_H__
#define __DIV_H__

#include "Operator.h"

namespace Operator {

	class Div : public Operator {

		public:

			void get_operation(Tensor::Tensor<float>& out) override;

			void get_jacobian(Tensor::TensorArray<float>& out) override;

	}; // class Operator::Div

} // namespace Operator

#endif // end guards