//
// Created by Carson Fricke on 10/19/2020 3:36pm PST
//


#ifndef __TENSOR_OPERATOR_TENSORDOT__
#define __TENSOR_OPERATOR_TENSORDOT__

#include "../Operator.h"

namespace Tensor {

	namespace Operator {

		// technically speaking this is a frobenius inner product, not a true dot product
		template<typename T = scalar_t>
		class TensorDot : public Operator<2, T> {

			protected:

				void pointer_procedure(
					T* target,
					Shape target_shape,
					T* tensor_pointers[2],
					Shape shapes[2]
				) override;

				void validate(
					T* target_contents,
					Shape target_shape,
					T* tensor_contents[2],
					Shape shapes[2]
				) override;

				void settup_directives(
					T* target_contents,
					Shape target_shape,
					T* tensor_contents[2],
					Shape shapes[2],
					T* (&modified_tensor_contents)[2],
					Shape(&modified_shapes)[2]
				) override;

		}; // class Tensor::Operator::Add

		static TensorDot<> tensor_dot;

	} // namespace Tensor::Operator

} // namespace Tensor

#endif // end guards