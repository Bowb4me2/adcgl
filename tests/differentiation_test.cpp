#include <iostream>

#include <adcgl.h>

#include <graph/operator/matrix/Outer.h>

#include <graph/operator/matrix/Dot.h>

#include <graph/operator/loss/MSE.h>

#include <stdlib.h>


int main() {

	Graph::GraphBuilder settings;

	scalar_t la1[] = { -1, 1, 0.1, 1, 1, 1, 1, 0.3, 1, 1 };
	Tensor::Tensor<> lt1(la1);
	Graph::Node::Constant input_layer(lt1);

	size_t wa1[] = { 5, 10 };
	Tensor::Shape ws1(wa1);
	Tensor::Tensor<> wt1(ws1);
	wt1.fill(1);
	Graph::Node::Constant weights(wt1);

	std::cout << wt1 << "\n" << wt1[1][1][0] << "\n";

	size_t la2[] = { 5 };
	Tensor::Shape ls2(la2);
	Tensor::Tensor<> lt2(ls2);
	Graph::Node::Placeholder output_layer(lt2, Graph::Operator::Dot());

	size_t la3[] = { 1 };
	Tensor::Shape ls3(la3);
	Tensor::Tensor<> lt3(ls3);
	Graph::Node::Sink error(lt3, Graph::Operator::MSE());

	scalar_t la4[] = { 1, 1, 1, 1, 1 };
	Tensor::Tensor<> lt4(la4);
	Graph::Node::Constant desired(lt4);


	settings.add_node(input_layer);
	settings.add_node(output_layer);
	settings.add_node(weights);
	settings.add_node(error);
	settings.add_node(desired);


	Graph::Node::link(input_layer,  output_layer);
	Graph::Node::link(weights,      output_layer);
	Graph::Node::link(output_layer, error);
	Graph::Node::link(desired,      error);

	Graph::DCGraph graph(settings);

	graph.forward();

	graph.reset_visited();

	graph.backward();

	std::cout << "Error Tensor: " << lt3 << "\n";

	std::cout << "Output Tensor: " << lt2 << "\n";

	//// remember to remove print statements in graph/operators

	//std::cout << "Weights Tensor: " << wt1[1] << "\n";

	//std::cout << "Output Tensor: " << sink_contents << "\n";

	return 0;

}
