#include <iostream>

using std::cout;
using std::endl;

#include "reply.hpp"
using namespace reply;

int main(int argc, char *argv[]) {
    cout << "Cacca!" << endl;
    
    if(argc != 3) {
        cout << "Mancano argomenti" << endl;
        exit(1);
    }
    
    Reader r((string(argv[1])));
    cout << "1)" << endl;
    map<int, Provider *> provs = r.getProviders();
    cout << "2)" << endl;
    map<unsigned long, Project *> projects = r.getProjects();
    cout << "3)" << endl;
    
    for(auto it=projects.rbegin(); it!=projects.rend(); ++it) {
        cout << it->second->getId() << endl;
        it->second->buy_res(&provs);
    }
    cout << "4)" << endl;
    
    Output o(projects, string(argv[2]));
    cout << "5)" << endl;
    
    return 0;
}
