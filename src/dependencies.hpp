#ifndef dependencies_hpp
#define dependencies_hpp

#include <iostream>
#include <vector>
#include <map>
#include <list>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::map;
using std::list;

namespace reply {
    
    class Provider;
    class Service;
    class Country;
    class Project;
    class Region;
    class Reader;
    class Package;
    class Output;
    
    class Lock;
    
    typedef struct {
        Country *c;
        int latency;
    } Country_latency;
    
    typedef struct {
        Service *s;
        int q;
    } Service_quant;
    
    typedef struct {
        Package *p;
        int lat;
        float cost;
    } Pack;
    
    typedef struct {
        Package *p;
        int q;
    } Package_quant;
    
    typedef struct {
        Package *p;
        Country *c;
    } Package_country;
    
}

#endif
