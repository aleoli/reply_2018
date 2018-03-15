#include "project.hpp"
using reply::Project;

#include "service.hpp"

Project::Project(int id, unsigned long penalty, Country *c) {
    this->id = id;
    this->penalty = penalty;
    this->c = c;
    this->has_req = false;
}

void Project::add_service(Service_quant sq) {
    this->sqs[sq.s->getId()] = sq;
    this->has_req = true;
}

void Project::buy_res(map<int, Provider *> *provs) {
    while(this->has_req) {
        Pack best;
        bool has_best = false;
        for(auto it=provs.begin(); it!=provs.end(); ++it) {
            Pack p = it->second->getPackage(this->c, this->sqs);
            if(!has_best) {
                has_best = true;
                best = p;
            } else if(p.lat*p.cost < best.lat*.best.cost) {
                best = p;
            }
        }
        this->scale_res(best.p);
    }
}

void Project::scale_res(Package *p) {
    
}
