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

Qualcosa Provider::getQualcosa(Country* country, vector<Service*> unita){
	Region *r;
	for(auto it=this->regioni.begin(); it!=this->regioni.end();++it){
		r = it->second;
		
		//verifico se ci sono ancora pacchetti
		if(r->getPackage()->getNum() == 0) continue;
		
		
		
		//
	}
}
