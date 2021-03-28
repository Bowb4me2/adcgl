//
// Created by Carson Fricke on 1/30/2021 10:26pm PST
//



#ifndef __SWING_EXCEPTION_H__
#define __SWING_EXCEPTION_H__

#include <string>

namespace swing {

	static void swing_assert(bool condition, std::string err_msg) {
	
		if (!condition) {
			std::cout << "Assertion failed: " << err_msg << std::endl;

			throw err_msg;
		}
	
	}



} // namespace swing


#endif // end guards