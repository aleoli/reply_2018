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
		map<int,Provider*> getProviders();
		map<int,Service*> getServices();
		map<int,Country*> getCountries();
		map<unsigned int,Project*> getProjects();
		Reader(string);
		
  private:
		map<int,Project*> mProjects;
		map<int,Service*> mServices;
		map<int,Country*> mCountries;
		map<int,Provider*> mProviders;    
	};
	
}

#endif
