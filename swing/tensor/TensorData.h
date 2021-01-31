//
// Created by Carson Fricke on 1/25/2021 7:00pm PST
//

#ifndef __TENSOR_TENSORDATA_H__
#define __TENSOR_TENSORDATA_H__

#include "../common/common.h"

namespace swing {

	namespace tensor {

		template<typename T>
		class TensorData {

			private:

				// data
				T* _data;
			
				size_t numel;

			protected:


			public:

				int64_t numel() {
					return _numel;
				}
				
		};

	} // namespace swing::tensor

} // namespace swing

#endif // end guards
