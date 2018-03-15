#ifndef project_hpp
#define project_hpp

#include "dependencies.hpp"

namespace reply {
    
    class Project {
        
    public:
        Project(int id, unsigned long penalty, Country *c);
        
        void add_service(Service_quant s_q);
        void buy_res(map<int, Provider *> *provs);
        void scale_res(Package *p);
        int **getBought(int *w, int *h);
        
    private:
        int id;
        unsigned long penalty;
        Country *c;
        map<int, Service_quant> sqs;
        bool has_req;
        int n_provs;
        
    };
    
}

#endif
