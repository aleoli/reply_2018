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
    map<> GetMap();
    vector<Ride> GetRides();
		int,*Ser
    private:
	Map<int,*Service> mServices;
    Map<int,*Country> mCountries;
    Map<int,*Provider> mProviders;
    Map<signed long,*Project> mProjects;
	};
	
}

#endif