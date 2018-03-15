#include "package.hpp"
using reply::Package;

#include "service.hpp"
#include "region.hpp"

using reply::Service_quant;

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

map<int, Service_quant> Package::getServ() const {
    return this->ss;
}

int Package::getId(){
	return this->id;
}

