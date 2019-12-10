class Person {
    public:
        std::string name;
        int age;
        std::string favorite_color;
        std::string birthday;

        Person(std::string this_name);

        std::string get_name();
        int get_age();
        std::string get_color();
        std::string get_birthday();

        void set_name(std::string this_name);
        void set_age(int this_age);
        void set_color(std::string this_color);
        void set_birthday(std::string this_birthday);
}

class Student : public Person {
    private:
        int student_id;
    public:
}