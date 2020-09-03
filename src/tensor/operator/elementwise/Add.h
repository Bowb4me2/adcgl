//
// Created by Carson Fricke on 8/14/2020 8:32pm PST
//


#ifndef __TENSOR_OPERATOR_ADD__
#define __TENSOR_OPERATOR_ADD__

#include "../Operator.h"

namespace Tensor {

	namespace Operator {
		
		template<typename T=scalar_t>
		class Add : public Operator<T> {

			protected:
				
				void procedure(T* out, T* arg0, T* arg1, Shape out_shape, Shape arg0_shape, Shape arg1_shape) override;

				void validate(Shape out_shape, Shape arg0_shape, Shape arg1_shape) override;

				bool requires_brodcast(Shape out_shape, Shape arg0_shape, Shape arg1_shape) override;

		}; // class Tensor::Operator::Add

		static Add<> add;

	} // namespace Tensor::Operator

} // namespace Tensor

#endif // end guards