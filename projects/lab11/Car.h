#ifndef __car_h__
#define __car_h__
#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>

class Car {
    private:
        std::string make;
        std::string model;
        std::string color;
        int year;
        double mileage;

    public:
        Car(std::string inMake, std::string inModel, std::string inColor, int inYear) {
            make = inMake;
            model = inModel;
            color = inColor;
            year = inYear;
        }

        void setMake(std::string someMake) {
            make = someMake;
        }
        void setMoel(std::string someModel) {
            model = someModel;
        }
        void setColor(std::string someColor) {
            color = someColor;
        }
        void setYear(int someYear) {
            year = someYear;
        }
        void setMileage(double someMileage) {
            mileage = someMileage;
        }

        std::string getMake() {
            return make;
        }
        std::string getModel() {
            return model;
        }
        std::string getColor() {
            return color;
        }
        int getYear() {
            return year;
        }
        double getMileage() {
            return mileage;
        }

        void printDetails() {
            std::cout << "Make: " << make << std::endl;
            std::cout << "Model: " << model << std::endl;
            std::cout << "Color: " << color << std::endl;
            std::cout << "Year: " << year << std::endl;
            std::cout << "Mileage: " << mileage << std::endl;
        }
};

#endif