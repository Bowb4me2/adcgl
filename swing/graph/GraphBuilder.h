//
// Created by Carson Fricke on 6/20/2020 12:13pm PST
//


#ifndef __GRAPH_GRAPHBUILDER_H__
#define __GRAPH_GRAPHBUILDER_H__

#include "node/Node.h"
#include "node/placeholder/Placeholder.h"
#include "node/sink/Sink.h"
#include "node/source/Source.h"

namespace swing {

	namespace graph {

		class GraphBuilder {

		private:

			node::NodeArray nodes;

			node::NodeArray sources;

			node::NodeArray sinks;

		public:

			friend class DCGraph;

			void add_node(node::Placeholder& node);

			void add_node(node::Sink& node);

			void add_node(node::Source& node);

		}; // class swing::graph::GraphBuilder

	} // namespace swing::graph

} // namespace swing

#endif // end guards