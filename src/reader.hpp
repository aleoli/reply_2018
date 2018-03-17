#ifndef reader_hpp
#define reader_hpp

#include "dependencies.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

namespace reply {
	
	class Reader {
	
	public:
        Reader(string);
		map<int, Provider *> getProviders();
		list<Project *> getProjects();
        list<Package *> getPackages();
		
  private:
		list<Project *> projects;
		map<int, Service *> mServices;
		map<int, Country *> mCountries;
        map<string, Country *> str_country;
		map<int, Provider *> mProviders;
        list<Package *> packages;
	};
	
}

#endif
