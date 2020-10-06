//
// Created by Carson Fricke on 9/18/2020 11:08am PST
//

#include "Sum.h"

namespace Graph {

	namespace Operator {


		void Sum::get_operation(Tensor::Tensor<scalar_t>& out) {

		}

		void Sum::get_jacobian(Tensor::TensorArray<scalar_t>& out) {

		}

		void Sum::init(Tensor::Shape operation_shape) {

			this->operation_shape = operation_shape;

			this->aggregate_grad = Tensor::Tensor<scalar_t>(operation_shape);

			construct_jacobians();
		}

	}
}