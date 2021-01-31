#include <iostream>

#include <swing.h>

#include <string>


int main() {
	std::cout << "word word \n";

	unsigned int a[5] = { 1, 2, 3, 4, 5 };

	swing::tensor::Tensor<unsigned int> tensor(a);

	swing::tensor::TensorArray<unsigned int> tensor_array;
	tensor_array.push_back(tensor);
	
	std::cout << tensor[2] << " " << tensor_array[0][2] << "\n";

	tensor_array.push_back(tensor);

	tensor_array[0][2] = 6;

	std::cout << tensor[2] << " " << tensor_array[1][2] << "\nArray Size: " << tensor_array.get_size() << "\n";

	tensor_array.clear();

	tensor_array.push_back(tensor);

	std::cout << tensor[2] << " " << tensor_array[0][2] << "\n";

	tensor_array.push_back(tensor);

	tensor_array[0][2] = 6;

	std::cout << tensor[2] << " " << tensor_array[1][2] << "\nArray Size: " << tensor_array.get_size() << "\n";


	std::string in;
	
	std::cin >> in;

	return 0;
}
