#include "Product.h"

using namespace std;

Product::Product(string id, string name, int quantity, double price)
    : id(id), name(name), quantity(quantity), price(price) {}

string Product::GetID() const { return id; }
string Product::GetName() const { return name; }
int Product::GetQuantity() const { return quantity; }
double Product::GetPrice() const { return price; }
void Product::SetQuantity(int quantity) { this->quantity = quantity; }
void Product::SetPrice(double price) { this->price = price; }

void Product::Display() const {
    cout << "ID: " << id << ", Name: " << name
              << ", Quantity: " << quantity << ", Price: $" << price << '\n';
}

ostream& operator<<(ostream& out, const Product& product) {
    out << product.id << ',' << product.name << ',' << product.quantity << ',' << product.price;
    return out;
}

istream& operator>>(istream& in, Product& product) {
    getline(in, product.id, ',');
    getline(in, product.name, ',');
    in >> product.quantity;
    in.ignore();
    in >> product.price;
    in.ignore();
    return in;
}

