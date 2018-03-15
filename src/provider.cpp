#include "provider.hpp"
using reply::Provider;

#include "region.hpp"
#include "package.hpp"

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

Package *Provider::getPackage(Country* country, map<int, Service_quant> serv){
	Region *r;
	Package *p=NULL;
	Package *ptemp=NULL;
	float latcost=-1;

	for(auto it=this->regioni.begin(); it!=this->regioni.end();++it){
		r = it->second;
		
		ptemp = r->getPackage();
		//verifico se ci sono ancora pacchetti
		if(ptemp->getNum() == 0) continue;
		
		prod = ptemp->getLatenza()*ptemp->getCost();
		
		if(latcost==-1 || prod<latcost) {
			latcost = prod;
			p = ptemp;
		}		

		//
	}
	
	return p;
}
