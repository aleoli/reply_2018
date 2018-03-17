#include "package.hpp"
using reply::Package;

#include "service.hpp"
#include "region.hpp"
#include "provider.hpp"

using reply::Service_quant;
using reply::Provider;
using reply::Region;

Package::Package(int id, int n_u, float cost, Region *r, Provider *p) {
    this->id = id;
    this->n_u = n_u;
    this->cost = cost;
	this->r = r;
    this->p = p;
}

Region *Package::getRegion() const {
    return this->r;
}

Provider *Package::getProv() const {
    return this->p;
}

void Package::scale() {
    this->lock.lock();
    this->n_u--;
    this->lock.unlock();
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

int Package::getId() const {
	return this->id;
}

bool Package::compare(const Package_country first, const Package_country second) {
    return first.p->getLatenza(first.c)*first.p->getCost() < second.p->getLatenza(second.c)*second.p->getCost();
}

