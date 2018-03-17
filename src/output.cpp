#include "output.hpp"
using reply::Output;

#include "project.hpp"
#include "region.hpp"
#include "provider.hpp"
#include "package.hpp"

using reply::Project;

#include <fstream>
using std::ofstream;

Output::Output(list<Project*> projects, string file_name) {
    
    ofstream f;
    f.open(file_name, ofstream::out);
    
    for(auto it=projects.begin(); it!=projects.end(); ++it) {
        vector<Package_quant> tmp = (*it)->getBought();
        for(auto it2=tmp.begin(); it2!=tmp.end(); ++it2) {
            f << it2->p->getProv()->getId() << " " << it2->p->getRegion()->getId() << " " << it2->q << " ";
        }
        f << endl;
    }
    
    f.close();
}
