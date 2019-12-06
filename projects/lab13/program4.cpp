#include <string>
#include <sstream>
#include <iostream>

int SumInts(std::string input) {
	int sum = 0;

    char delimeter = ',';
    std::stringstream this_string(input);
    std::string token;

    while (std::getline(this_string, token, delimeter)) {
        sum += std::stoi(token);
    }

	return sum;
}

int main() {
	std::string my_text = "5,10,15,20,25";

	std::cout << SumInts(my_text) << std::endl;
}