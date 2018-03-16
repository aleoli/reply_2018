#include "output.hpp"
using reply::Output;

#include "project.hpp"
#include "region.hpp"
#include "provider.hpp"
#include "package.hpp"

using reply::Project;

#include <fstream>
using std::ofstream;

Output::Output(map<unsigned long, Project*> mProjects, string file_name) {
    
    ofstream f;
    f.open(file_name, ofstream::out);
    
    for(auto it=mProjects.begin(); it!=mProjects.end(); ++it) {
        vector<Package_quant> tmp = it->second->getBought();
        for(auto it2=tmp.begin(); it2!=tmp.end(); ++it2) {
            f << it2->p->getProv()->getId() << " " << it2->p->getRegion()->getId() << " " << it2->q << " ";
        }
        f << endl;
    }
    
    f.close();
}
