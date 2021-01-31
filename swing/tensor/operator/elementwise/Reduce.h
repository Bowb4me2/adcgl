//
// Created by Carson Fricke on 12/24/2020 1:26pm PST
//


// refactor this badboy to include dimentions to sum over

#ifndef __TENSOR_OPERATOR_REDUCE__
#define __TENSOR_OPERATOR_REDUCE__

#include "../Operator.h"

namespace swing {

	namespace tensor {

		namespace oper {

			template<typename T = scalar_t>
			class Reduce : public Operator<1, T, int> {

			protected:

				void pointer_procedure(
					T* target,
					Shape target_shape,
					T* tensor_pointers[1],
					Shape shapes[1],
					int&& dims
				) override;

				void validate(
					T* target_contents,
					Shape target_shape,
					T* tensor_contents[1],
					Shape shapes[1],
					int&& dims
				) override;

				void settup_directives(
					T* target_contents,
					Shape target_shape,
					T* tensor_contents[1],
					Shape shapes[1],
					T* (&modified_tensor_contents)[1],
					Shape(&modified_shapes)[1],
					int&& dims
				) override;


			}; // class swing::tensor::oper::Reduce

			static Reduce<> reduce;

		} // namespace swing::tensor::oper

	} // namespace swing::tensor

} // namespace swing

#endif // end guards