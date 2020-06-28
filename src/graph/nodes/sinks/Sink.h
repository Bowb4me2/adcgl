//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#ifndef __SINK_H__
#define __SINK_H__

#include "..\Node.h"
#include "..\..\..\operators\Operator.h"

namespace Graph {

	namespace Node {

		class Sink : public Node {

			protected:

				Operator::Operator& operation;
			public:

				Sink(Tensor::Tensor<float>& contents, Operator::Operator& operation);

				void add_input(Tensor::Tensor<float>& input) override;

				void add_grad(Tensor::Tensor<float>& grad) override;

				void forward() override;

				void backward() override;

		}; // class Sink

	} // namespace Graph::Node

} // namespace Graph

#endif // end guards