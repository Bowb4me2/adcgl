//
// Created by Carson Fricke on 1/17/2021 12:25am PST
//

#ifndef __SWING_TENSOR_TENSORSTORAGE_H__
#define __SWING_TENSOR_TENSORSTORAGE_H__

#include "../common/common.h"
#include "../common/exception.h"
#include "TensorData.h"


namespace swing {

	namespace tensor {


		class TensorStorage {

			private:

				// data
				// pointers to references for permutation
				TensorData<float> _data;
		
				// sizes
				vector_t<int64_t> _sizes;

				// strides
				vector_t<int64_t> _strides;

				// the storage offset, ie what is treated as
				// the start of this tensor
				size_t _data_offset;

				// dims, number of dimentions
				int64_t _dims;

				// numel, total tensor elements
				size_t _numel;

				// if the tensor storage is contiguous, 
				// ie whether or not strides access elements 
				// in order that are concentric in memory.
				// ie, all the elements are next to each other
				// when accessed with strides
				bool _contiguous;

			protected:
				
				static int64_t compute_numel(IntRefArray sizes);

				static int64_t compute_storage_size(IntRefArray sizes, IntRefArray strides);

				static bool compute_contiguous(IntRefArray sizes, IntRefArray strides);

				TensorStorage(TensorData<float>& data);

				void refresh_numel();

				void refresh_contiguous();

				// populates strides with standard contiguous strides
				void empty_tensor_refresh_strides();

			public:
				
				// modifies internal TensorData
				void enforce_internal_contiguity();

				TensorStorage();

				TensorStorage(IntRefArray sizes);

				void set_sizes_and_strides(IntRefArray new_sizes, IntRefArray new_strides, size_t data_offset = 0);

				TensorStorage as_strided(IntRefArray new_sizes, IntRefArray new_strides, int64_t storage_offset = 0);

				IntRefArray sizes();

				IntRefArray strides();

				int64_t dims();

				int64_t numel();
				
				int64_t size(int64_t index);

				int64_t stride(int64_t index);

		};

	} // namespace swing::tensor

} // namespace swing

#endif // end guards
