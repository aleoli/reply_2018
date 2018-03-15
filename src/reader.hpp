#ifndef reader_hpp
#define reader_hpp

#include "dependencies.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

using reply::Service;
using reply::Country;
using reply::Provider;

namespace reply {
	
	class Reader {
	
	public:
    Reader(string);
    map<int,Service*> get_services();
    map<int,Country*> get_countries();
    map<int,Provider*> get_providers();
    map<int,Project*> get_projects();
    private:
	map<int,Service*> mServices;
    map<int,Country*> mCountries;
    map<int,Provider*> mProviders;
    map<unsigned long,*Project> mProjects;
	};
	
}

#endif