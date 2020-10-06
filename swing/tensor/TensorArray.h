//
// Created by Carson Fricke on 5/18/2020 2:41pm PST
//


#ifndef __TENSOR_TENSORARRAY_H__
#define __TENSOR_TENSORARRAY_H__

#include "Tensor.h"

namespace Tensor {

	template<typename T>
	class TensorArray {
		
		private:

			size_t size;

			size_t max;

			Tensor<T>* iterable;

		public:

			Tensor<T>& operator[](size_t index) {
				if (index >= this->size || index < 0) {
					throw "index outside of array range, out of bounds exception";
				}

				return this->iterable[index];
			}

			TensorArray() 
				: size(0),
				  max(0),
				  iterable() {
				
			}

			void push_back(Tensor<T>& item) {
				
				if (this->size == this->max) {

					Tensor<T>* placeholder_array;

					placeholder_array = new Tensor<T>[this->size];

					// copy array over to placeholder
					for (size_t copy_index = 0; copy_index < this->size; copy_index++) {
						placeholder_array[copy_index] = this->iterable[copy_index];
					}

					if (this->max == 0) {
						this->max++;
					} else {
						this->max *= 2;
					}

					// clear placeholder, allocate more space
					this->iterable = new Tensor<T>[this->max];

					// copy contents from placeholder over to array
					for (size_t copy_index = 0; copy_index < this->size; copy_index++) {
						this->iterable[copy_index] = placeholder_array[copy_index];
					}

					delete[] placeholder_array;
					
				}


				this->iterable[this->size] = item;


				this->size++;

			}

			void append(TensorArray<T>& tensor_array) {
				for (unsigned int index = 0; index < tensor_array.size; index++) {
					push_back(tensor_array[index]);
				}
			}

			void clear() {
				this->iterable = new Tensor<T>[this->max];

				this->size = 0;
			}

			inline size_t get_size() {
				return this->size;
			}

	}; // class Tensor::TensorArray

} // namespace Tensor

#endif // end guards