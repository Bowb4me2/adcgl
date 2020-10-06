#include <iostream>

#include <swing.h>

#include <graph/operator/matrix/Outer.h>

#include <graph/operator/matrix/Dot.h>

#include <stdlib.h>

// performs an out product between two tensors and then a dot product uppon the result.


int main() {


	Graph::GraphBuilder settings;

	scalar_t a1[] = { 2.0f };
	scalar_t a2[] = { 1.0f, 2.0f, 3.0f};

	size_t a3[] = { 1, 3 };
	Tensor::Shape s3(a3);

	scalar_t a4[] = { 1, 1, 0.5 };
	scalar_t a5[] = { 0 };

	Tensor::Tensor<> source_contents1(    a1);
	Tensor::Tensor<> source_contents2(    a2);
	Tensor::Tensor<> source_contents3(    a4);
	Tensor::Tensor<> placeholder_contents(s3);
	Tensor::Tensor<> sink_contents(       a5);

	Graph::Node::Constant constant1(     source_contents1);
	Graph::Node::Constant constant2(     source_contents2);
	Graph::Node::Constant constant3(     source_contents3);
	Graph::Node::Placeholder placeholder(placeholder_contents, Graph::Operator::Outer());
	Graph::Node::Sink sink(              sink_contents,        Graph::Operator::Dot());

	settings.add_node(constant1);
	settings.add_node(constant2);
	settings.add_node(constant3);
	settings.add_node(placeholder);
	settings.add_node(sink);

	Graph::Node::link(constant1, placeholder);
	Graph::Node::link(constant2, placeholder);

	Graph::Node::link(constant3, sink);
	Graph::Node::link(placeholder, sink);
	

	Graph::DCGraph graph(settings);

	graph.forward();

	std::cout << "Placeholder Tensor: " << placeholder_contents << "\n";

	std::cout << "Output Tensor: " << sink_contents << "\n";

	graph.reset_visited();

	graph.backward();

	// remember to remove print statements in graph/operators

	std::cout << "Placeholder Tensor: " << placeholder_contents << "\n";

	std::cout << "Output Tensor: " << sink_contents << "\n";

	return 0;

}
