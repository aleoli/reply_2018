#include "region.hpp"
using reply::Region;

Region::Region(int id, string name) {
    this->id = id;
    this->name = name;
}

void Region::add_contry(Country_latency c_l) {
    this->cls[c_l.c->getId()] = c_l;
}

void Region::add_package(Package *p) {
    this->packages.push_back(p);
}
