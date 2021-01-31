//
// Created by Carson Fricke on 6/14/2020 4:09pm PST
//


#ifndef __GRAPH_DCGRAPH_H__
#define __GRAPH_DCGRAPH_H__

#include "node/NodeArray.h"
#include "node/sink/Sink.h"
#include "node/source/Source.h"
#include "GraphBuilder.h"

namespace swing {

	namespace graph {

		// Differentiable Compute Graph
		class DCGraph {

		private:

			node::NodeArray nodes;

			node::NodeArray sources;

			node::NodeArray sinks;

			void init_inputs();

			void init_grads();

			void init();

		public:

			DCGraph(GraphBuilder& pattern);

			void full_reset();

			void reset_visited();

			void forward();

			void backward();


		}; // class swing::graph::DCGraph

	} // namespace swing::graph

} // namespace swing

#endif // end guards
