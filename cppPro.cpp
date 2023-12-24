#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct MenuItem {
    string name;
    double price;
    string category;
};

class FoodMenu {
private:
    vector<MenuItem> menuItems;

public:
    void addItem(const string& name, double price, const string& category) {
        MenuItem item;
        item.name = name;
        item.price = price;
        item.category = category;
        menuItems.push_back(item);
    }

    void displayMenu() {
        cout << "Menu:" << endl;
        string currentCategory = "";
        for (size_t i = 0; i < menuItems.size(); ++i) {
            if (menuItems[i].category != currentCategory) {
                cout << "\n" << menuItems[i].category << ":" << endl;
                currentCategory = menuItems[i].category;
            }
            cout << i + 1 << ". " << menuItems[i].name << " - Rs" << menuItems[i].price << endl;
        }
    }

    double getItemPrice(int index) {
        if (index >= 0 && index < menuItems.size()) {
            return menuItems[index].price;
        }
        return 0.0;
    }

    size_t getItemCount() {
        return menuItems.size();
    }

    string getItemName(int index) {
        if (index >= 0 && index < menuItems.size()) {
            return menuItems[index].name;
        }
        return "Invalid Item";
    }
};

int main() {
    FoodMenu menu;

    // menu item 
    //Burgers

    menu.addItem("Cheese Burst burger", 150, "Burgers");

    menu.addItem("Mini Mayo burger", 150, "Burgers");

    menu.addItem("Paneer Tikka Burger", 150, "Burgers");

    menu.addItem("Veg Tadka Burger", 150, "Burgers");

    menu.addItem("Mini Mayo burger", 150, "Burgers");

    menu.addItem("Paneer Tikka Burger", 150, "Burgers");

    
    //Pizza

    menu.addItem("Deluxe Veg Pizza", 150, "Pizza");

    menu.addItem("Golden Corn Pizza", 150, "Pizza");

    menu.addItem("Panner Tikka Pizza", 150, "Pizza");

    menu.addItem("Golden Corn Pizza", 150, "Pizza");

    menu.addItem("Double Cheese Pizza", 150, "Pizza");


    //pasta

    menu.addItem("White Cheese Pasta", 210, "Pasta");

    menu.addItem("Red Sauce Pasta", 210, "Pasta");

    menu.addItem("Mixed Sauce Pasta", 210, "Pasta");

    menu.addItem("Peri Peri Pasta", 210, "Pasta");

    menu.addItem("Spaghetti", 210, "Pasta");


    //Sandwich

    menu.addItem("Cheese Chutney Sandwich", 120, "Sandwich");

    menu.addItem("Panner Tikka Sandwich", 120, "Sandwich");

    menu.addItem("Potato Masala Sandwich", 120, "Sandwich");

    menu.addItem("Exotic Mayo Sandwich", 120, "Sandwich");

    menu.addItem("Veg Club Sandwich(Pizza Style)", 120, "Sandwich");


    //Hot coffee

    menu.addItem("Cappaccino", 110, "Hot Coffee");

    menu.addItem("Cafe Latte", 110, "Hot Coffee");

    menu.addItem("Flat White", 110, "Hot Coffee");

    menu.addItem("Hot Chocolate", 110, "Hot Coffee");


    //cold coffee

    menu.addItem("Caramel Coffee", 150, "Cold Coffee");

    menu.addItem("Cold Coffee", 150, "Cold Coffee");

    menu.addItem("Irish Coffee", 150, "Cold Coffee");

    menu.addItem("Iced Coffee", 150, "Cold Coffee");

    menu.addItem("Choco Crunch", 150, "Cold Coffee");


    //Ice Creams

    menu.addItem("Cone", 100, "Ice Cream");

    menu.addItem("Bar", 50, "Ice Cream");

    menu.addItem("Bucket", 250, "Ice Cream");

    menu.addItem("Ice cream Sandwich", 100, "Ice Cream");

    menu.addItem("Family Pack", 100, "Ice Cream");


    int choice;
    vector<int> order;
    vector<int> quantity; 
    int tableBooking = 0; 

    while (true) {
        cout << "Food Ordering Menu:" << endl;
        menu.displayMenu();

        cout << "Enter the number of the item you'd like to order (0 to finish, -1 to view order, -2 to edit order, -3 to book a table): ";
        cin >> choice;

        if (choice == 0) {
            break;
        } 

        else if (choice == -1) {

            if (order.empty()) {
                cout << "Your order is empty." << endl;
            } else {
                cout << "Your order:" << endl;
                double totalCost = 0.0;

                for (size_t i = 0; i < order.size(); ++i) {
                    int itemIndex = order[i];
                    string itemName = menu.getItemName(itemIndex - 1);
                    double itemPrice = menu.getItemPrice(itemIndex - 1);
                    int itemQuantity = quantity[i];
                    cout << itemName << " x" << itemQuantity << " - Rs" << itemPrice * itemQuantity << endl;
                    totalCost += itemPrice * itemQuantity;
                }
                cout << "Total cost: Rs" << totalCost << endl;
            }
        } 
        else if (choice == -2) {

            if (order.empty()) {
                cout << "Your order is empty. Nothing to edit." << endl;
            }
            
             else {
                cout << "Your current order:" << endl;
                double totalCost = 0.0;
                for (size_t i = 0; i < order.size(); ++i) {
                    int itemIndex = order[i];
                    string itemName = menu.getItemName(itemIndex - 1);
                    double itemPrice = menu.getItemPrice(itemIndex - 1);
                    int itemQuantity = quantity[i];
                    cout << itemName << " x" << itemQuantity << " - Rs" << itemPrice * itemQuantity << endl;
                    totalCost += itemPrice * itemQuantity;
                }
                cout << "Total cost: Rs" << totalCost << endl;

                cout << "Enter the number of the item you'd like to remove from the order: ";
                cin >> choice;

                if (choice >= 1 && choice <= order.size()) {
                    cout << menu.getItemName(order[choice - 1] - 1) << " removed from your order." << endl;
                    order.erase(order.begin() + choice - 1);
                    quantity.erase(quantity.begin() + choice - 1);
                }
                
                 else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        } 

        else if (choice == -3) {
            cout << "Enter the number of people for table booking: ";
            cin >> tableBooking;
            cout << "Table booked for " << tableBooking << " people." << endl;
        }

        else if (choice >= 1 && choice <= menu.getItemCount()) {
            int itemQuantity;
            cout << "Enter the quantity for " << menu.getItemName(choice - 1) << ": ";
            cin >> itemQuantity;
            
            if (itemQuantity > 0) {
                order.push_back(choice);
                quantity.push_back(itemQuantity);
                cout << menu.getItemName(choice - 1) << " x" << itemQuantity << " added to your order." << endl;
            }
            
             else {
                cout << "Invalid quantity. Please try again." << endl;
            }
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    cout << "Thank you for your order!" << endl;
    
    if (tableBooking > 0) {
        cout << "Table booked for " << tableBooking << " people." << endl;
    }

    return 0;

}
