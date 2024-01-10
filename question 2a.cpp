#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Product {
public:
    int id;
    string name;

    Product(int id, string name) : id(id), name(name) {}

    bool operator==(const Product& p) const {
        return id == p.id;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(int id, string name) {
        products.push_back(Product(id, name));
    }

    void removeProduct(int id) {
        products.erase(
            remove_if(products.begin(), products.end(), [id](const Product& product) {
                return product.id == id;
                }),
            products.end()
        );
    }

    void displayProducts() {
        for (const auto& product : products) {
            cout << "Product ID: " << product.id << " - " << product.name << endl;
        }
    }
};

int main() {
    Inventory inventory;

    inventory.addProduct(1, "Laptop");
    inventory.addProduct(2, "Smartphone");
    inventory.removeProduct(1); 

    inventory.displayProducts();  
    return 0;
}
