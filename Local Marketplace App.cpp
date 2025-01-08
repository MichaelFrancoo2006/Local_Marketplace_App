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

// Define updateProduct function
void updateProduct() {
    int index;
    cout << "Enter the product number to update: ";
    cin >> index;

    if (index < 1 || index > products.size()) {
        cout << "Invalid product number.\n";
        return;
    }

    string name, seller;
    double price;
    cout << "Enter new product name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter new product price: ";
    cin >> price;
    cout << "Enter new seller name: ";
    cin.ignore();
    getline(cin, seller);

    products[index - 1] = {name, price, seller};
    cout << "Product updated successfully.\n";
}

// Define deleteProduct function
void deleteProduct() {
    int index;
    cout << "Enter the product number to delete: ";
    cin >> index;

    if (index < 1 || index > products.size()) {
        cout << "Invalid product number.\n";
        return;
    }

    products.erase(products.begin() + index - 1);
    cout << "Product deleted successfully.\n";
}

// Define searchProduct function
void searchProduct() {
    string query;
    cout << "Enter product name to search: ";
    cin.ignore();
    getline(cin, query);

    cout << "\n--- Search Results ---\n";
    bool found = false;
    for (const auto& product : products) {
        if (product.name.find(query) != string::npos) {
            cout << product.name << " - " << product.price << " TZS (Seller: " << product.seller << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No products found matching '" << query << "'.\n";
    }
}

// Define sortProductsByPrice function
void sortProductsByPrice() {
    sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
    });
    cout << "Products sorted by price.\n";
    viewProducts();
}

// Start main function
int main() {
    int choice;
    do {
        cout << "\n--- Local Marketplace ---\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Update Product\n";
        cout << "4. Delete Product\n";
        cout << "5. Search Product\n";
        cout << "6. Sort Products by Price\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Add switch case for menu
        switch (choice) {
        	case 1:
                // Handle add product
                addProduct();
                break;
            case 2:
                // Handle view products
                viewProducts();
                break;
            case 3:
                // Handle update product
                updateProduct();
                break;
            case 4:
                // Handle delete product
                deleteProduct();
                break;
