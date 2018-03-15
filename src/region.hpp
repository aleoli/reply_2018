#ifndef region_hpp
#define region_hpp

#include "dependencies.hpp"

namespace reply {
    
    class Region {
        
    public:
        Region(int id, string name);
        
        int getId() const;
        Package *getPackage() const;
        
        void add_country(Country_latency c_l);
        void add_package(Package *p);
        
    private:
        int id;
        string name;
        map<int, Country_latency> cls;
        Package *package;
        
    };
    
}

#endif
