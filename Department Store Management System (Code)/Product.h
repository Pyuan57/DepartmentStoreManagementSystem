#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

class Product {
private:
    string id;
    string name;
    int quantity;
    double price;

public:
    Product(string id = "", string name = "", int quantity = 0, double price = 0.0);

    string GetID() const;
    string GetName() const;
    int GetQuantity() const;
    double GetPrice() const;
    void SetQuantity(int quantity);
    void SetPrice(double price);

    // Display
    void Display() const;

    // Overload << for saving to file
    friend ostream& operator<<(ostream& out, const Product& product);
    friend istream& operator>>(istream& in, Product& product);
};

#endif
