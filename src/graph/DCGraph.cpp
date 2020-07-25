//
// Created by Carson Fricke on 6/14/2020 4:09pm PST
//

#include "DCGraph.h"

namespace Graph {
	
	void DCGraph::init_inputs() {
		for (size_t source_index = 0; source_index < this->sources.get_size(); source_index++) {
			this->sources[source_index].init_input();
		}
	}

	void DCGraph::init_grads() {
		for (size_t sink_index = 0; sink_index < this->sinks.get_size(); sink_index++) {
			this->sinks[sink_index].init_grad();
		}
	}

	void DCGraph::init() {
		
		init_inputs();
		reset_visited();

		init_grads();
		reset_visited();
	}

	DCGraph::DCGraph(GraphBuilder& pattern)
		: nodes(pattern.nodes), 
		  sources(pattern.sources), 
		  sinks(pattern.sinks) {
		
		init();
	}

	void DCGraph::full_reset() {

	}

	void DCGraph::reset_visited() {
		for (size_t node_index = 0; node_index < this->nodes.get_size(); node_index++) {
			this->nodes[node_index].reset_visited();
		}
	}

	void DCGraph::forward() {
		for (size_t source_index = 0; source_index < this->sources.get_size(); source_index++) {
			this->sources[source_index].forward();
		}
	}

	void DCGraph::backward() {
		for (size_t sink_index = 0; sink_index < this->sinks.get_size(); sink_index++) {
			this->sinks[sink_index].backward();
		}
	}



}