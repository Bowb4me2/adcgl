//
// Created by Carson Fricke on 5/17/2020 6:27pm PST
//

#include <iostream>

#ifndef __TENSOR_SHAPE_H__
#define __TENSOR_SHAPE_H__


namespace Tensor {

	struct Shape {


		// fields
		size_t size;
			 
		size_t* shape;

		size_t dims;			

		// operator overloads
		friend std::ostream& operator<<(std::ostream& os, const Shape& shape);

		// methods
		bool is_equal(Shape shape);

		size_t& operator[](int index);

		// default contructor
		Shape();

		// copy constructor
		Shape(Shape& shape);

		// contructor with specified size
		Shape(size_t size);

		// contructor with psuedo std::intializer_list
		template<size_t N>
		Shape(const size_t(&shape)[N])
			: size(1),
			  shape(new size_t[N]),
			  dims(N) {

			for (size_t i = 0; i < N; i++) {
				this->size *= shape[i];

				this->shape[i] = shape[i];
			}
		}

		Shape(size_t* shape, size_t dims);

		bool is_brodcastable(Shape shape);

		//template<size_t N>
		//void reshape(const unsigned int(&shape)[N]) {
		//
		//}

		void reshape(Shape shape);

		void collapse(size_t mac_collapseable);

		void collapse_left();

		void collapse_right();

		static Shape concatenate(Shape arg0, Shape arg1);


	}; // class Tensor::Shape

} // namespace Tensor

#endif // end guards