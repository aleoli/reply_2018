#include "provider.hpp"
using reply::Provider;

#include "region.hpp"
#include "package.hpp"

using reply::Pack;

Provider::Provider(int id, string name){
	this->id = id;
	this->name = name;
}

Provider::~Provider(){
	for(auto it=this->regioni.begin(); it!=this->regioni.end();++it)
		delete it->second;
}

void Provider::addRegion(Region *r){
	regioni[r->getId()] = r;
}

Pack Provider::getPackage(Country* country, map<int, Service_quant> serv){
	Region *r;
	Pack ptemp;
	Pack pack;
	Package *p;
	float latcost=-1;
	float ltemp;

	for(auto it=this->regioni.begin(); it!=this->regioni.end();++it){
		r = it->second;
		
		p = r->getPackage();
		//verifico se ci sono ancora pacchetti
		if(p->getNum() == 0) continue;
		
		ptemp.lat = p->getLatenza();
		ptemp.cost = p->getCost();
		
		ltemp = ptemp.lat*ptemp.cost;
		
		if(latcost==-1 || ltemp<latcost) {
			latcost = ltemp;
			pack = ptemp;
		}		

		//
	}
	
	return pack;
}
