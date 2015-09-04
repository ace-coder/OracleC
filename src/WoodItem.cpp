/* 
 * File:   WoodItem.cpp
 * Author: Md Mainuddin
 * 
 * Created on September 3, 2015, 10:45 PM
 */

#include "WoodItem.h"

/*
 * Empty constructor
 */
WoodItem::WoodItem() {
}

/*
 * Method to initialize a tic tac toe game
 * Initializes board and turn
 */
WoodItem::WoodItem(std::string woodType, double woodAmount, double itemPrice) {
    type = woodType;
    amount = woodAmount;
    price = itemPrice;
}

WoodItem::~WoodItem() {
}

