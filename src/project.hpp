#ifndef project_hpp
#define project_hpp

#include "dependencies.hpp"

namespace reply {
    
    class Project {
        
    public:
        Project(int id, unsigned long penalty, Country *c);
        
        int getId() const;
        unsigned long getPenalty() const;
        void add_service(Service_quant s_q);
        void buy_res(list<Package *> *packages);
        vector<Package_quant> getBought();
        
        static bool compare(const Project *first, const Project *second);
        
    private:
        void scale_res(Package *p);
        bool find_best(list<Package *> *packages, Pack *best);
        bool has_res(Package *p);
        
        int id;
        unsigned long penalty;
        Country *c;
        map<int, Service_quant> sqs;
        bool has_req;
        map<int, Package_quant> bought;
        
    };
    
}

#endif
