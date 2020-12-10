//
// Created by Carson Fricke on 8/14/2020 8:32pm PST
//


#ifndef __TENSOR_OPERATOR_MUL__
#define __TENSOR_OPERATOR_MUL__

#include "../Operator.h"

namespace Tensor {

	namespace Operator {

		template<typename T = scalar_t>
		class Mul : public Operator<2, T> {

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


		}; // class Tensor::Operator::Mul

		static Mul<> mul;

	} // namespace Tensor::Operator

} // namespace Tensor

#endif // end guards

