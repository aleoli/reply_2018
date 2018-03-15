#include "output.hpp"

using hs::Output;

Output::Output(map<int,Project*> mProjects){
    
    FILE* f;
    f=fopen("output.txt","w");
    
    for(int i=0;i<mProjects.size();i++) {
        for(int j=0;j<mProjects[i]->;j++)
    }
    fclose(f);
}