#include "service.hpp"
using reply::Service;

Service::Service(int id, string name) {
    this->id = id;
    this->name = name;
}

Service::~Service() {
    
}

int Service::getId() const {
    return this->id;
}
