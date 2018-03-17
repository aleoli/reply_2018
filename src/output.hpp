#ifndef output_hpp
#define output_hpp

#include "dependencies.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

namespace reply {
	
    class Output {
	
        public:
        Output(list<Project*> projects, string file_name);
    };
	
}

#endif
