//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#ifndef __SUB_H__
#define __SUB_H__

#include "Operator.h"

namespace Operator {
			
	class Sub : public Operator {

		public:

			void get_operation(Tensor::Tensor<float>& out) override;

			void get_jacobian(Tensor::TensorArray<float>& out) override;

			void init(Tensor::Shape operation_shape) override;

	}; // class Operator::Sub

} // namespace Operator

#endif // end guards