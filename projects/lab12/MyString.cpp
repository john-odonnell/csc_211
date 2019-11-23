#include "MyString.h"
#include <iostream>

// Constructors
MyString::MyString() {
    this->length = 0;
    this->capacity = 1;
    this->array = new char[this->capacity] {0};
}

MyString::MyString(const char *c) {
    this->length = 0;
    while (c[this->length]) {
        this->length++;
    }
    this->capacity = this->length + 1;
    this->array = new char[this->capacity] {0};

    for (int i = 0; i < this->length; i++) {
        this->array[i] = c[i];
    }
}

MyString::~MyString() {
    delete [] this->array;
}

bool MyString::in_range(int idx) {
    if (idx < this->length) {
        return true;
    }
    else { 
        return false;
    }
}

bool MyString::str_comp(int idx, const char *str) {
    for(int j = 0; str[j]; j++) {
        if (idx + j > this->length) return 0;
        if (this->array[idx + j] != str[j]) return 0;
    }
    return 1;
}

void MyString::print() {
    for (int i = 0; i < this->length; i++) {
        std::cout << this->array[i];
    }
    std::cout << std::endl;
}

unsigned int MyString::len() {
    return this->length;
}

void MyString::set(int idx, char c) {
    if (MyString::in_range(idx)) {
        this->array[idx] = c;
    }
    else {
        std::cout << "Index not in range." << std::endl;
    }
}

char MyString::get(int idx) {
    if (this->in_range(idx)) {
        return this->array[idx];
    }
    else {
        return '-';
    }
}

void MyString::del(int idx) {
    if (MyString::in_range(idx)) {
        for (int i = idx; i < this->length - 1; i++) {
            this->array[i] = this->array[i+1];
        }
        this->length--;
    }
}

const char *MyString::c_str(int idx, int jdx) {
    return array;
}

void MyString::reverse() {
    for (int i = 0; i < this->length / 2; i++) {
        char temp = array[length-i];
        array[length-i] = array[i];
        array[i] = temp;
    }
}

int MyString::find_first(char c) {
    for (int i = 0; i < this->length; i++) {
        if (this->array[i] == c) return i;
    }
    return -1;
}

int MyString::find_first(const char *str) {
    for (int i = 0; i <= this->length; i++) {
        if (this->str_comp(i, str)) return i;
    }
    return -1;
}

int MyString::find_last(char c) {
    for (int i = this->length; i >= 0; i--) {
        if (this->array[i] == c) return i;
    }
    return -1;
}

int MyString::find_last(const char *str) {
    for (int i = this->length; i >= 0; i--) {
        if (this->str_comp(i, str)) return i;
    }
    return -1;
}

bool MyString::compare(const char *str) {
    return (this->str_comp(0, str));
}

void MyString::append(char c) {
    if (this->length + 1 >= this->capacity) {
        this->capacity *= 2;
    }
    char *temp = new char[capacity];
    
    int idx = 0;
    while (this->array[idx]) {
        temp[idx] = this->array[idx];
        idx++;
    }
    for (int i = idx; i < this->capacity; i++) {
        temp[i] = 0;
    }

    delete [] this->array;
    this->array = temp;
    this->length++;
}

void MyString::append(const char *str) {
    for (int i = 0; str[i]; i++) {
        this->append(str[i]);
    }
}

char MyString::operator[](const unsigned int idx) const {

}

