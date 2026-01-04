#include <iostream>
#include <string>
using namespace std;

int main(){
 
    // Variable declarations.
    int ordercode, quantity; // Product code and quantity.
    char yesno; // User choice to repeat the order.
    string order, icon;  // Product name and string for icon/symbol.
    int money = 0, pay, change; // Total cost, inserted money, and change.
    icon[1] = 16; // Attempts to store a symbol (unsafe if string is not initialized).


    do
    { 
        // Display vending machine menu.
        cout << "\n\n Welcome to Danilo Vending Machine" << icon[1];
        cout << "\n\n ============= Menu ==================";
        cout << "\n\n 1. Water - 1.50         2. Sprite - 2.00";
        cout << "\n\n 3. Coke cola - 2.00     4. Kit Kat - 1.00";
        cout << "\n\n 5. Tea - 0.50";
        cout << "\n==========================\n";

        cout << "Insert your money: "; // Ask the user to insert money.
        cin >> pay; //User input how much they have.

        cout << "Choose your order (1 - 5): ";  // Ask the user to choose a product.
        cin >> ordercode; //Users input their choice.

        cout << "Please Enter Quantity: "; // Ask for the quantity.
        cin >> quantity; //Users input the quantity they would like.

        // Determine the selected product and calculate the total cost.
        switch (ordercode)
        {
        case 1:
            order = "Water"; //type of the product.
            money = quantity * 1.50; //Quantity x price.
            break;

        case 2:
            order = "Sprite"; //type of the product.
            money = quantity * 2; //Quantity x price.
            break;

        case 3:
            order = "Coke Cola"; //type of the product.
            money = quantity * 2; //Quantity x price.
            break;

        case 4:
            order = "Kit Kat"; //type of the product.
            money = quantity * 1; //Quantity x price.
            break;

        case 5:
            order = "Tea"; //type of the product.
            money = quantity * 0.50; //Quantity x price.
            break;
        
        default:
        cout << "Invalid Option"; //if the user input another anything else, it shows this message.
            break;
        }
    
    // Check if the inserted money is enough  
    if(pay < money){
        cout << "\n   Sorry, You do not have enough money to proceed this transaction. ";
        cout << "     We have returned you " << pay << "£"; 
    }

    else
    {
        // Calculate change
        change = pay - money;

        // Display order details
        cout << "Dispensing your " << order << endl; //Output this message with the order too.
        cout << "Order: " << quantity << " x " << order << endl; //Output the message and the calculation quantity x order to let the user knows how much is.

        cout << "Total:  " << quantity << " " << order << " = " << money << " - " << pay << " = " << change << endl; //Output the total which is quantity + order = money - pay = change.

        change = pay - money; //Variable which does the user's change.
        cout << "Change: " << change << "\n "; //Output how much the user has to get from the machine. 

    }

    // Ask if the user wants to place another order
    cout <<"\n\n" << icon[1] << "Do you want to order again? (y/n): ";
    cin >> yesno; //Users input if they what to order again.

        
    } 
    
    // Repeat while the user answers 'y' or 'Y'.
    while (yesno == 'Y' || yesno == 'y');


        //If it is not 'Y', it will show this final message.
        cout << "Thank you for buying with us, we are delighted to serve you. See you soon. " << endl;
    
}