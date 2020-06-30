#include <iostream>

#include <adcgl.h>

#include <operators/Add.h>

#include <string>


int main() {

	Graph::GraphBuilder settings;

	float a1[] = { 5.1f, 0.2f };
	float a2[] = { 2.4f, 0.9f };
	float a3[] = { 0.0f, 0.0f };

	Tensor::HTensor<float> source_contents1(a1);
	Tensor::HTensor<float> source_contents2(a2);
	Tensor::HTensor<float> sink_contents(a3);

	Graph::Node::Constant constant_source1(source_contents1);
	Graph::Node::Constant constant_source2(source_contents2);
	Graph::Node::Sink sink(sink_contents, Operator::Add());

	settings.add_node(constant_source1);
	settings.add_node(constant_source2);
	settings.add_node(sink);

	// problem is likely with link
	Graph::Node::Node::link(constant_source1, sink);
	Graph::Node::Node::link(constant_source2, sink);

	Graph::DCGraph graph(settings);

	graph.forward();

	std::cout << sink.get_contents()[0] << "\n\n";

	std::cout << &(source_contents1) << " : in 1\n";
	std::cout << &(source_contents2) << " : in 2\n";
	std::cout << &(sink_contents) << " : out 1\n";

	return 0;
}
