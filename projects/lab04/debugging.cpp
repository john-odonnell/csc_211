#include <iostream>
int main(){
    int i = 1;
    while (true) {
        i++;
        if (i == 10) break;
    }
    if(i == 10) std::cout << i << std::endl;
}
