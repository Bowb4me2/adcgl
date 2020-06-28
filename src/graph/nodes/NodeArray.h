//
// Created by Carson Fricke on 6/20/2020 2:37pm PST
//

#ifndef __NODEARRAY_H__
#define __NODEARRAY_H__

namespace Graph {

	namespace Node {

		class Node;

		class NodeArray {

			private:

				size_t size;

				size_t max;

				Node** iterable;
				
			public:

				Node& operator[](size_t index);

				NodeArray();

				void push_back(Node& item);

				void append(NodeArray& tensor_array);

				void clear();

				size_t get_size();

		}; // class Graph::Node::NodeArray

	} // namespace Graph::Node

} // namespace Graph

#endif // end guards