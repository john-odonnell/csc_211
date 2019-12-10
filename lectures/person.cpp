#include "person.h"

Person::Person(std::string this_name, int this_age, std::string this_color, std::string this_birthday)) {
    name = this_name;
    age = this_age;
    favorite_color = this_color;
    birthday = this_birthdy;
}

std::string Person::get_name() {
    return name;
}
int Person::get_age() {
    return age;
}
std::string Person::get_color() {
    return favorite_color;
}
std::string Person::get_birthday() {
    return birthday;
}

void Person::set_name(std::string this_name) {
    name = this_name;
}
void Person::set_age(int this_age) {
    age = this_age;
}
void Person::set_color(std::string this_color) {
    favorite_color = this_color;
}
void Person::set_birthday(std::string this_birthday) {
    birthday = this_birthday;
}