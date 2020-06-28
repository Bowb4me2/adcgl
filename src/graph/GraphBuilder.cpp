//
// Created by Carson Fricke on 6/20/2020 12:13pm PST
//

#include "GraphBuilder.h"

void Graph::GraphBuilder::add_node(Node::Placeholder& node) {
	this->nodes.push_back(node);
}

void Graph::GraphBuilder::add_node(Node::Sink& node) {
	this->nodes.push_back(node);

	this->sinks.push_back(node);
}

void Graph::GraphBuilder::add_node(Node::Source& node) {
	this->nodes.push_back(node);

	this->sources.push_back(node);
}
