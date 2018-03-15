#ifndef reader_hpp
#define reader_hpp

#include "dependencies.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

using hs::Service;
using hs::Country;
using hs::Provider;

namespace hs {
	
	class Reader {
	
	public:
    Reader(string);
    MapConfig GetMap();
    vector<Ride> GetRides();
		
    private:
	Map<int,*Service> mServices;
    Map<int,*Country> mCountries;
    Map<int,*Provider> mProviders;
    Map<signed long,*Project> mProjects;
	};
	
}

#endif