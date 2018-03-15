#ifndef service_hpp
#define service_hpp

#include "dependencies.hpp"

namespace reply {
    
    class Service {
        
    public:
        Service(int id, string name);
        ~Service();
        
        int getId() const;
        
    private:
        int id;
        string name;
        
    }
    
}

#endif
