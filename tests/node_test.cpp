#include <iostream>

#include <swing.h>

#include <graph/operator/elementwise/Sub.h>
#include <graph/operator/elementwise/Add.h>
#include <graph/operator/elementwise/Mul.h>

#include <stdlib.h>


int main() {


	swing::graph::GraphBuilder settings;

	scalar_t a1[] = { 2.0f };
	scalar_t a2[] = { 2.0f, 3.0f, 4.0f};
	scalar_t a3[] = { 2.0f, 3.0f, 4.0f};
	scalar_t a4[] = { 0.0f, 0.0f, 0.0f};
	scalar_t a5[] = { 0.0f, 0.0f, 0.0f};


	swing::tensor::Tensor<> source_contents1(    a1);
	swing::tensor::Tensor<> source_contents2(    a2);
	swing::tensor::Tensor<> source_contents3(    a3);
	swing::tensor::Tensor<> placeholder_contents(a4);
	swing::tensor::Tensor<> sink_contents(       a5);

	swing::graph::node::Constant    constant1(   source_contents1);
	swing::graph::node::Constant    constant2(   source_contents2);
	swing::graph::node::Constant    constant3(   source_contents3);
	swing::graph::node::Placeholder placeholder1(placeholder_contents, swing::graph::oper::Mul());
	swing::graph::node::Sink        sink(        sink_contents,        swing::graph::oper::Add());

	settings.add_node(constant1);
	settings.add_node(constant2);
	settings.add_node(constant3);
	settings.add_node(placeholder1);
	settings.add_node(sink);

	swing::graph::node::link(constant1,    placeholder1);
	swing::graph::node::link(constant2,    placeholder1);
	swing::graph::node::link(constant3,    sink);
	swing::graph::node::link(placeholder1, sink);


	swing::graph::DCGraph graph_(settings);

	graph_.forward();

	graph_.reset_visited();

	graph_.backward();

	// remember to remove print statements in graph/operators

	std::cout << sink_contents << "\n\n";


	return 0;

}
