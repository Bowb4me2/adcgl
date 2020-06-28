#include <iostream>

#include <adcgl.h>

#include <operators/Operator.h>

#include <string>


int main() {

	Graph::GraphBuilder settings;

	float a[] = { 0.1f, 0.2f };

	Tensor::HTensor<float> source_contents(a);

	Tensor::HTensor<float> sink_contents(a);

	Graph::Node::Constant constant_source(source_contents);

	//Graph::Node::Sink sink(sink_contents, );

	return 0;
}
