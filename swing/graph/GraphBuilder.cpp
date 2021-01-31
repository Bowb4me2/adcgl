//
// Created by Carson Fricke on 6/20/2020 12:13pm PST
//

#include "GraphBuilder.h"

namespace swing {

	namespace graph {

		void GraphBuilder::add_node(node::Placeholder& node) {
			this->nodes.push_back(node);
		}

		void GraphBuilder::add_node(node::Sink& node) {
			this->nodes.push_back(node);

			this->sinks.push_back(node);
		}

		void GraphBuilder::add_node(node::Source& node) {
			this->nodes.push_back(node);

			this->sources.push_back(node);
		}

	} // namespace swing::graph

} // namespace swing