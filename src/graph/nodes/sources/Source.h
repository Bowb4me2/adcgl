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

				Tensor::Tensor<float> forward() override;

				Tensor::Tensor<float> backward() override;

		}; // class Source

	} // namespace Graph::Node

} // namespace Graph

#endif // end guards