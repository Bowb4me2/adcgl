//
// Created by Carson Fricke on 5/17/2020 6:27pm PST
//

#ifndef __SHAPE_H__
#define __SHAPE_H__


namespace Tensor {

	class Shape {
		
		private:
			
			size_t size;
			 
			size_t* shape;

			size_t dims;			

		public:

			template <typename T/*, int I*/>
			friend class Tensor;

			template <typename T>
			friend class HTensor;

			template <typename T>
			friend class DTensor;

			size_t& operator[](int index);

			// default contructor
			Shape();

			// contructor with specified size
			Shape(size_t size);

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

			static Shape concatenate(Shape arg0, Shape arg1);

			size_t get_size();

			size_t* get_shape();

			size_t get_dims();

	}; // class Tensor::Shape

} // namespace Tensor

#endif // end guards