#include <iostream>
#include <map>
using namespace std;

class Payment{
public:
    virtual void Pay() = 0;
};

class Cash : public Payment{
public:
    void Pay() {
        cout << "Cash" << endl;
    }
};

class Product{
private:
    string name;
    int price;
    int amount;

public:
    Product(const string& name, int price, int amount) : name(name), price(price), amount(amount) {}

    string GetName(){
        return name;
    }

    int GetPrice(){
        return price;
    }

    int GetAmount(){
        return amount;
    }

    void SetAmount(int newAmount){
        amount = newAmount;
    }
};

class VendingMachine {
private:
    float money;
    map<int, Product*> products;

public:
    void Pay(Payment* payment){
        payment->Pay();
    }

    void AddProduct(Product* product){
        products[products.size() + 1] = product;
    }

    void RemoveProduct(int index){
        auto it = products.find(index);

        if (it != products.end()){
            delete it->second;
            products.erase(it);
        }
        else{
            cout << "there is no product with given index"<<endl;
        }
    }

    void ShowProducts(){
        for (auto itr = products.begin(); itr != products.end(); ++itr){
            cout << itr->first<<
                 '\t' << "name: " << itr->second->GetName() <<
                 '\t' << "price: " << itr->second->GetPrice() <<
                 '\t' << "amount: " << itr->second->GetAmount() << '\n';
        }
    }

    int GetProductCount(){
        return products.size();
    }

    Product* GetProduct(int index){
        auto it = products.find(index);
        return it->second;
    }
};
class User{
private:
    float money;

public:
    User(float money) : money(money) {}


    float GetMoney() const{
        return money;
    }

    void BuyProduct(VendingMachine& vendingMachine, int productIndex){
        if (productIndex > 0 && productIndex <= vendingMachine.GetProductCount()){
            Product* selectedProduct = vendingMachine.GetProduct(productIndex);
            if (selectedProduct->GetPrice() <= money && selectedProduct->GetAmount() > 0){
                cout << "Buying " << selectedProduct->GetName() << " for " << selectedProduct->GetPrice() <<"$"<< endl;
                money -= selectedProduct->GetPrice();
                selectedProduct->SetAmount(selectedProduct->GetAmount()-1);
            }
            else {
                cout << "user dont have enough money or there is no product" << endl;
            }
        } 
        else {
            cout << "there is no product with given index" << endl;
        }
    }
};

int main() {
    //testing functions manually
    
    VendingMachine vendingMachine;

    Product* product1 = new Product("Soda", 2, 10);
    Product* product2 = new Product("Chips", 1, 15);


    vendingMachine.AddProduct(product1);
    vendingMachine.AddProduct(product2);


    cout << "================================"<< endl;
    vendingMachine.ShowProducts();

    User user(5);
    
    cout << "user have: "<< user.GetMoney()<< "$"<<endl;
    
    user.BuyProduct(vendingMachine, 1);

    cout << "================================"<< endl;
    vendingMachine.ShowProducts();
    cout << "user have: "<< user.GetMoney()<< "$"<<endl;
        
    cout << "================================"<< endl;

    user.BuyProduct(vendingMachine, 4);
    
    vendingMachine.RemoveProduct(4);
    
    delete product1;
    delete product2;

    return 0;
}
