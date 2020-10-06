//
// Created by Carson Fricke on 7/26/2020 12:45pm PST
//


#ifndef __TENSOR_DEVICE_DEVICE_H__
#define __TENSOR_DEVICE_DEVICE_H__

namespace Tensor {

	namespace Device {
		
		class Device {

			public:

				virtual inline void alloc_to_device(void* allocatee, size_t size) = 0;

		}; // class Tensor::Device::Device

	} // namespace Tensor::Device

} // namespace Tensor

#endif // end guards