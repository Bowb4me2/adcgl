//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#ifndef __SOURCE_H__
#define __SOURCE_H__

#include "..\Node.h"

namespace Graph {

	namespace Node {

		class Source : public Node {

			protected:

			public:

				Source(Tensor::Tensor<float>& contents);

				void init_input() override;

				void init_grad() override;

				void add_input(Tensor::Tensor<float>& input) override;

				void add_grad(Tensor::Tensor<float>& grad) override;

				void forward() override;

				void backward() override;

		}; // class Source

	} // namespace Graph::Node

} // namespace Graph

#endif // end guards