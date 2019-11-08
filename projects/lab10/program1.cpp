#include <iostream>

bool in_str(std::string str, char character) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == character) {
            return true;
        }
    }
}

void permute_str(std::string current, std::string choices) {
    if (current.length() == choices.length()) {
        std::cout << current << std::endl;
        return;
    }
    else {
        for (int i = 0; i < choices.length(); i++) {
            if (!in_str(current, choices[i])) {
                permute_str(current + choices[i], choices);
            }
        }
    }
}

int main() {
    std::string input;
    std::cin >> input;

    permute_str("", input);

    return 0;
}