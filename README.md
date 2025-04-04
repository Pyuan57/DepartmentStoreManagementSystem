# Department Store Management System

## Introduction
The **Department Store Management System** is designed to modernize inventory control for small businesses. Traditional inventory systems, reliant on manual tracking, often suffer from inefficiencies, human errors, and inconsistent records. This system utilizes **data structures** and **algorithms** (including **linked lists** and **hash tables**) to manage product inventory effectively. Key features include adding, editing, and deleting products, sorting and searching products by price, and real-time inventory updates.

The system ensures:
- **Efficient operations**: Through the use of selection sort and hash tables for fast searching and sorting.
- **File-based secure storage**: For safe and consistent management of inventory data.
- **User-friendly interface**: Designed for small business owners to manage their stores with ease.

## Problem Statement
Small businesses often face challenges with traditional inventory management systems due to:
- **Human errors** in manual record-keeping.
- **Inefficient updates**: Delays in tracking stock levels and product details.
- **Lack of sorting and searching**: Making it difficult to find specific products or analyze inventory.
- **Data loss risks**: Reliance on physical or unprotected digital records.

This system solves these problems by:
- Providing **centralized** and **real-time inventory tracking**.
- Allowing **efficient searching and sorting** by product prices.
- Ensuring **data integrity** with a secure file-based storage system.

## Objectives
The **Department Store Management System** aims to:
1. Provide a **centralized inventory system** for easy management and tracking of product information.
2. Enable **efficient searching and sorting** of products by price, improving inventory analysis.
3. **Minimize data loss risks** by utilizing a secure file-based storage solution.
4. **Reduce human errors** by automating tasks like inventory updates and product additions/removals.
5. Offer an **intuitive user interface** for store employees and managers.

## Implementation Details

### Data Structures

#### 1. Linked List
A **Linked List** is used to store product details dynamically. Each product is represented by a node containing product data (ID, name, price, quantity), and a pointer to the next product in the sequence.

**Supported Operations:**
- **Add**: Insert new products at the head of the list.
- **Remove**: Delete products by ID.
- **Find**: Search for products by ID.
- **Sort by Price**: Sort products based on price using **selection sort**.
- **Display**: Display all products in the list.

**Why Linked List?**
- **Dynamic Size**: Easily grows or shrinks as products are added or removed.
- **Efficient Insert/Remove**: Add or delete products without rearranging other elements.
- **Sequential Access**: Ideal for displaying or sorting products.

#### 2. Hash Table
A **Hash Table** is used for quick product searches. It maps product IDs to product objects using a hash function.

**Supported Operations:**
- **Insert**: Add products by computing the hash for the product ID.
- **Remove**: Delete a product based on its ID.
- **Search**: Find products quickly using their ID.

**Why Hash Table?**
- **Fast Search/Update/Deletion**: Constant time complexity for these operations.
- **Efficient Organization**: Products are distributed across buckets for quick access.
- **Collision Handling**: Handles multiple products with the same ID by chaining them in linked lists.

### Algorithms

#### Selection Sort
**Selection Sort** is used to sort products by price. It works by repeatedly selecting the smallest (or largest) element from the unsorted part of the list and swapping it with the first unsorted element.

**Why Selection Sort?**
- **Simple to Implement**: Ideal for small datasets and direct sorting in a linked list.
- **In-place Sorting**: No additional space is required beyond the list itself.

## Features
- **Add Product**: Add new products to inventory with details like ID, name, price, and quantity.
- **Edit Product**: Update product details such as price and quantity.
- **Remove Product**: Delete products from the inventory by ID.
- **Search Product**: Quickly search for products by their unique ID.
- **Sort by Price**: Sort products in ascending order of price using the **selection sort algorithm**.
- **Display All Products**: View all products in the inventory, neatly formatted.

## Requirements
- C++ compiler (e.g., GCC)
- Basic understanding of data structures and algorithms

## How to Run
1. Clone or download the repository.
2. Open the project in your C++ IDE or editor.
3. Compile the program and run it.
4. Use the interactive menu to manage the inventory.

## Future Enhancements
- Implement additional sorting algorithms (e.g., quicksort).
- Add a graphical user interface (GUI) for better interaction.
- Integrate with a database for larger-scale inventory management.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

