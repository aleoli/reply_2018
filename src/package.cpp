#include "package.hpp"
using reply::Package;

Package::Package(int id, int n_u, float cost) {
    this->id = id;
    this->n_u = n_u;
    this->cost = cost;
}

void Package::add_service(Service_quant s) {
    this->ss[s.s->getId()] = s;
}

int Package::getNum() const {
	return this->n_u;
}
