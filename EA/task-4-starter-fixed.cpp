#include <string>
#include<iostream>
#include <bits/stdc++.h>
#include <utility>

class Item {
private:
    std::string name;
    int quantity;
    float price;

public:
    Item(
            std::string name,
            int quantity,
            float price
    ) :
            name{std::move(name)},
            quantity{quantity},
            price{price} {

    }

    std::string get_name() const {
        return name;
    }

    int get_quantity() const {
        return quantity;
    }

    void set_quantity(int new_quantity) {
        quantity = new_quantity;
    }

    float get_price() const {
        return price;
    }

    bool is_match(const std::string &other) {
        return name == other;
    }
};

class Inventory {
private:
   // Item *items[20];
   std::vector<Item*>items;
    float total_money;
   // int item_count;

    static void display_data(Item &item) {
        std::cout << "\nItem name: " << item.get_name();
        std::cout << "\nQuantity: " << item.get_quantity();
        std::cout << "\nPrice: " << item.get_price();
    }

public:
    Inventory() :
            //items{},
            total_money{0} {}
        //    item_count{0} {}

    void add_item() {
        std::string name;
        int quantity;
        float price;

        std::cin.ignore();
        std::cout << "\nEnter item name: ";
        std::cin >> name;
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        std::cout << "Enter price: ";
        std::cin >> price;

        // items[item_count] = new Item(name, quantity, price);
        // item_count++;
        items.push_back(new Item(name, quantity, price));
    }

    void sell_item() {
        if(items.empty()){
            std::cout<<"Inventory is empty!\n";
            return;
        }
        std::string item_to_check;
        std::cin.ignore();
        std::cout << "\nEnter item name: ";
        std::cin >> item_to_check;
        
     // for (int i = 0; i < item_count; i++) {
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i]->is_match(item_to_check)) {
                remove_item(i);
                return;
            }
        }
        std::cout << "\nThis item is not in your Inventory";
    }

    void remove_item(int item_index) {
        int input_quantity;
        Item *item = items[item_index];
        std::cout << "\nEnter number of items to sell: ";
        std::cin >> input_quantity;

        int quantity = item->get_quantity();
        if (input_quantity <= quantity) {
            float price = item->get_price();
            float money_earned = price * input_quantity;

            // if(input_quantity == quantity){ // checking if the available quantity of the product == quatity which the user wants to sell
            //     delete items[item_index];   // if matches freeing the memory by deleteing 
            //     for(int ea=item_index; ea<item_count-1; ea++){ // shifting to the left to cover
            //         items[ea]=items[ea+1];
            //     }
            //     items[item_count-1]=nullptr;  // clear last pointer
            //     item_count--;                 // updating items count
            //     std::cout<<"Item sold out and removed from the inventory\n";
            // }else{
            //     item->set_quantity(quantity - input_quantity);  // else, normal flow!
            //     std::cout<<"Item sold!\n";
            // }

            if(input_quantity==quantity){
                delete items[item_index];
                items.erase(items.begin()+item_index);
                std::cout<<"Item sold out and removed from the inventory\n";
            }else{
                item->set_quantity(quantity - input_quantity);  
                std::cout<<"Item sold!\n";
            }
            
            std::cout << "\nMoney received: " << money_earned;
            total_money += money_earned;
        } else {
            std::cout << "\nCannot sell more items than you have.";
        }
    }

    void list_items() {
     // if (item_count == 0) {
        if (items.empty()) {
            std::cout << "\nInventory empty.";
            return;
        }

        // for (int i = 0; i < item_count; i++) {
        //     display_data(*items[i]);
        //     std::cout << "\n";
        // }
        for(Item* ea:items){
            display_data(*ea);
            std::cout<<"\n";
        }
    }

    ~Inventory(){
        for(Item* i:items){
            delete i;
        }
    }
};

// no need to modify anything here
int main() {
    int choice;
    Inventory inventory_system;
    std::cout << "Welcome to the inventory!";

    while (1) {
        std::cout << "\n\nMENU\n"
                  << "1. Add new item\n"
                  << "2. Sell item\n"
                  << "3. List items\n"
                  << "4. Exit\n\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                inventory_system.add_item();
                break;

            case 2:
                inventory_system.sell_item();
                break;

            case 3:
                inventory_system.list_items();
                break;

            case 4:
                exit(0);

            default:
                std::cout << "\nInvalid choice entered";
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                break;
        }
    }
}
