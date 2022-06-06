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

// --------------------------------------------------------
// Customer Side
void customerRegister();
int customerCount();
void customerLogin();
void customerForgot(Customer);
void customerRent(Customer, Car);
bool customerCheck(Customer);

// Admin Side
void addCar(Car);
void deleteCar(Car);
void adminLogin(Admin);
void adminChangeCredentials(Admin);

// Car Side
void carRate(Car);
// --------------------------------------------------------

void customerRegister(){
    Customer customer;
    cout << "New Customer Registration\n";
    
    cout << "Enter your name: "; 
    getline(cin, customer.name);
    
    cout << "Enter your age: ";
    cin >> customer.age;

    do{
        cout << "Username: ";
        cin >> customer.accUsername;
        
        cout << "Password: ";
        cin >> customer.accPassword;
    } while(customerCheck(customer));

}
