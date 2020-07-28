//
// Created by Carson Fricke on 7/27/2020 9:49pm PST
//

#ifndef __HOSTDEVICE_H__
#define __HOSTDEVICE_H__

#include "Device.h"

namespace Tensor {

	namespace Device {
		
		class HostDevice : public Device {
			
			public:

				inline void alloc_to_device(void* allocatee, size_t size) override;

		};


	} // namespace Tensor::Device

} // namespace Tensor


#endif // end guards