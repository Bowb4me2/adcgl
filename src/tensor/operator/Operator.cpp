//
// Created by Carson Fricke on 8/12/2020 11:26am PST
//

#include "Operator.h"

namespace Tensor {

	namespace Operator {


		void Operator::operator()(Tensor<float>& out, Tensor<float>& arg0, Tensor<float>& arg1) {
			
			validate(out.shape, arg0.shape, arg1.shape);

			if (requires_brodcast(out.shape, arg0.shape, arg1.shape)) {
				
				if (arg0.is_brodcastable(arg1)) {
					
					arg0.brodcast_to_mem(arg1);

					operate(out.iterable, arg0.iterable, arg0.brodcast_iterable, out.shape, arg0.shape, arg1.shape);
				}
				else if (arg1.is_brodcastable(arg0)) {
					
					arg1.brodcast_to_mem(arg0);

					operate(out.iterable, arg1.brodcast_iterable, arg1.iterable, out.shape, arg0.shape, arg1.shape);
				}
			}
			else {

				operate(out.iterable, arg0.iterable, arg1.iterable, out.shape, arg0.shape, arg1.shape);
			}

			
		}

	} // namespace Tensor::Operators

} // namespace Tensor