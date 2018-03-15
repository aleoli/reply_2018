#ifndef dependencies_hpp
#define dependencies_hpp

#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::map;

namespace reply {
    
    class Provider;
    class Service;
    class Country;
    class Project;
    class Region;
    class Reader;
    class Package;
    
    typedef struct {
        Country *c;
        int latency;
    } Country_latency;
    
    typedef struct {
        Service *s;
        int q;
    } Service_quant;
    
}

#endif
