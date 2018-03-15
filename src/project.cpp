#include "project.hpp"
using reply::Project;

#include "service.hpp"

Project::Project(int id, unsigned long penalty, Country *c) {
    this->id = id;
    this->penalty = penalty;
    this->c = c;
}

void Project::add_service(Service_quant sq) {
    this->sqs[sq.s->getId()] = sq;
}

void Project::buy_res(map<int, Provider *> *provs) {
    
}
