// cpp is case sensitive, int != INT
#include <iostream>

int main (int argc, char *argv[]) {     // curly brackets denote blocks of code
                                        // int means that the function returns and integer
    // body
    // all statements end with a semicolon

    int a;
    a = 100;        // identifiers are names given to entities such as data types, objects, references, variables, functions, macros, class members, etc.
    a = a           // identifiers can only use letters, digits, and underscores, but cannot start with a digit
    +               // identifiers can not be reserved words
    111;
                    // a variable is a nameed location in memory
                    // location irrelevant

    // 1 byte = 8 bits
    // basic variable types: void, boolean, integer, floating point, character, string
        // bool: true or false
        // int: has minimum and maximum limit
            // short int (2 bytes) int (4), long int (4), double (8), long double (10)
        // float: min and max, each less than the int min and max
        // char: restricted to one recognized character on the ASCII table (one byte a peice, 256 possible characters)
        // str:

    // website sends a request to a server to send back code, images and whatnot

    return 0;   // ever cpp file needs an main function along with a return 0
                // also known as exit code... 0 means normal, -x means error
                // default return value is 0

}

// the main function is automatically called at program startup
// and is the designated entrypoint to a program that is executed ina hosted enviromnent
    // prototype cannot be modified

    // cannot be used anywhere in the program
    // cannot be overloaded
    // cannot be called recursively

    // its address cannot be taken

// single line comments
/*
multi
line
comments
*/