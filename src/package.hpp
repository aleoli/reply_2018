#ifndef package_hpp
#define package_hpp

#include "dependencies.hpp"

#include "lock.hpp"

namespace reply {
    
    class Package {
        
    public:
        Package(int id, int n_u, float cost, Region*, Provider *);
        
        void add_service(Service_quant s);
        int getNum() const;
		float getCost() const;
		int getLatenza(Country *c) const;
        map<int, Service_quant> getServ() const;
		int getId() const;
        void scale();
        
        Region *getRegion() const;
        Provider *getProv() const;
        
        static bool compare(const Package_country first, const Package_country second);
        
    private:
        Lock lock;
        int id;
        int n_u;
        float cost;
        map<int, Service_quant> ss;
		Region *r;
        Provider *p;
        vector<Package *> bought;
        
    };
    
}

#endif
