#ifndef project_hpp
#define project_hpp

#include "dependencies.hpp"

namespace reply {
    
    class Project {
        
    public:
        Project(int id, unsigned long penalty, Country *c);
        
        void add_service(Service_quant s_q);
        
    private:
        int id;
        unsigned long penalty;
        Country *c;
        map<int, Service_quant> sqs;
        
    }
    
}

#endif
