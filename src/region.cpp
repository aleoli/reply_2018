#include "region.hpp"
using reply::Region;

#include "country.hpp"
#include "package.hpp"

using reply::Package;

Region::Region(int id, string name) {
    this->id = id;
    this->name = name;
}

void Region::add_country(Country_latency c_l) {
    this->cls[c_l.c->getId()] = c_l;
}

void Region::add_package(Package *p) {
    this->package = p;
}

int Region::getId() const {
    return this->id;
}

Package *Region::getPackage() const {
    return this->package;
}

int Region::getLatenza(Country *c){
	Country_latency cl;
	for(auto it=this->cls.begin(); it!=this->cls.end();++it){
		cl = it->second;
		if(cl.c == c)
            return cl.latency;
	}
    return 0;
}
