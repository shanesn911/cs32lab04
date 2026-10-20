#include "CustomItem.h"
#include <sstream>
#include <iomanip>

CustomItem::CustomItem(std::string size) : IceCreamItem(size) {}

CustomItem::~CustomItem() {}

void CustomItem::addTopping(std::string topping) {
    toppings[topping]++;
}

double CustomItem::getPrice() {
    double base = 0.0;
    if (size == "small") base = 3.00;
    else if (size == "medium") base = 5.00;
    else if (size == "large") base = 6.50;

    int totalOz = 0;
    for (const auto& t : toppings) totalOz += t.second;
    return base + 0.40 * totalOz;
}

std::string CustomItem::composeItem() {
    std::ostringstream out;
    out << "Custom Size: " << size << std::endl;
    out << "Toppings: " << std::endl;
    for (const auto& t : toppings) {
        out << t.first << ": " << t.second << " oz" << std::endl;
    }
    out << "Price: $" << std::fixed << std::setprecision(2) << getPrice() << "\n";
    return out.str();
}