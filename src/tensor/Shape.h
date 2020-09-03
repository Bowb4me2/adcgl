//
// Created by Carson Fricke on 5/17/2020 6:27pm PST
//

#ifndef __TENSOR_SHAPE_H__
#define __TENSOR_SHAPE_H__


namespace Tensor {

	struct Shape {


		// fields
		size_t size;
			 
		size_t* shape;

		size_t dims;			

		// methods
		bool is_equal(Shape shape);

		size_t& operator[](int index);

		// default contructor
		Shape();

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

		bool is_brodcastable(Shape shape);

		//template<size_t N>
		//void reshape(const unsigned int(&shape)[N]) {
		//
		//}

		void reshape(Shape shape);

		static Shape concatenate(Shape arg0, Shape arg1);


	}; // class Tensor::Shape

} // namespace Tensor

#endif // end guards