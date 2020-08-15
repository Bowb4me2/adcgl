//
// Created by Carson Fricke on 8/14/2020 8:32pm PST
//

#ifndef __TENSOR_OPERATOR_ADD__
#define __TENSOR_OPERATOR_ADD__

#include "../TensorOperator.h"

namespace Tensor {

	namespace Operator {
		
		class Add : public TensorOperator {

			protected:
				
				void operate(void* out, void* arg0, void* arg1, Shape out_shape, Shape arg0_shape, Shape arg1_shape) override;

				void validate(Shape out_shape, Shape arg0_shape, Shape arg1_shape) override;

				bool requires_brodcast(Shape out_shape, Shape arg0_shape, Shape arg1_shape) override;



		} add;

	} // namespace Tensor::Operators

} // namespace Tensor

#endif // end guards