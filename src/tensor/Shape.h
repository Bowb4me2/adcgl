//
// Created by Carson Fricke on 5/17/2020 6:27pm PST
//

#ifndef __SHAPE_H__
#define __SHAPE_H__


namespace Tensor {

	class Shape {
		private:
			
			size_t size;
			 
			unsigned int* shape;

			size_t dims;

			

		public:

			template <typename T>
			friend class Tensor;

			template <typename T>
			friend class HTensor;

			template <typename T>
			friend class DTensor;

			unsigned int& operator[](int index);

			// default contructor
			Shape();

			// contructor with specified size
			Shape(unsigned int size);

			// contructor with psuedo std::intializer_list
			template<size_t N>
			Shape(const unsigned int(&shape)[N])
				: size(1),
				  shape(new unsigned int[N]),
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

			size_t get_size();

			unsigned int* get_shape();

			size_t get_dims();

	}; // class Tensor::Shape

} // namespace Tensor

#endif // end guards