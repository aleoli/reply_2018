#include "project.hpp"
using reply::Project;

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
            Pack p = it->second->getPackage(*(this->c), this->sqs);
            if(!has_best) {
                has_best = true;
                best = p;
            } else if(p.lat*p.cost < best.lat*best.cost) {
                best = p;
            }
        }
        this->scale_res(best.p);
    }
}

void Project::scale_res(Package *p) {
    auto it = this->bought.find(p->getId());
    if(it!=this->bought.end()) {
        Package_quant pq;
        pq.p = p;
        pq.q = 1;
        this->bought[p->getId()] = pq;
    } else {
        this->bought[p->getId()].q++;
    }
    map<int, Service_quant> ss = p->getServ();
    bool finish = true;
    for(auto it=ss.begin(); it!=ss.end(); ++it) {
        int tmp = this->sqs[it->second.s->getId()].q - it->second.q;
        this->sqs[it->second.s->getId()].q = tmp;
        if(this->sqs[it->second.s->getId()].q > 0) {
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
