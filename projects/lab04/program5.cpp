#include <iostream>
#include <iomanip>

int main () {
    int sum = 0;

    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            for (int j = 1; j <= 5; j++) {
                sum += (i * j);
            }
        }
        else {
            for (int j = (10 - i); j >= 5; j--){
                sum += (i * j);
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;

}