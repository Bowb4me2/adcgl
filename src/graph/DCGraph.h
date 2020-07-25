//
// Created by Carson Fricke on 6/14/2020 4:09pm PST
//


#ifndef __DCGRAPH_H__
#define __DCGRAPH_H__

#include "nodes/NodeArray.h"
#include "nodes/sinks/Sink.h"
#include "nodes/sources/Source.h"
#include "GraphBuilder.h"

namespace Graph {

	// Differentiable Compute Graph
	class DCGraph {

		private:

			Node::NodeArray nodes;

			Node::NodeArray sources;

			Node::NodeArray sinks;

			void init_inputs();

			void init_grads();

			void init();

		public:

			DCGraph(GraphBuilder& pattern);
			
			void full_reset();
			
			void reset_visited();

			void forward();

			void backward();


	}; // class DCGraph

} // namespace Graph

#endif // end guards
