#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

#include "reply.hpp"
using namespace reply;

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout << "Mancano argomenti" << endl;
        exit(1);
    }
    
    Reader r((string(argv[1])));
    cout << "1)" << endl;
    list<Package *> packages = r.getPackages();
    cout << "2)" << endl;
    list<Project *> projects = r.getProjects();
    cout << "3)" << endl;
    
    for(auto it=projects.rbegin(); it!=projects.rend(); ++it) {
        cout << (*it)->getId() << endl;
        (*it)->buy_res(&packages);
    }
    cout << "4)" << endl;
    
    Output o(projects, string(argv[2]));
    cout << "5)" << endl;
    
    return 0;
}
