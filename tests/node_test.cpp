#include <iostream>

#include <adcgl.h>

#include <graph/operator/elementwise/Sub.h>
#include <graph/operator/elementwise/Add.h>
#include <graph/operator/elementwise/Mul.h>

#include <stdlib.h>



int main() {


	Graph::GraphBuilder settings;

	scalar_t a1[] = { 2.0f };
	scalar_t a2[] = { 2.0f, 3.0f, 4.0f};
	scalar_t a3[] = { 2.0f, 3.0f, 4.0f};
	scalar_t a4[] = { 0.0f, 0.0f, 0.0f};
	scalar_t a5[] = { 0.0f, 0.0f, 0.0f};


	Tensor::Tensor<> source_contents1(    a1);
	Tensor::Tensor<> source_contents2(    a2);
	Tensor::Tensor<> source_contents3(    a3);
	Tensor::Tensor<> placeholder_contents(a4);
	Tensor::Tensor<> sink_contents(       a5);

	Graph::Node::Constant    constant1(   source_contents1);
	Graph::Node::Constant    constant2(   source_contents2);
	Graph::Node::Constant    constant3(   source_contents3);
	Graph::Node::Placeholder placeholder1(placeholder_contents, Graph::Operator::Mul());
	Graph::Node::Sink        sink(        sink_contents,        Graph::Operator::Add());

	settings.add_node(constant1);
	settings.add_node(constant2);
	settings.add_node(constant3);
	settings.add_node(placeholder1);
	settings.add_node(sink);

	Graph::Node::Node::link(constant1,    placeholder1);
	Graph::Node::Node::link(constant2,    placeholder1);
	Graph::Node::Node::link(constant3,    sink);
	Graph::Node::Node::link(placeholder1, sink);

	

	Graph::DCGraph graph(settings);

	graph.forward();

	graph.reset_visited();

	graph.backward();

	// remember to remove print statements in graph/operators

	std::cout << sink.get_contents()[0] << " " << sink.get_contents()[1] << " " << sink.get_contents()[2] << "\n\n";


	return 0;

}
