//
// Created by Carson Fricke on 9/18/2020 11:14am PST
//


#ifndef __TENSOR_OPERATOR_SUM__
#define __TENSOR_OPERATOR_SUM__

#include "../Operator.h"

namespace Tensor {

	namespace Operator {

		template<typename T = scalar_t>
		class Sum : public Operator<1, T> {

			protected:

				void pointer_procedure(
					T* target,
					Shape target_shape,
					T* tensor_pointers[1],
					Shape shapes[1]
				) override;

				void validate(
					T* target_contents,
					Shape target_shape,
					T* tensor_contents[1],
					Shape shapes[1]
				) override;

				void settup_directives(
					T* target_contents,
					Shape target_shape,
					T* tensor_contents[1],
					Shape shapes[1],
					T* (&modified_tensor_contents)[1],
					Shape(&modified_shapes)[1]
				) override;


		}; // class Tensor::Operator::Sum

		static Sum<> sum;

	} // namespace Tensor::Operator

} // namespace Tensor

#endif // end guards