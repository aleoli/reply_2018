#include "project.hpp"
using reply::Project;

Project::Project(int id, unsigned long penalty, Country *c) {
    this->id = id;
    this->penalty = penalty;
    this->c = c;
}

void Project::add_service(Service_quant sq) {
    this->sqs[sq.s->getId()] = sq;
}
