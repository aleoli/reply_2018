#include "output.hpp"

using reply::Output;

Output::Output(map<unsigned int,Project*> mProjects){
    
    FILE* f;
    f=fopen("output.txt","w");
    
    for(int i=0;i<mProjects.size();i++) {
        for(int j=0;j<mProjects[i]->getBought().size();j++){
            vector<Package_quant> tmp=mProjects[i]->getBought();
            fprintf(f,"%d ",tmp[j].q);
        }
    }
    fclose(f);
}