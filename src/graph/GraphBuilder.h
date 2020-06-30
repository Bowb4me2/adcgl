//
// Created by Carson Fricke on 6/20/2020 12:13pm PST
//


#ifndef __GRAPHBUILDER_H__
#define __GRAPHBUILDER_H__

#include "nodes/Node.h"
#include "nodes/placeholders/Placeholder.h"
#include "nodes/sinks/Sink.h"
#include "nodes/sources/Source.h"

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