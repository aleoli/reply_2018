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

void Project::buy_res(list<Package *> *packages) {
    Pack best;
    while(this->has_req) {
        if(this->find_best(packages, &best)) {
            this->scale_res(best.p);
        } else {
            break;
        }
    }
}

bool Project::find_best(list<Package *> *packages, Pack *best) {
    list<Package_country> tmp;
    for(auto it=packages->begin(); it!=packages->end(); ++it) {
        if(this->has_res(*it)) {
            Package_country pc;
            pc.p = *it;
            pc.c = this->c;
            tmp.push_back(pc);
        }
    }
    if(tmp.size() == 0) {
        return false;
    }
    tmp.sort(Package::compare);
    Package *p = tmp.front().p;
    best->p = p;
    best->lat = p->getLatenza(this->c);
    best->cost = p->getCost();
    return true;
}

bool Project::has_res(Package *p) {
    auto p_serv = p->getServ();
    for(auto it=this->sqs.begin(); it!=this->sqs.end(); ++it) {
        if(it->second.q <= 0)
            continue;
        auto it2 = p_serv.find(it->second.s->getId());
        if(it2 != p_serv.end() && it2->second.q > 0) {
            return true;
        }
    }
    return false;
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

unsigned long Project::getPenalty() const {
    return this->penalty;
}

int Project::getId() const {
    return this->id;
}

bool Project::compare(const Project *first, const Project *second) {
    return first->penalty < second->penalty;
}

