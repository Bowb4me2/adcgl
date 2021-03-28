//
// Created by Carson Fricke on 2/7/2021 12:37pm PST
//

#ifndef __SWING_TENSOR_TENSORDATA__
#define __SWING_TENSOR_TENSORDATA__


namespace swing {

	namespace tensor {
	
		class TensorStorage;

		template<typename T>
		class TensorData {
			
			private:
				
				friend class TensorStorage;

				T** _data;

				size_t _numel;

				bool _contiguous;	

				TensorData(T** data, int numel, bool contiguous) :
					_data(new T* [numel]),
					_numel(numel),
					_contiguous(contiguous) {

					for (size_t index = 0; index < _numel; index++) {

						_data[index] = data[index];
					}

				}


			protected:

				bool compute_contiguous(T** data, size_t numel) {
					
					for (size_t index = 1; index < numel; index++) {
						if (data[index] - data[index - 1] != 1) {
							return false;
						}
					}

					return true;

				}

				void strided_permute_enforce_noncontiguous(IntRefArray sizes, IntRefArray strides, IntRefArray new_strides) {

					swing_assert(sizes.size() == strides.size() && strides.size() == new_strides.size(), "sizes and strides must have the same number of dims");

					_contiguous = false;

					size_t dims = sizes.size();

					vector_t<int64_t> initial_indicies(dims);

					int64_t individual_index;

					int64_t remaining_index;

					size_t swapped_index;

					vector_t<T*> permuted_memory(_numel);

					for (size_t index = 0; index < _numel; index++) {
						
						remaining_index = index;

						swapped_index = 0;

						for (size_t dim_index = 0; dim_index < dims; dim_index++) {
							
							individual_index = remaining_index / new_strides[dim_index];

							remaining_index -= individual_index * new_strides[dim_index];

							initial_indicies[dim_index] = individual_index;

						}

						for (size_t dim_index = 0; dim_index < dims; dim_index++) {
							
							swapped_index += initial_indicies[dim_index] * strides[dim_index];

						}

						// value swapping here
						permuted_memory[swapped_index] = _data[index];


					}

					for (size_t index = 0; index < _numel; index++) {
						_data[index] = permuted_memory[index];
					}

				}


			public:

				TensorData wrap() {

					return TensorData(_data, _numel, _contiguous);
				}

				TensorData() :
					_data(nullptr), 
					_numel(0), 
					_contiguous(true) {


				
				}

				TensorData(const size_t numel) :
					_data(new T*[numel]), 
					_numel(numel), 
					_contiguous(true) {

					T* underlying_memory = new T[_numel];

					for (size_t index = 0; index < _numel; index++) {

						underlying_memory[index] = 0;

						_data[index] = &(underlying_memory[index]);
					}
				
				}

				TensorData(size_t numel, T fill) :
					_data(new T*[numel]),
					_numel(numel),
					_contiguous(true) {

					T* underlying_memory = new T[_numel];

					for (size_t index = 0; index < _numel; index++) {
						
						underlying_memory[index] = fill;
						
						_data[index] = &(underlying_memory[index]);
					}

				}

				int64_t numel() {
					return _numel;
				}


		}; // class swing::tensor::TensorData
	
	} // namespace swing::tensor

} // namespace swing


#endif // end guards