#include "provider.hpp"
using reply::Provider;

#include <exception>

#include "region.hpp"
#include "package.hpp"
#include "service.hpp"

using reply::Package;
using reply::Pack;
using reply::Service_quant;

Provider::Provider(int id, string name){
	this->id = id;
	this->name = name;
}

Provider::~Provider(){
	for(auto it=this->regioni.begin(); it!=this->regioni.end();++it)
		delete it->second;
}

int Provider::getId() const {
    return this->id;
}

void Provider::addRegion(Region *r){
	regioni[r->getId()] = r;
}

Pack Provider::getPackage(Country* country, map<int, Service_quant> serv) {
	Region *r;
	Pack ptemp;
	Pack pack;
	Package *p;
	float latcost=-1;
	float ltemp;
    
    bool has_pack = false;

	for(auto it=this->regioni.begin(); it!=this->regioni.end();++it){
		r = it->second;
		
		p = r->getPackage();
		//verifico se ci sono ancora pacchetti
		if(p->getNum() == 0) continue;
        
        if(this->has_res(serv, p)) {
            
            has_pack = true;
            
            ptemp.lat = p->getLatenza(country);
            ptemp.cost = p->getCost();
            ptemp.p = p;
            
            ltemp = ptemp.lat*ptemp.cost;
            
            if(latcost==-1 || ltemp<latcost) {
                latcost = ltemp;
                pack = ptemp;
            }
            
        }

		//
	}
	
    if(!has_pack) {
        throw std::exception();
    }
    
	return pack;
}

bool Provider::has_res(map<int, Service_quant> serv, Package *p) {
    auto p_serv = p->getServ();
    for(auto it=serv.begin(); it!=serv.end(); ++it) {
        if(it->second.q <= 0)
            continue;
        auto it2 = p_serv.find(it->second.s->getId());
        if(it2 != p_serv.end() && it2->second.q > 0) {
            return true;
        }
    }
    return false;
}




