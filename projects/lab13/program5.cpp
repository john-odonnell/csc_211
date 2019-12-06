#include <string>
#include <sstream>
#include <iostream>
#include <vector>

void VectorsByReference(std::string input, std::vector<int>* int_vector, std::vector<std::string>* str_vector);

int main() {
	std::string input = "5-apple-15-mango-25-pineapple";

	std::vector<int> int_vector;
	std::vector<std::string> str_vector;

	//Call the function here
	VectorsByReference(input, int_vector, str_vector)

	for (int i = 0; i < int_vector.size(); i++) {
		std::cout << int_vector[i] << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < str_vector.size(); i++) {
		std::cout << str_vector[i] << " ";
	}
	std::cout << "\n";
}

void VectorsByReference(std::string input, std::vector<int>* int_vector, std::vector<std::string>* str_vector) {
	// Apart from the single line where you call this function in main, this should be the only place you add code!
}