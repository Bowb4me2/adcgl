//
// Created by Carson Fricke on 6/14/2020 4:09pm PST
//

#include "DCGraph.h"

namespace Graph {



	void DCGraph::forward() {
		for (size_t source_index = 0; source_index < this->sources.get_size(); source_index++) {
			static_cast<Node::Source&>(this->sources[source_index]).forward();
		}
	}

	void DCGraph::backward() {

		for (size_t sink_index = 0; sink_index < this->sinks.get_size(); sink_index++) {
			static_cast<Node::Sink&>(this->sinks[sink_index]).backward();
		}

	}

}