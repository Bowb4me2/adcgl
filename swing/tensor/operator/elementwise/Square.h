//
// Created by Carson Fricke on 12/10/2020 2:24pm PST
//


#ifndef __TENSOR_OPERATOR_SQUARE__
#define __TENSOR_OPERATOR_SQUARE__

#include "../Operator.h"

namespace swing {

	namespace tensor {

		namespace oper {

			template<typename T = scalar_t>
			class Square : public Operator<1, T> {

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


			}; // class swing::tensor::oper::Sum

			static Square<> square;

		} // namespace swing::tensor::oper

	} // namespace swing::tensor

} // namespace swing

#endif // end guards
