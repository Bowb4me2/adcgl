//
// Created by Carson Fricke on 9/7/2020 12:53pm PST
//


#ifndef __TENSOR_OPERATOR_DOT__
#define __TENSOR_OPERATOR_DOT__

#include "../Operator.h"

namespace Tensor {

	namespace Operator {
		
		// technically speaking this is a frobenius inner product, not a true dot product
		template<typename T=scalar_t>
		class Dot : public Operator<T> {

			protected:
				
				void procedure(T* target, T* arg0, T* arg1, Shape target_shape, Shape arg0_shape, Shape arg1_shape) override;

				void validate(Shape target_shape, Shape arg0_shape, Shape arg1_shape) override;

				bool requires_brodcast(Shape target_shape, Shape arg0_shape, Shape arg1_shape) override;

				bool brodcast_which(Shape target_shape, Shape arg0_shape, Shape arg1_shape) override;

				Shape brodcast_shape(Shape target_shape, Shape arg0_shape, Shape arg1_shape, bool which) override;

		}; // class Tensor::Operator::Add

		static Dot<> dot;

	} // namespace Tensor::Operator

} // namespace Tensor

#endif // end guards