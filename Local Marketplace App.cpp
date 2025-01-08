// Include iostream header
#include <iostream>

// Include vector header
#include <vector>

// Include string header
#include <string>

// Include algorithm header
#include <algorithm>

// Start using namespace std
using namespace std;

// Define Product struct
struct Product {
    string name;
    double price;
    string seller;
};

// Declare products vector
vector<Product> products;

// Define addProduct function
void addProduct() {
    string name, seller;
    double price;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter product price: ";
    cin >> price;
    cout << "Enter seller name: ";
    cin.ignore();
    getline(cin, seller);

    products.push_back({name, price, seller});
    cout << "Product added successfully.\n";
}

// Define viewProducts function
void viewProducts() {
    cout << "\n--- Product Listings ---\n";
    for (size_t i = 0; i < products.size(); i++) {
        cout << i + 1 << ". " << products[i].name << " - " 
             << products[i].price << " TZS (Seller: " 
             << products[i].seller << ")\n";
    }
    if (products.empty()) {
        cout << "No products available.\n";
    }
}