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
		class Dot : public Operator<2, T> {

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

		static Dot<> dot;

	} // namespace Tensor::Operator

} // namespace Tensor

#endif // end guards