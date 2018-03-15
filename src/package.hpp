#ifndef package_hpp
#define package_hpp

#include "dependencies.hpp"

namespace reply {
    
    class Package {
        
    public:
        Package(int id, int n_u, float cost);
        
    private:
        int id;
        int n_u;
        float cost;
        
    }
    
}

#endif
