#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){

    // Variables for order handling.
    int ordercode, quantity; // Selected product code and quantity.
    char yesno; // User response for yes/no questions.
    string order; // Name of the selected product.
    double money = 0, pay, change;  // Total cost, money inserted, and change.

    int stock[10] = {0, 10, 6, 3, 9, 16, 8, 4, 11, 18};  // Stock array: index represents product code, value represents quantity available
    double price [] = {0, 1.50, 2.00, 2.00, 2.75, 1.00, 0.50, 3.50, 4.00, 2.50}; // Price array: index corresponds to product code
    string names [] = {"", "Water", "Sprite", "Coke Cola","Lacazette", "Kit Kat", "Tea", "Latte", "Mocha", "Espresso"};  // Product names array: index corresponds to product code

    do
    {
         // Display vending machine menu and current stock
        cout << "\n\n Welcome to Danilo Vending Machine";
        cout << "\n\n ============= Drinks ==================";
        cout << "\n1. Water - 1.50 (" << stock [1] << "left)";         
        cout << "\n2. Sprite - 2.00 (" << stock [2] << "left)";
        cout << "\n3. Coke cola - 2.00 (" << stock [3] << "left)";
        cout << "\n4. Lacazette - 2.75 (" << stock [4] << "left)"; 
        cout << "\n =============== Snacks ===================";    
        cout << "\n5. Kit Kat - 1.00 (" << stock [5] << "left)";
        cout << "\n ================Hot Drinks ===============";
        cout << "\n6. Tea - 0.50 (" << stock [6] << "left)";
        cout << "\n7. Latte - 3.50 (" << stock [7] << "left)";
        cout << "\n8. Mocha - 4.00 (" << stock [8] << "left)";
        cout << "\n9. Espresso - 2.50 (" << stock [9] << "left)";
        cout << "\n==========================\n";

        cout << "Insert your money: "; // Ask user to insert money.
        cin >> pay; //Input user's money.


        cout << "Choose your order (1 - 9): "; // Ask user to choose a product.
        cin >> ordercode; //Input user's product code.

        // Validate order code
        if (ordercode <1 || ordercode > 9){ //It determines that the ordercode runs from 1 to 9.
            cout << "Sorry, Invalid option, Please choose a number between 1 to 9. "; //Output this message asking the user to put a correct code.
            continue;  // Restart the loop
        }

        cout << "Please Enter Quantity: "; //Output this message.
        cin >> quantity; //User has to input the quantity.

        if(quantity > stock[ordercode]){  // Check if enough stock is available.
            cout << "Sorry, not enough stock for " << names[ordercode] << endl; //Output this message if the ordercode is out of stock.
        }

        // Calculate total cost and set order name.
        money = price[ordercode] * quantity; //Variable which 
        order = names[ordercode]; //variable which is order = array names[ordercode].

        if(pay < money){ // Check if user has inserted enough money
            cout << "Sorry, you do not have enough money. " << pay << " returned " << endl; //Output this message and it gives to the user their money.
        } else{
            stock[ordercode] -= quantity; // Deduct stock and calculate change.
            change = pay - money; //Variable which gives the change.

            cout << "\nDispensing your " << order << "...\n"; //Output this message to inform user that the order is dispensing and shows their order.
            cout << "Order: " << quantity << " x " << order << endl; //Output this message to inform user the order quantity x order.
            cout << "Total: £" << money << endl; //Output the user's money.
            cout << "Change: £" << change << endl;  //Output the user's change.
        }

        // Offer a free Kit Kat for specific drinks
         if (order == "Tea" || order == "Coke Cola"){ //If the user's order is Tea or Coke Cola.
            cout << "\nWould you like to add a free Kit Kat? (y/n): "; //Output offering a free Kit Kat. 
            cin >> yesno; //User's input their choice.

            if (yesno == 'y' || yesno == 'Y') { //If the user's answer is 'Y' or 'y', it means that it adds Kit Kat.
                cout << "Adding Kit Kat to your order!\n"; //Output this message to let the user knows that their kit kat is on its way.
                stock[5]--; // remove 1 Kit Kat from stock
            }
        }

        // ----------- ORDER AGAIN? ----------------
        cout << "\nDo you want to order again? (y/n): "; 
        cin >> yesno; //Users input if they what to order again.



    } while (yesno == 'Y' || yesno == 'y'); // Repeat while the user answers 'y' or 'Y'.
    
    cout << "\nThank you for buying with us. See you soon!\n"; //If it is not 'Y', it will show this final message.
    return 0;


}