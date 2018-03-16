#include "project.hpp"
using reply::Project;

#include <exception>

#include "service.hpp"
#include "package.hpp"
#include "provider.hpp"
#include "country.hpp"

using reply::Package_quant;

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
    this->n_provs = provs->size();
    while(this->has_req) {
        Pack best;
        bool has_best = false;
        for(auto it=provs->begin(); it!=provs->end(); ++it) {
            try {
                Pack p = it->second->getPackage(this->c, this->sqs);
                if(!has_best) {
                    has_best = true;
                    best = p;
                } else if(p.lat*p.cost < best.lat*best.cost) {
                    best = p;
                }
            } catch(std::exception &e) {
                
            }
        }
        if(has_best)
            this->scale_res(best.p);
        else
            break;
    }
}

void Project::scale_res(Package *p) {
    p->scale();
    if(this->bought.size()==0 || this->bought.find(p->getId())==this->bought.end()) {
        Package_quant pq;
        pq.p = p;
        pq.q = 1;
        this->bought[p->getId()] = pq;
    } else {
        this->bought[p->getId()].q++;
    }
    map<int, Service_quant> ss = p->getServ();
    bool finish = true;
    for(auto it=this->sqs.begin(); it!=this->sqs.end(); ++it) {
        int q = ss[it->first].q;
        int new_v = it->second.q - q;
        this->sqs[it->first].q = new_v;
        if(new_v > 0) {
            finish = false;
        }
    }
    if(finish) {
        this->has_req = false;
    }
}

vector<Package_quant> Project::getBought() {
    vector<Package_quant> res;
    for(auto it=this->bought.begin(); it!=this->bought.end(); ++it) {
        res.push_back(it->second);
    }
    return res;
}

int Project::getId() const {
    return this->id;
}
