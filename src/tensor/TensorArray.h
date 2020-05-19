//
// Created by Carson Fricke on 5/18/2020 2:41pm PST
//


#ifndef __TENSORARRAY_H__
#define __TENSORARRAY_H__

#include "Tensor.h"

namespace Tensor {

	template<typename T>
	class TensorArray {
		
		private:

			size_t size;

			size_t max;

			Tensor<T>* iterable;

		public:

			Tensor<T>* operator[](int index) {
				if (index >= this->size) {
					return nullptr;
				}

				return &iterable[index];
			}

			TensorArray() 
				: size(0),
				  max(0),
				  iterable() {
				
			}

			void push_back(Tensor<T>& item) {
				
				if (this->size == this->max) {

					Tensor<T>* arr;

					arr = new Tensor<T>[this->size];

					for (size_t i = 0; i < this->size; i++) {
						arr[i] = this->iterable[i];
					}

					this->iterable = new Tensor<T>[this->size * 2];

					for (size_t i = 0; i < this->size; i++) {
						this->iterable[i] = arr[i];
					}

					delete[] arr;
					
					if (this->max != 0) {
						this->max *= 2;
					}else {
						this->max++;
					}
				}

				this->size++;

				iterable[this->size] = item;

			}

			void append(TensorArray<T>& tensor_array) {
				for (size_t i = 0; i < tensor_array.size; i++) {
					push_back(tensor_array[i]);
				}
			}

	}; // class Tensor::TensorArray

} // namespace Tensor

#endif // end guards