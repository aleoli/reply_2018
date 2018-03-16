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
		map<int, Service *> getServices();
		map<int, Country *> getCountries();
		map<unsigned long, Project *> getProjects();
		
  private:
		map<unsigned long, Project *> mProjects;
		map<int, Service *> mServices;
		map<int, Country *> mCountries;
        map<string, Country *> str_country;
		map<int, Provider *> mProviders;
	};
	
}

#endif
