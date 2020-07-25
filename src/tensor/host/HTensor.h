//
// Created by Carson Fricke on 6/17/2020 5:39pm PST
//

#include <Tensor.h>

namespace Tensor {

	template<typename T>
	class HTensor : public Tensor<T> {

	private:
		
		void brodcast_to_mem_recursive(Tensor<T>& iterable, size_t depth, size_t dim_difference, size_t host_index, size_t iterable_index) {

			// ensures recursion stops when tensor tips are reached
			if (depth < this->shape.dims) {

				// ensures that if iterable tensor has less dims that they are not accessed until later
				if (depth < dim_difference) {

					// recur once for every item in the current shape dimention, selected by depth
					// this runs before the iterable tensor is accessable
					for (size_t shape_index = 0; shape_index < this->shape.shape[depth]; shape_index++) {
						brodcast_to_mem_recursive(iterable,
							depth + 1,
							dim_difference,
							host_index * this->shape.shape[depth] + shape_index,
							0);
					}
				}
				else {

					// recur once for every item in the current shape dimention, selected by depth
					// this runs only if the iterable tensor can now be accessed
					for (size_t shape_index = 0; shape_index < this->shape.shape[depth]; shape_index++) {
						brodcast_to_mem_recursive(iterable,
							depth + 1,
							dim_difference, host_index * this->shape.shape[depth] + shape_index,
							iterable_index * iterable.get_shape().shape[depth - dim_difference] + (iterable.get_shape().shape[depth] == 1) ? 0 : shape_index);
					}
				}

			}
			else {
				// copies the value from the appropriate iterable's index to the brodcast_iterables index
				this->brodcast_iterable[host_index] = iterable.get_iterable()[iterable_index];
			}

		} // recursive brodcast helper function 
		

	protected:

		void brodcast_to_mem(Tensor<T>& iterable) override {
			brodcast_to_mem_recursive(iterable, 0, this->shape.dims - iterable.get_shape().dims, 0, 0);
		}

		void operate(Tensor<T>& out, void (*operation)(T*, T*, T*, size_t)) override {
			operation(out.get_iterable(), this->iterable, this->brodcast_iterable, out.get_size());
		}

	public:
	
		T& operator[](size_t index) override {
			
			if (index >= this->size || index < 0) {
				throw "index outside of tensor range, out of bounds exception";
			}

			return this->iterable[index];
		}

		HTensor() : Tensor() {
			fill(T(0));
		}

		HTensor(size_t size) : Tensor(size) {
			fill(T(0));
		}

		HTensor(Shape shape) : Tensor(shape) {
			fill(T(0));
		}

		template<size_t N>
		HTensor(const T(&iterable)[N]) : Tensor(iterable) {

			//for (size_t i = 0; i < N; i++) {
			//	this->iterable[i] = iterable[i];
			//}

		}

		void fill(T fill_contents) override {
			for (size_t index = 0; index < this->size; index++) {
				this->iterable[index] = fill_contents;
			}
		}

		Tensor<T>& clone() override {
			return *(new HTensor<T>(this->shape));
		}

		T* get_iterable() override {
			return this->iterable;
		}

		T* get_brodcast_iterable() override {
			return this->brodcast_iterable;
		}

	}; // class Tensor::HTensor<T>

} // namespace Tensor
