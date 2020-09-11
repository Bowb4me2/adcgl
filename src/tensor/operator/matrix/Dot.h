//
// Created by Carson Fricke on 9/7/2020 12:53pm PST
//


#ifndef __TENSOR_OPERATOR_DOT__
#define __TENSOR_OPERATOR_DOT__

#include "../Operator.h"

namespace Tensor {

	namespace Operator {
		
		template<typename T=scalar_t>
		class Dot : public Operator<T> {

			protected:
				
				void procedure(T* out, T* arg0, T* arg1, Shape out_shape, Shape arg0_shape, Shape arg1_shape) override;

				void validate(Shape out_shape, Shape arg0_shape, Shape arg1_shape) override;

				bool requires_brodcast(Shape out_shape, Shape arg0_shape, Shape arg1_shape) override;

				bool brodcast_which(Shape out_shape, Shape arg0_shape, Shape arg1_shape) override;

				Shape brodcast_shape(Shape out_shape, Shape arg0_shape, Shape arg1_shape, bool which) override;

		}; // class Tensor::Operator::Add

		static Dot<> dot;

	} // namespace Tensor::Operator

} // namespace Tensor

#endif // end guards