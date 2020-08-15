#include <iostream>

#include <adcgl.h>

#include <graph/operator/Sub.h>
#include <graph/operator/Add.h>
#include <graph/operator/Mul.h>

#include <string>


int main() {

	Graph::GraphBuilder settings;

	float a1[] = { 5.2f, 0.2f, 0.3f};
	float a2[] = { 2.4f, 0.9f, 4.3f};
	float a3[] = { 1.1f, 2.7f, 3.2f};
	float a4[] = { 0.0f, 0.0f, 0.0f};
	float a5[] = { 0.0f, 0.0f, 0.0f};


	Tensor::Tensor<float> source_contents1(    a1);
	Tensor::Tensor<float> source_contents2(    a2);
	Tensor::Tensor<float> source_contents3(    a3);
	Tensor::Tensor<float> placeholder_contents(a4);
	Tensor::Tensor<float> sink_contents(       a5);

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
