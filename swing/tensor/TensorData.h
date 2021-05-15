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

				//
				// the potentially permuted data
				T** _data;

				//
				// the origenal, allocated data
				T* _alloc;

				//
				// number of items
				size_t _numel;

				//
				// whether or not this items elements are in order
				bool _contiguous;

				//
				// this tensor's parent, if nullptr then this tensor is origenal.
				TensorData<T>* _parent;

				TensorData(T** data, T* alloc, size_t numel, bool contiguous, TensorData<T>* parent) :
					_data(new T* [numel]),
					_alloc(alloc),
					_numel(numel),
					_contiguous(contiguous),
					_parent(parent) {

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

					return TensorData(_data, _alloc, _numel, _contiguous, this);
				}

				TensorData() :
					_data(nullptr), 
					_alloc(nullptr),
					_numel(0), 
					_contiguous(true),
					_parent(nullptr) {
				
				}

				TensorData(const size_t numel) :
					_data(new T*[numel]),
					_alloc(new T[numel]),
					_numel(numel), 
					_contiguous(true), 
					_parent(nullptr) {

					for (size_t index = 0; index < _numel; index++) {

						_alloc[index] = 0;

						_data[index] = &(_alloc[index]);
					}
				
				}

				TensorData(size_t numel, T fill) :
					_data(new T*[numel]),
					_alloc(new T[numel]),
					_numel(numel),
					_contiguous(true),
					_parent(nullptr) {

					for (size_t index = 0; index < _numel; index++) {
						
						_alloc[index] = fill;
						
						_data[index] = &(_alloc[index]);
					}

				}

				int64_t numel() {
					return _numel;
				}

				
				~TensorData() {
					
					if (_parent == nullptr) {
						if (_alloc) {
							delete[] _alloc;
						}
					} else {
						_parent = nullptr;
					}

					if (_data) {
						delete[] _data;
					}
				}

		}; // class swing::tensor::TensorData
	
	} // namespace swing::tensor

} // namespace swing


#endif // end guards