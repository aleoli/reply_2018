#include "package.hpp"
using reply::Package;

Package::Package(int id, int n_u, float cost, Region *r) {
    this->id = id;
    this->n_u = n_u;
    this->cost = cost;
	this->r = r;
}

void Package::add_service(Service_quant s) {
    this->ss[s.s->getId()] = s;
}

int Package::getNum() const {
	return this->n_u;
}

int Package::getLatenza(Country *c) const{
	return this->r->getLatenza(c);
}

float Package::getCost() const{
	return this->cost;
}