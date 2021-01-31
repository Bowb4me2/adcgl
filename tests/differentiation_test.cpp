#include <iostream>

#include <swing.h>

#include <graph/operator/matrix/Outer.h>

#include <graph/operator/matrix/Dot.h>

#include <graph/operator/loss/MSE.h>

#include <stdlib.h>

#include <stdarg.h>

int main() {

	Graph::GraphBuilder settings;

	swing::tensor::Tensor<> lt1({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 });
	Graph::Node::Constant input_layer(lt1);


	swing::tensor::Shape ws1({ 5, 10 });
	swing::tensor::Tensor<> wt1(ws1);
	Graph::Node::Constant weights(wt1);
	wt1[0].fill(0.1);
	wt1[1].fill(0.2);
	wt1[2].fill(0.3);
	wt1[3].fill(0.4);
	wt1[4].fill(0.5);
	wt1.transpose();
	wt1[3].fill(3);
	wt1.transpose();


	swing::tensor::Shape ls2({ 5 }); 
	swing::tensor::Tensor<> lt2(ls2);
	Graph::Node::Placeholder output_layer(lt2, Graph::Operator::Dot());

	swing::tensor::Shape ls3({ 1 });
	swing::tensor::Tensor<> lt3(ls3);
	Graph::Node::Sink error(lt3, Graph::Operator::MSE());

	swing::tensor::Tensor<> lt4({ 3, 4, 5, 6, 7 });
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


	std::cout << "Input Tensor: "   << lt1 << "\n";
	std::cout << "Weight Tensor: "  << wt1 << "\n";
	std::cout << "Error Tensor: "   << lt3 << "\n";
	std::cout << "Output Tensor: "  << lt2 << "\n";
	std::cout << "Desired Tensor: " << lt4 << "\n";
	

	//// remember to remove print statements in graph/operators
	return 0;
}
