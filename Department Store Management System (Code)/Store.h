#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <fstream>
#include <exception>
#include "Product.h"
using namespace std;

// Linked List Implementation
struct Node {
    Product product;
    Node* next;
    Node(const Product& p) : product(p), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    void Add(const Product& product);
    void Remove(const string& id);
    Node* Find(const string& id);
    void SortByPrice();
    void Display() const;
    Node* GetHead() const { return head; }
};

// Hash Table Implementation
class HashTable {
private:
    static const int TABLE_SIZE = 100;
    struct HashNode {
        string key;
        Product product;
        HashNode* next;
        HashNode(const string& k, const Product& p) : key(k), product(p), next(nullptr) {}
    };
    HashNode* table[TABLE_SIZE];

    int HashFunction(const string& key) const;
public:
    HashTable();
    ~HashTable();
    void Insert(const string& key, const Product& product);
    void Remove(const string& key);
    Product* Search(const string& key);
};

// Store Class
class Store {
private:
    LinkedList products;
    HashTable productMap;

public:
    Store();

    void AddProduct(const Product& product);
    void EditProduct(const string& id, int quantity, double price);
    void DeleteProduct(const string& id);
    Product* SearchProduct(const string& id);
    void SortProductsByPrice();
    void DisplayProducts() const;

    void SaveToFile(const string& filename) const;
    void LoadFromFile(const string& filename);

    class ProductNotFoundException : public exception {
        const char* what() const throw() { return "Product not found!"; }
    };
};

#endif
