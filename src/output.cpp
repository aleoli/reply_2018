#include "output.hpp"

using hs::Output;

Output::Output(vector<Package_quant> mProjects){
    
    FILE* f;
    f=fopen("output.txt","w");
    
    for(int i=0;i<mProjects.size();i++) {
        fprintf(f,"%d ",&mProjects[i].q);
    }
    fclose(f);
}