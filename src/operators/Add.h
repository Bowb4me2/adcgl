//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#ifndef __ADD_H__
#define __ADD_H__

#include "Operator.h"

namespace Operator {

	class Add : public Operator {

		public:

			void get_operation(Tensor::Tensor<float>& out) override;

			void get_jacobian(Tensor::TensorArray<float>& out) override;

			void init(Tensor::Shape operation_shape) override;

	}; // class Operator::Add

} // namespace Operator

#endif // end guards