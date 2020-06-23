//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#ifndef __PLACEHOLDER_H__
#define __PLACEHOLDER_H__

#include "..\Node.h"

namespace Graph {

	namespace Node {

		class Placeholder : public Node {

			protected:


			public:

				Tensor::Tensor<float> forward() override;

				Tensor::Tensor<float> backward() override;

		}; // class Placeholder

	} // namespace Graph::Node

} // namespace Graph

#endif // end guards