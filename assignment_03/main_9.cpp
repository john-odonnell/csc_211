#include <iostream>
#include <iomanip>
#include <string>

unsigned int str_length(std::string str) {
    unsigned int counter = 0;
    while(str[counter]) {
        counter++;
    }
    return counter;
}

bool same_gmail(std::string firstEmail, std::string secondEmail) {
    unsigned int firstLength = str_length(firstEmail);
    unsigned int secondLength = str_length(secondEmail);

    int i = 0;
    int j = 0;

    bool same = true;

    while ((i < firstLength) and (j < secondLength) and (same)) {
        if (firstEmail[i] == '.') {
            i++;
        }
        else if (secondEmail[j] == '.') {
            j++;
        }
        else if (firstEmail[i] == '+') {
            bool negated = true;
            while (negated) {
                i++;
                if (firstEmail[i] == '@') {
                    negated = false;
                }
            }
        }
        else if (secondEmail[j] == '+') {
            bool negated = true;
            while (negated) {
                j++;
                if (secondEmail[j] == '@') {
                    negated = false;
                }
            }
        }
        else if (toupper(firstEmail[i]) != toupper(secondEmail[j])) {
            same = false;
        }
        else {
            i++;
            j++;
        }
    }

    return same;
}

int main() {
    std::string firstEmail, secondEmail;
    std::cin >> firstEmail >> secondEmail;

    // bool validFirst = checkValid(firstEmail);
    // bool validSecond = checkValid(secondEmail);

    bool same = same_gmail(firstEmail, secondEmail);

    if (same) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    return 0;
}

// WORKS