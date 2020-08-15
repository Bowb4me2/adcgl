//
// Created by Carson Fricke on 8/12/2020 11:26am PST
//

#ifndef __TENSOROPERATOR_H__
#define __TENSOROPERATOR_H__

#include "../Tensor.h"

namespace Tensor {

	namespace Operator {
	
		class TensorOperator {

			protected:
				
				virtual void operate(void* out, void* arg0, void* arg1, Shape out_shape, Shape arg0_shape, Shape arg1_shape) = 0;
				
				virtual void validate(Shape out_shape, Shape arg0_shape, Shape arg1_shape) = 0;

				virtual bool requires_brodcast(Shape out_shape, Shape arg0_shape, Shape arg1_shape) = 0;

			public:

				void operator()(Tensor<float>& out, Tensor<float>& arg0, Tensor<float>& arg1);

		}; // class Tensor::Operators::TensorOperator
		
	} // namespace Tensor::Operators

} // namespace Tensor


#endif // end guards
