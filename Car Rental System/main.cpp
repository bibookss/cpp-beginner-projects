#include <iostream>

using namespace std;

struct Customer {
    int customerID;
    string name;
    int age;
    int balance;
    string accUsername;
    string accPassword;
};

struct Admin {
    string name;
    string adminUsername = "admin";
    string adminPassword = "1234";
};

struct Car {
    int carID;
    string name;
    string brand;
    string color;
    int ratePerKm;
};

// Customer Side
void customerRegister(Customer);
void customerLogin(Customer);
void customerForgot(Customer);
void customerRent(Customer, Car);

// Admin Side
void addCar(Car);
void deleteCar(Car);
void adminLogin(Admin);
void adminChangeCredentials(Admin);

// Car Side
void carRate(Car);
