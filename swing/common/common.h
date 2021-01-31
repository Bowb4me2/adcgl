//
// Created by Carson Fricke on 1/18/2021 12:15am PST
//

#include <vector>
#include "RefArray.h"

namespace swing {

	template<typename T>
	using vector_t = std::vector<T>;

	typedef RefArray<int64_t> IntRefArray;

	typedef double scalar_t;

}