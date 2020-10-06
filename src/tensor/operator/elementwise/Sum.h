//
// Created by Carson Fricke on 9/18/2020 11:14am PST
//


#ifndef __TENSOR_OPERATOR_SUM__
#define __TENSOR_OPERATOR_SUM__

#include "../Operator.h"

namespace Tensor {

	namespace Operator {

		template<typename T = scalar_t>
		class Sum : public Operator<T> {

		protected:

			void procedure(T* target, T* arg0, T* arg1, Shape target_shape, Shape arg0_shape, Shape arg1_shape) override;

			void validate(Shape target_shape, Shape arg0_shape, Shape arg1_shape) override;

			bool requires_brodcast(Shape target_shape, Shape arg0_shape, Shape arg1_shape) override;

			bool brodcast_which(Shape target_shape, Shape arg0_shape, Shape arg1_shape) override;

			Shape brodcast_shape(Shape target_shape, Shape arg0_shape, Shape arg1_shape, bool which) override;

		public:

			void operator()(Tensor<T>& target, Tensor<T>& arg0);

		}; // class Tensor::Operator::Sum

		static Sum<> sum;

	} // namespace Tensor::Operator

} // namespace Tensor

#endif // end guards