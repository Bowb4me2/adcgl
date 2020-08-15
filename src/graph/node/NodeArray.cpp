#include "NodeArray.h"
//
// Created by Carson Fricke on 6/20/2020 2:37pm PST
//

namespace Graph {

	namespace Node {

		Node& NodeArray::operator[](size_t index) {
			if (index >= this->size || index < 0) {
				throw "index outside of array range, out of bounds exception";
			}

			return *this->iterable[index];
		}

		NodeArray::NodeArray()
			: size(0),
			max(0),
			iterable() {

		}

		void NodeArray::push_back(Node& item) {

			if (this->size == this->max) {

				Node** placeholder_array;

				placeholder_array = new Node*[this->size];

				// copy array over to placeholder
				for (size_t copy_index = 0; copy_index < this->size; copy_index++) {
					placeholder_array[copy_index] = this->iterable[copy_index];
				}

				if (this->max == 0) {
					this->max++;
				}
				else {
					this->max *= 2;
				}

				// clear placeholder, allocate more space
				this->iterable = new Node*[(this->max)];

				// copy contents from placeholder over to array
				for (size_t copy_index = 0; copy_index < this->size; copy_index++) {
					this->iterable[copy_index] = placeholder_array[copy_index];
				}

				delete[] placeholder_array;

			}


			this->iterable[this->size] = &item;


			this->size++;

		}

		void NodeArray::append(NodeArray& node_array) {
			for (unsigned int index = 0; index < node_array.size; index++) {
				push_back(node_array[index]);
			}
		}

		void NodeArray::clear() {
			this->iterable = new Node*[this->max];

			this->size = 0;
		}

		size_t NodeArray::get_size() {
			return this->size;
		}

	} // namespace Graph::Node

} // namespace Graph 