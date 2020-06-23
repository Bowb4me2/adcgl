//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#ifndef __SINK_H__
#define __SINK_H__

#include "..\Node.h"

namespace Graph {

	namespace Node {

		class Sink : public Node {

			protected:

			public:

				Tensor::Tensor<float> forward() override;

				Tensor::Tensor<float> backward() override;

		}; // class Sink

	} // namespace Graph::Node

} // namespace Graph

#endif // end guards