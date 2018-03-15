#include "country.hpp"
using reply::Country;

Country::Country(int id, string name) {
    this->id = id;
    this->name = name;
}

int Country::getId() const {
    return this->id;
}
