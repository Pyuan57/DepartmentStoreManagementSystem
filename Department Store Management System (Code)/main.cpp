#include "Store.h"
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

void ClearConsole() {
    system("cls");
}

void Pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void ShowMenu() {
    cout << "======= Department Store Management System =======\n";
    cout << "| 1. Add Product                                 |\n";
    cout << "| 2. Edit Product                                |\n";
    cout << "| 3. Delete Product                              |\n";
    cout << "| 4. Search Product                              |\n";
    cout << "| 5. Sort Products by Price                      |\n";
    cout << "| 6. Display Products                            |\n";
    cout << "| 7. Save to File                                |\n";
    cout << "| 8. Exit                                        |\n";
    cout << "==================================================\n";
    cout << "Enter your choice: ";
}

int main() {
    Store store;

    // Automatically load products from file on startup
    try {
        store.LoadFromFile("products.txt");
        cout << "Products loaded from file.\n";
    } catch (const exception& e) {
        cout << "Error loading products: " << e.what() << "\n";
    }

    int choice;

    do {
        ShowMenu();
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                string id, name;
                int quantity;
                double price;
                cout << "Enter Product ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Product Name: ";
                getline(cin, name);
                cout << "Enter Product Quantity: ";
                cin >> quantity;
                cout << "Enter Product Price: ";
                cin >> price;
                store.AddProduct(Product(id, name, quantity, price));
                cout << "Product added! Remember to save to file.\n";
                break;
            }
            case 2: {
                cout << "Current products in the store:\n";
                store.DisplayProducts();
                string id;
                int quantity;
                double price;
                cout << "\nEnter Product ID to edit: ";
                cin >> id;
                cout << "Enter New Quantity: ";
                cin >> quantity;
                cout << "Enter New Price: ";
                cin >> price;
                store.EditProduct(id, quantity, price);
                cout << "Product edited! Remember to save to file.\n";
                break;
            }
            case 3: {
                cout << "Current products in the store:\n";
                store.DisplayProducts();
                string id;
                cout << "\nEnter Product ID to delete: ";
                cin >> id;
                store.DeleteProduct(id);
                cout << "Product deleted! Remember to save to file.\n";
                break;
            }
            case 4: {
                string id;
                cout << "Enter Product ID to search: ";
                cin >> id;
                Product* product = store.SearchProduct(id);
                if (product) {
                    product->Display();
                } else {
                    cout << "Product not found.\n";
                }
                break;
            }
            case 5:
                store.SortProductsByPrice();
                cout << "Products sorted by price.\n";
                break;
            case 6:
                store.DisplayProducts();
                break;
            case 7:
                store.SaveToFile("products.txt");
                cout << "Products saved to file.\n";
                break;
            case 8:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << '\n';
        }

        if (choice != 8) {
            Pause();
            ClearConsole();
        }
    } while (choice != 8);

    return 0;
}
