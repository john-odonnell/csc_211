#include <iostream>
#include <iomanip>

int suffix_sum(int n, int s) {
    int sum = 0;
    int counter = 0;

    while (counter < s) {
        sum += n;
        n--;
        counter++;
    }

    return sum;
}

int main () {
    int n, s, sum;
    std::cin >> n >> s;

    sum = suffix_sum(n, s);
    std::cout << sum << std::endl;

    return 0;
}