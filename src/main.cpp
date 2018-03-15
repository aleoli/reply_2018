#include <iostream>

using std::cout;
using std::endl;

#include "reply.hpp"
using namespace reply;

int main(int argc, char *argv[]) {
    cout << "Cacca!" << endl;
    
    Reader r(string(argv[1]));
    map<int, Provider *> provs = r.getProviders();
    map<unsigned int, Project *> projects = r.getProjects();
    
    for(auto it=projects.rbegin(); it!=projects.rend(); ++it) {
        it->second->buy_res(&provs);
    }
    
    Output o(projects);
    
    return 0;
}
