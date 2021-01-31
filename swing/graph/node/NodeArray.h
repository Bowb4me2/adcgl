//
// Created by Carson Fricke on 6/20/2020 2:37pm PST
//

#ifndef __GRAPH_NODE_NODEARRAY_H__
#define __GRAPH_NODE_NODEARRAY_H__

namespace swing {

	namespace graph {

		namespace node {

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

			}; // class swing::graph::node::NodeArray

		} // namespace swing::graph::node

	} // namespace swing::graph

} // namespace swing

#endif // end guards