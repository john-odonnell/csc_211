#include "MyString.h"
#include <iostream>

int main() {
    MyString string = MyString("John O'Donnell");

    string.print();
    std::cout << string.len() << std::endl;

    string.set(1, '3');
    string.print();

    char at_3 = string.get(3);
    std::cout << at_3 << std::endl;

    string.del(3);
    string.print();

    return 0;
}