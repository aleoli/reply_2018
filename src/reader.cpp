#include "reader.hpp"
using reply::Reader;

#include <fstream>

using std::ifstream;

Reader::Reader(string file_name) {
	
	ifstream f(file_name);
	
    int nProv;
    int nSer;
    int nCou;
    int nProj;
	f >> nProv >> nSer >> nCou >> nProj;
    
	while(true) {
/*		Ride r;
		r.id = id;
		if(!(f >> r.start.x >> r.start.y >> r.end.x >> r.end.y >> r.st_t >> r.end_t)) {
			break;
		}
		cout << r.start.x << " " << r.start.y << " " << r.end.x << " " << r.end.y << " " << r.st_t << " " << r.end_t << endl;
		this->mRides.push_back(r);
		id++;*/
        string tmp;
        int tmp1;
        
        for(int count=0; count<nSer; count++){
            f >> tmp;
            mServices[count]=new Service(count,tmp);
        }
        
        for(int count=0; count<nCou; count++){
            f >> tmp;
            mCountries[count]=new Country(count,tmp);
        }
        
        for(int count=0; count<nProv; count++){
            f >> tmp >> tmp1;
            mProviders[count]=new Provider(count,tmp);
            for(int count1=0; count1<tmp1; count1++){
                string nomereg;
                int available;
                float package_unit_cost;
                f >> nomereg;
                f >> available >> package_unit_cost;                 Region* reg=new Region(count1,nomereg);
                Package* p= new Package(count1,available,package_unit_cost);
                for(int count3; count3<nSer; count3++){
                    Service_Quant sq;
                    int q;
                    sq.s= mServices[count3];
                    f >> q;
                    sq.q= q;
                    p->add_service(sq);
                }
                reg->add_package(p);
                for(int count2; count2<nCou; count2++){
                    int latency;
                    Country_Latency cl;
                    cl.c=mCountries[count2];
                    f >> latency;
                    cl.latency=latency;
                    reg->add_country(cl);
                }
                mProviders[count]->addRegion(reg);
            }
        }
        for(int i=0;i<nProj;i++){
            unsigned long penalty;
            string ncountry;
            f >> penalty >> ncountry;
            Project* p=new Project(i,penalty,mCountries[ncountry]);
            for(j=0;j<nSer;j++){
                Service_Quant sq;
                int q;
                sq.s= mServices[j];
                f >> q;
                sq.q= q;
                p->add_service(sq);
            }
        }
	}
}

MapConfig Reader::GetMap() {
	return this->mMap;
}

vector<Ride> Reader::GetRides() {
	return this->mRides;
}
