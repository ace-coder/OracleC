/* 
 * File:   WoodItem.h
 * Author: Md Mainuddin
 *
 * Created on September 3, 2015, 10:45 PM
 */

#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef WOODITEM_H
#define	WOODITEM_H

class WoodItem {
public:
    std::string type;
    double amount;
    double price;

    // Member functions declaration
    WoodItem();
    WoodItem(std::string woodType, double woodAmount, double itemPrice);
    virtual ~WoodItem();
private:

};

#endif	/* WOODITEM_H */
