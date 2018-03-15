#ifndef package_hpp
#define package_hpp

#include "dependencies.hpp"

namespace reply {
    
    class Package {
        
    public:
        Package(int id, int n_u, float cost, Region*);
        
        void add_service(Service_quant s);
        int getNum() const;

		float getCost() const;
		int getLatenza(Country *c) const;
        map<int, Service_quant> getServ() const;
        
    private:
        int id;
        int n_u;
        float cost;
        map<int, Service_quant> ss;
		Region *r;
        vector<Package *> bought;
        
    };
    
}

#endif
