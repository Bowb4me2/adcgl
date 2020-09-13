#include <iostream>

#include <adcgl.h>

#include <graph/operator/matrix/Outer.h>

#include <stdlib.h>



int main() {


	Graph::GraphBuilder settings;

	scalar_t a1[] = { 2.0f };
	scalar_t a2[] = { 1.0f, 2.0f, 3.0f};

	size_t a3[] = { 3, 3 };
	Tensor::Shape s3(a3);


	Tensor::Tensor<> source_contents1(a1);
	Tensor::Tensor<> source_contents2(a2);
	Tensor::Tensor<> sink_contents(   s3);

	Graph::Node::Constant constant1(source_contents1);
	Graph::Node::Constant constant2(source_contents2);
	Graph::Node::Sink     sink(     sink_contents, Graph::Operator::Outer());

	settings.add_node(constant1);
	settings.add_node(constant2);
	settings.add_node(sink);

	Graph::Node::Node::link(constant1, sink);
	Graph::Node::Node::link(constant2, sink);
	

	Graph::DCGraph graph(settings);

	graph.forward();

	graph.reset_visited();

	graph.backward();

	// remember to remove print statements in graph/operators

	std::cout << "Output Shape: " << sink_contents.get_shape() << "\n";
	std::cout << "Output Tensor: " << sink_contents << "\n";

	return 0;

}
