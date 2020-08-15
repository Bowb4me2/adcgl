//
// Created by Carson Fricke on 6/20/2020 12:13pm PST
//


#ifndef __GRAPH_GRAPHBUILDER_H__
#define __GRAPH_GRAPHBUILDER_H__

#include "node/Node.h"
#include "node/placeholder/Placeholder.h"
#include "node/sink/Sink.h"
#include "node/source/Source.h"

namespace Graph {

	class GraphBuilder {

	private:

		Node::NodeArray nodes;

		Node::NodeArray sources;

		Node::NodeArray sinks;

	public:

		friend class DCGraph;

		void add_node(Node::Placeholder& node);

		void add_node(Node::Sink& node);

		void add_node(Node::Source& node);

	}; // class GraphBuilder

} // namespace Graph

#endif // end guards