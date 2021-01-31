//
// Created by Carson Fricke on 1/17/2021 12:25am PST
//

#ifndef __TENSOR_TENSORSTORAGE_H__
#define __TENSOR_TENSORSTORAGE_H__

#include "../common/common.h"
#include "../common/exception.h"


namespace swing {

	namespace tensor {

		template<typename T>
		class TensorStorage {

			private:

				// data
				// pointers to references for permutation
				T** _data;
		
				// sizes
				vector_t<int64_t> _sizes;

				// strides
				vector_t<int64_t> _strides;

				// dims
				int64_t _dims;

				int64_t _data_offset;

				// numel
				size_t _numel;

				// is contiguous, effectively whether or not the tensor elements are adjacent in memory
				bool _contiguous;


			protected:

				
				static int64_t compute_numel(IntRefArray sizes) {
					
					int64_t n = 1;

					for (auto s : sizes) {
						n *= s;
					}

					return n;
				}

				bool compute_contiguous() {

					// include something here about a tensor being empty

					for (int64_t dim_index = _dims - 1; dim_index >= 0; dim_index--) {

						int64_t stride = 1;

						if (_sizes[dim_index] != 1) {

							if (_stride[dim_index] == stride) {
								stride *= _sizes[dim_index];
							}
							else {
								return false;
							}

						}

					}

					return true;
				}

				void refresh_numel() {
					_numel = compute_numel(_sizes);
				}

				void refresh_contiguous() {
					_contiguous = compute_contiguous();
				}

				void refresh_strides() {
					
					int64_t stride = 1;
					
					for (int64_t stride_index = _dims - 1; stride_index >= 0; stride_index--) {
						
						_strides[stride_index] = stride;

						stride *= _sizes[stride_index];
					}
				}

			public:
				
				TensorStorage(IntRefArray sizes, T fill=0) :
					_data(new T*[compute_numel(sizes)]),
					_sizes(sizes.vec()),
					_strides(sizes.numel()),
					_dims(sizes.numel()),
					_data_offset(0),
					_numel(compute_numel(sizes)),
					_contiguous(true) {

						T* underlying_memory = new T[_numel];

						for (size_t memory_index = 0; memory_index < _numel; memory_index++) {
							_data[memory_index] = &(underlying_memory[memory_index]);
						}

						refresh_strides();
				
				
				}

				void set_sizes_and_strides(IntRefArray new_sizes, IntRefArray new_strides) {

					swing_assert(new_sizes.size() == new_strides.size(), "size of new_sizes and new_strides must match");

					auto new_dims = new_sizes.size();

					_sizes.resize(new_dims);

					for (size_t dim_index = 0; dim_index < new_dims; dim_index++) {
						_sizes[dim_index] = new_sizes[dim_index];
					}
				
					_strides.resize(new_dims);

					for (int64_t dim_index = new_dims - 1; dim_index >= 0; dim_index--) {
						// finish
					}

				}

				IntRefArray sizes() {
					return IntRefArray(_sizes);
				}

				IntRefArray strides() {
					return IntRefArray(_strides);
				}

				int64_t dims() {
					return _dims;
				}

				int64_t numel() {
					return _numel;
				}
				
				int64_t size(int64_t index) {
					return _sizes[index];
				}

				int64_t stride(int64_t index) {
					return _strides[index];
				}
		};

	} // namespace swing::tensor

} // namespace swing

#endif // end guards
