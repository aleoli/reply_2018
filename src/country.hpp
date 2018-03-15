#ifndef country_hpp
#define country_hpp

#include "dependencies.hpp"

namespace reply {
    
    class Country {
        
    public:
        Country(int id, string name);
        
        int getId() const;
        
    private:
        int id;
        string name;
        
    };
    
}

#endif
