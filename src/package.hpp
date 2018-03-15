#ifndef package_hpp
#define package_hpp

#include "dependencies.hpp"

namespace reply {
    
    class Package {
        
    public:
        Package(int id, int n_u, float cost);
        
        void add_service(Service_quant s);
        int getNum() const;
        
    private:
        int id;
        int n_u;
        float cost;
        map<int, Service_quant> ss;
        
    };
    
}

#endif
