//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Md Mainuddin
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
//============================================================================

#include "HardwoodSeller.hpp"

string ShowCurrencyFormat(double amount) {
    std::stringstream ss;
    if (amount < 0) {
        ss << "-$" << std::fixed << -amount;
    } else {
        ss << "$" << std::fixed << std::setprecision(2) << amount;
    }
    return ss.str();
}

int main() {
    //Read the input file
    ifstream file("input.txt");

    string line1, line2;

    getline(file, line1);
    getline(file, line2);

    // Line 1 contains Buyer name; Address; Date
    // Line 2 contains a combination of WoodType and amount

    // Extract Name, Address, Date from line 1
    istringstream ss(line1);
    string name, address, date;

    getline(ss, name, ';');
    getline(ss, address, ';');
    getline(ss, date, ';');

    // Extract Wood types and amounts and do the calculation
    istringstream wood_collection(line2);
    string wood;

    double total_price = 0;
    double delivery_time = 0;

    vector<WoodItem> wood_items;

    while (getline(wood_collection, wood, ';')) {

        istringstream wood_with_amount(wood);
        string wood_type, amount;

        getline(wood_with_amount, wood_type, ':');
        getline(wood_with_amount, amount, ':');

        double basePrice = 0;
        double baseDeliveryTime = 0;

        if (wood_type == "Cherry") {
            basePrice = 5.95;
            baseDeliveryTime = 2.5;
        } else if (wood_type == "Curry Maple") {
            basePrice = 6;
            baseDeliveryTime = 1.5;
        } else if (wood_type == "Genuine Mahogany") {
            basePrice = 9.6;
            baseDeliveryTime = 3;
        } else if (wood_type == "Wenge") {
            basePrice = 22.35;
            baseDeliveryTime = 5;
        } else if (wood_type == "White Oak") {
            basePrice = 6.70;
            baseDeliveryTime = 2.3;
        } else if (wood_type == "Sawdust") {
            basePrice = 1.5;
            baseDeliveryTime = 1;
        }

        double wood_amount = atof(amount.c_str());

        double item_price = basePrice * wood_amount;

        wood_items.push_back({wood_type, wood_amount, item_price});

        total_price += item_price;

        double deliveryTimeMultiplier = 1;
        if (wood_amount > 500) {
            deliveryTimeMultiplier = 5.5;
        } else if (wood_amount > 400) {
            deliveryTimeMultiplier = 5;
        } else if (wood_amount > 300) {
            deliveryTimeMultiplier = 4;
        } else if (wood_amount > 200) {
            deliveryTimeMultiplier = 3;
        } else if (wood_amount > 100) {
            deliveryTimeMultiplier = 2;
        }

        double itemDeliveryTime = deliveryTimeMultiplier * baseDeliveryTime;
        if (itemDeliveryTime > delivery_time) {
            delivery_time = itemDeliveryTime;
        }
    }

    cout << "Buyer Name: " << name << endl;
    cout << "Delivery Address: " << address << endl;
    cout << "Ordered Woods: " << endl;

    for (std::vector<WoodItem>::iterator it = wood_items.begin(); it != wood_items.end(); ++it) {
        cout << "\t Wood type: " << left << setw(15) << (*it).type << "\t Amount: " << (*it).amount << "\t Price: " << ShowCurrencyFormat((*it).price) << endl;
    }

    cout << "Total price: " << ShowCurrencyFormat(total_price) << ", Delivery time: " << delivery_time << " hour(s)";
    return 0;
}

/*
 * Method to read the input file
 */
void readInputFile(string inputFilePath) {

}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime() {
    double deliveryETA = 0.0;
    return deliveryETA;
}
