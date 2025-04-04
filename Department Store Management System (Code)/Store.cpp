#include "Store.h"
#include <iomanip>
using namespace std;

// LinkedList Implementation
LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::Add(const Product& product) {
    Node* newNode = new Node(product);
    newNode->next = head;
    head = newNode;
}

void LinkedList::Remove(const string& id) {
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->product.GetID() == id) {
            // If it's the head node
            if (!prev) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;  // Free memory
            return;          // Exit after deleting
        }
        prev = current;
        current = current->next;
    }
}

Node* LinkedList::Find(const string& id) {
    Node* current = head;
    while (current) {
        if (current->product.GetID() == id) return current;
        current = current->next;
    }
    throw Store::ProductNotFoundException();
}

// Selection Sort algorithm
void LinkedList::SortByPrice() {
    if (!head || !head->next) return; // Empty or single node list

    for (Node* i = head; i && i->next; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->product.GetPrice() < minNode->product.GetPrice()) {
                minNode = j;
            }
        }
        if (minNode != i) {
            swap(i->product, minNode->product); // Swap product data
        }
    }
}

void LinkedList::Display() const {
    // Set column headers
    cout << left << setw(12) << "Product ID"
         << setw(40) << "Product Name"
         << setw(12) << "Quantity"
         << setw(12) << "Price" << endl;

    // Print a line separator
    cout << setfill('-') << setw(12) << ""
         << setw(40) << ""
         << setw(12) << ""
         << setw(12) << "" << endl;
    cout << setfill(' ');  // Reset fill character back to space

    Node* current = head;
    while (current) {
        cout << left << setw(12) << current->product.GetID()
             << setw(40) << current->product.GetName()
             << setw(12) << current->product.GetQuantity()
             << setw(12) << fixed << setprecision(2) << current->product.GetPrice() << endl;
        current = current->next;
    }
}

// HashTable Implementation
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode* current = table[i];
        while (current) {
            HashNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

int HashTable::HashFunction(const string& key) const {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % TABLE_SIZE;
    }
    return hash;
}

void HashTable::Insert(const string& key, const Product& product) {
    int index = HashFunction(key);
    HashNode* newNode = new HashNode(key, product);
    newNode->next = table[index];
    table[index] = newNode;
}

void HashTable::Remove(const string& key) {
    int index = HashFunction(key);
    HashNode* current = table[index];
    HashNode* prev = nullptr;
    while (current) {
        if (current->key == key) {
            if (prev) prev->next = current->next;
            else table[index] = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    throw Store::ProductNotFoundException();
}

Product* HashTable::Search(const string& key) {
    int index = HashFunction(key);
    HashNode* current = table[index];
    while (current) {
        if (current->key == key) return &current->product;
        current = current->next;
    }
    throw Store::ProductNotFoundException();
}

// Store Implementation
Store::Store() {}

void Store::AddProduct(const Product& product) {
    products.Add(product);
    productMap.Insert(product.GetID(), product);
}

void Store::EditProduct(const string& id, int quantity, double price) {
    Product* product = productMap.Search(id);
    product->SetQuantity(quantity);
    product->SetPrice(price);

    Node* node = products.Find(id);
    node->product.SetQuantity(quantity);
    node->product.SetPrice(price);
}

void Store::DeleteProduct(const string& id) {
    productMap.Remove(id);
    products.Remove(id);
}

Product* Store::SearchProduct(const string& id) {
    return productMap.Search(id);
}

void Store::SortProductsByPrice() {
    products.SortByPrice();
}

void Store::DisplayProducts() const {
    products.Display();
}

void Store::SaveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for saving.\n";
        return;
    }
    Node* current = products.GetHead();
    while (current) {
        file << current->product << '\n';
        current = current->next;
    }
    file.close();
}

void Store::LoadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for loading.\n";
        return;
    }
    Product product;
    while (file >> product) {
        AddProduct(product);
    }
    file.close();
}
