//
// Created by Carson Fricke on 6/21/2020 2:38pm PST
//

#include "Constant.h"


namespace swing {

	namespace graph {

		namespace node {

			Constant::Constant(tensor::Tensor<scalar_t>& contents)
				: Source(contents) {

			}


		} // namespace swing::graph::node

	} // namespace swing::graph

} // namespace swing