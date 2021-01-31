//
// Created by Carson Fricke on 8/12/2020 11:26am PST
//

#ifndef __TENSOR_OPERATOR_H__
#define __TENSOR_OPERATOR_H__

#include "../Tensor.h"
#include <array>


typedef double scalar_t;


namespace swing {

	namespace tensor {

		namespace oper {

			template<int64_t N_TENSORS, typename T = scalar_t, typename... ARGS>
			class Operator {

			protected:

				virtual void pointer_procedure(
					T* target,
					Shape target_shape,
					T* tensor_pointers[N_TENSORS],
					Shape shapes[N_TENSORS],
					ARGS&&... args
				) = 0;

				// will throw errors if args are not compatible
				virtual void validate(
					T* target_contents,
					Shape target_shape,
					T* tensor_contents[N_TENSORS],
					Shape shapes[N_TENSORS],
					ARGS&&... args
				) = 0;

				// inteded to include things like brodcasting, internal stuff
				virtual void settup_directives(
					T* target_contents,
					Shape target_shape,
					T* tensor_contents[N_TENSORS],
					Shape shapes[N_TENSORS],
					T* (&modified_tensor_contents)[N_TENSORS],
					Shape(&modified_shapes)[N_TENSORS],
					ARGS&&... args
				) = 0;

				static T* brodcast_pointer(
					T* iterable,
					Shape& host_shape,
					Shape& target_shape
				) {
					Tensor<T>::brodcast_to_mem_recursive(
						iterable,
						host_shape,
						0,
						target_shape.dims - host_shape.dims,
						0,
						0,
						target_shape
					);

					return Tensor<T>::brodcast_iterable;
				}

				void operation_internal(
					Tensor<T>& target,
					const Tensor<T>(&tensor_args)[N_TENSORS],
					ARGS&&... args
				) {


					T* tensor_contents[N_TENSORS];
					Shape shapes[N_TENSORS];

					T* tensor_contents_modified[N_TENSORS];
					Shape shapes_modified[N_TENSORS];

					for (int64_t arg_index = 0; arg_index < N_TENSORS; arg_index++) {
						tensor_contents[arg_index] = tensor_args[arg_index].iterable;
						shapes[arg_index] = tensor_args[arg_index].shape;
					}

					validate(
						target.iterable,
						target.shape,
						tensor_contents,
						shapes,
						args...
					);

					settup_directives(
						target.iterable,
						target.shape,
						tensor_contents,
						shapes,
						tensor_contents_modified,
						shapes_modified,
						args...
					);

					pointer_procedure(target.iterable, target.shape, tensor_contents_modified, shapes_modified, args...);
				}


			public:

				void operator()(Tensor<T>& target, const Tensor<T>(&tensor_args)[N_TENSORS], ARGS&&... args) {
					operation_internal(target, tensor_args, args...);
				}

			}; // class swing::tensor::oper::Operator

		} // namespace swing::tensor::oper

	} // namespace swing::tensor

} // namespace swing


#endif // end guards
