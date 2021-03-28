//
// Created by Carson Fricke on 1/17/2021 12:26am PST
//

#include "TensorStorage.h"

namespace swing {

	namespace tensor {

		int64_t TensorStorage::compute_numel(IntRefArray sizes) {

			int64_t n = 1;

			for (auto s : sizes) {
				n *= s;
			}

			return n;
		}

		int64_t TensorStorage::compute_storage_size(IntRefArray sizes, IntRefArray strides) {

			swing_assert(
				sizes.size() == strides.size(),
				"dims of sizes and strides must match"
			);

			int64_t dims = sizes.size();

			int64_t output = 1;

			for (int64_t index = 0; index < dims; index++) {
				output += strides[index] * (sizes[index] - 1);
			}


			return output;
		}

		bool TensorStorage::compute_contiguous(IntRefArray sizes, IntRefArray strides) {

			swing_assert(
				sizes.size() == strides.size(),
				"dims of sizes and strides must match"
			);

			size_t dims = sizes.size();

			// include something here about a tensor being empty

			for (int64_t dim_index = dims - 1; dim_index >= 0; dim_index--) {

				int64_t stride = 1;

				if (sizes[dim_index] != 1) {

					if (strides[dim_index] == stride) {
						stride *= sizes[dim_index];
					}
					else {
						return false;
					}

				}

			}

			return true;
		}

		TensorStorage::TensorStorage(TensorData<float>& data) : 
			_data(data.wrap()), 
			_sizes(data._numel),
			_strides(1),
			_dims(1), 
			_data_offset(0), 
			_numel(data._numel),
			_contiguous(true) {
		
		}

		void TensorStorage::refresh_numel() {
			_numel = compute_numel(_sizes);
		}

		void TensorStorage::refresh_contiguous() {
			_contiguous = compute_contiguous(_sizes, _strides);
		}

		void TensorStorage::empty_tensor_refresh_strides() {

			int64_t stride = 1;

			for (int64_t stride_index = _dims - 1; stride_index >= 0; stride_index--) {

				_strides[stride_index] = stride;

				stride *= _sizes[stride_index];
			}
		}

		void TensorStorage::enforce_internal_contiguity() {

			swing_assert(!_contiguous, "tensor cannot be contiguous");

			swing_assert(_data_offset == 0, "tensor must have a storage offset of 0");

			swing_assert(_data.numel() == _numel, "sizes must match");

			vector_t<int64_t> vec_strides = _strides;

			IntRefArray strides = vec_strides;

			empty_tensor_refresh_strides();

			_data.strided_permute_enforce_noncontiguous(_sizes, strides, _strides);

		}

		TensorStorage::TensorStorage() : 
			_data(0), 
			_sizes(), 
			_strides(), 
			_dims(0),
			_data_offset(0),
			_numel(0),
			_contiguous(true) {

		}

		TensorStorage::TensorStorage(IntRefArray sizes) :
			_data(compute_numel(sizes)),
			_sizes(sizes.vec()),
			_strides(sizes.numel()),
			_dims(sizes.numel()),
			_data_offset(0),
			_numel(compute_numel(sizes)),
			_contiguous(true) {

			empty_tensor_refresh_strides();

		}

		void TensorStorage::set_sizes_and_strides(IntRefArray new_sizes, IntRefArray new_strides, size_t data_offset) {

			// check that everything is in bounds for memory
			swing_assert(
				compute_storage_size(new_sizes, new_strides) + data_offset <= _numel,
				"new strides and sizes are not within memory boundaries"
			);


			auto new_dims = new_sizes.size();

			_sizes.resize(new_dims);

			for (size_t dim_index = 0; dim_index < new_dims; dim_index++) {
				_sizes[dim_index] = new_sizes[dim_index];
			}

			_strides.resize(new_dims);

			for (int64_t dim_index = new_dims - 1; dim_index >= 0; dim_index--) {

				if (new_strides[dim_index] >= 0) {
					_strides[dim_index] = new_strides[dim_index];
				}
				else {

					if (new_dims == dim_index - 1) {
						_strides[dim_index] = 1;
					}
					else {
						_strides[dim_index] = std::max<int64_t>(_sizes[dim_index + 1], 1) * _strides[dim_index + 1];
					}
				}
			}

			_dims = new_dims;

			_data_offset = data_offset;

			refresh_numel();

			refresh_contiguous();

		}

		TensorStorage TensorStorage::as_strided(IntRefArray new_sizes, IntRefArray new_strides, int64_t data_offset) {
		
			TensorStorage x(_data);

			x.set_sizes_and_strides(new_sizes, new_strides, data_offset);

			return x;
		}
		
		IntRefArray TensorStorage::sizes() {
			return IntRefArray(_sizes);
		}

		IntRefArray TensorStorage::strides() {
			return IntRefArray(_strides);
		}

		int64_t TensorStorage::dims() {
			return _dims;
		}

		int64_t TensorStorage::numel() {
			return _numel;
		}

		int64_t TensorStorage::size(int64_t index) {
			return _sizes[index];
		}

		int64_t TensorStorage::stride(int64_t index) {
			return _strides[index];
		}




	} // namespace swing::tensor

} // namespace swing



