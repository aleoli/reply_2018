#include "reader.hpp"
using reply::Reader;

#include <fstream>
using std::ifstream;

#include "service.hpp"
#include "country.hpp"
#include "provider.hpp"
#include "region.hpp"
#include "package.hpp"
#include "project.hpp"

using reply::Provider;
using reply::Service;
using reply::Country;
using reply::Project;

Reader::Reader(string file_name) {
	
	ifstream f(file_name);
	
    int nProv;
    int nSer;
    int nCou;
    int nProj;
	f >> nProv >> nSer >> nCou >> nProj;
    
	string tmp;
	int tmp1;
	
	for(int count=0; count<nSer; count++){
		f >> tmp;
		this->mServices[count] = new Service(count,tmp);
	}
	
	for(int count=0; count<nCou; count++){
		f >> tmp;
        Country *c = new Country(count,tmp);
        this->mCountries[count] = c;
        this->str_country[tmp] = c;
	}
	
	for(int count=0; count<nProv; count++){
		f >> tmp >> tmp1;
        Provider *prov = new Provider(count, tmp);
		for(int count1=0; count1<tmp1; count1++) {
			string nomereg;
			int available;
			float package_unit_cost;
			f >> nomereg;
			f >> available >> package_unit_cost;                 
			Region* reg = new Region(count1, nomereg);
			Package* p = new Package(count1, available, package_unit_cost, reg, prov);
			for(int count3=0; count3<nSer; count3++) {
				Service_quant sq;
				int q;
				sq.s = this->mServices[count3];
				f >> q;
				sq.q = q;
				p->add_service(sq);
			}
			reg->add_package(p);
			for(int count2=0; count2<nCou; count2++) {
				int latency;
				Country_latency cl;
				cl.c = this->mCountries[count2];
				f >> latency;
				cl.latency = latency;
				reg->add_country(cl);
			}
			prov->addRegion(reg);
		}
        this->mProviders[count] = prov;
	}
	
	for(int i=0; i<nProj; i++) {
		unsigned long penalty;
		string ncountry;
		f >> penalty >> ncountry;
		Project* p = new Project(i, penalty, this->str_country[ncountry]);
		for(int j=0; j<nSer; j++) {
			Service_quant sq;
			int q;
			sq.s= mServices[j];
			f >> q;
			sq.q= q;
			p->add_service(sq);
		}
        this->mProjects[penalty] = p;
	}
    
    f.close();
}

map<int, Provider*> Reader::getProviders() {
	return this->mProviders;
}

map<int,Service*> Reader::getServices() {
	return this->mServices;
}

map<int,Country*> Reader::getCountries() {
	return this->mCountries;
}

map<unsigned long, Project *> Reader::getProjects() {
	return this->mProjects;
}
