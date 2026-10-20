#include "PreMadeItem.h"
#include <iomanip>
#include <sstream>

using namespace std;

PreMadeItem::PreMadeItem(std::string name, std::string size)
    : IceCreamItem(size), name(name) {}

PreMadeItem::~PreMadeItem() {}

double PreMadeItem::getPrice() {
    if (size == "small") return 4.00;
    if (size == "medium") return 6.00;
    if (size == "large") return 7.50;
    return 0.0;
}

std::string PreMadeItem::composeItem() {
   std::ostringstream out;
    out << "Pre-made Size: " << size << "\n";
    out << "Pre-made Item: " << name << "\n";
    out << "Price: $" << std::fixed << std::setprecision(2) << getPrice() << "\n";
    return out.str();
}


