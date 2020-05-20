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

			Tensor<T>& operator[](int index) {
				if (index >= this->size) {
					throw std::out_of_range("you done goofed");
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

					Tensor<T>* arr;

					arr = new Tensor<T>[this->size];

					for (size_t i = 0; i < this->size; i++) {
						arr[i] = this->iterable[i];
					}

					if (this->max == 0) {
						this->max++;
					} else {
						this->max *= 2;
					}


					this->iterable = new Tensor<T>[(this->max)];

					for (size_t i = 0; i < this->size; i++) {
						this->iterable[i] = arr[i];
					}

					delete[] arr;
					
				}


				this->iterable[this->size] = item;


				this->size++;

			}

			void append(TensorArray<T>& tensor_array) {
				for (size_t i = 0; i < tensor_array.size; i++) {
					push_back(tensor_array[i]);
				}
			}

			size_t get_size() {
				return this->size;
			}

	}; // class Tensor::TensorArray

} // namespace Tensor

#endif // end guards