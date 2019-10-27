#include <iostream>
#include <iomanip>
#include <string>

int unique(std::string inputString) {
    int i = 0;
    int count = 0;
    while (inputString[i]) {
        if (i == 0) {
            count++;
        }
        else {
            int j = i - 1;
            bool preceeded = false;
            while((!preceeded) and (j >= 0)) {
                if (inputString[j] == inputString[i]) {
                    preceeded = true;
                }
                j--;
            }

            if (preceeded == false) {
                count++;
            }
        }

        i++;
    }

    return count;
}

int main() {
    std::string inputString;
    std::getline(std::cin, inputString);

    int number = unique(inputString);

    std::cout << number << std::endl;

    return 0;
}

// WORKS