#ifndef __mystring_h__
#define __mystring_h__

class MyString {
    private:
        // declare all you data members here
        unsigned int length;
        unsigned int capacity;
        char *array;

        bool in_range(int idx);
        bool str_comp(int idx, const char *str);

    public:
        // constructors and destructor
        // Store an empty string
        MyString();
        // Copy the contents of input into the class' data
        MyString(const char *c);
        // Deallocate any dynamically stored memory
        ~MyString();

        // other functions
        // print the string
        void print();
        // return length of string
        unsigned int len();
        // change a character in the string
        void set(int idx, char c);
        // return a character in the string
        char get(int idx);
        // delete a character in the string
        void del(int idx);

        // return a substring
        const char *c_str(int idx, int jdx);

        // Reverse the string. "hello" should turn into "olleh". 
        // If you would like a challenge try to do it in-place (cannot create another array).
        void reverse();
            
        // Find the first occurrence of this character, and return the index. 
        // Return `-1` if it can't be found.
        int find_first(char c);
            
        // Find the first occurrence of the input string. 
        // Return the index of the starting character. 
        // Return the `-1` if it can't be found.
        int find_first(const char *str);
            
        // Find the last occurrence of this character, and return the index. 
        // Return the `-1` if it can't be found.
        int find_last(char c);
            
        // Find the last occurrence of the input string. 
        // Return the index of the starting character.             // Return the `-1` if it can't be found.
        int find_last(const char *str);
            
        // Return true if the str stored is equivalent to the given string
        // Return false if they are not the same
        bool compare(const char *str);
            
        // Append a single character onto the end of the string.
        void append(char c);
            
        // Concatenate the input string to the object's string.
        void append(const char *);
        
        //Overload the '[]' operator to fuction as we expect
        // Ex. MyString("Hello")[2] == 'l'
        char operator[](const unsigned int index) const;
        
        // Overload the '+' operator to concatenate two strings together
        MyString operator+(const MyString str2) const;
            
        // Overload the '*' operator to return the string concatenated on itself x times
        // Ex. "Hello" * 3 == "HelloHelloHello"
        MyString operator*(const int x) const;

};

#endif