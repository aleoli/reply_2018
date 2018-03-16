#ifndef provider_hpp
#define provider_hpp

#include "dependencies.hpp"

namespace reply {
	
	class Provider {
		
    public:
        Provider(int, string);
        
        int getId() const;
        void addRegion(Region*);
        void addNumRegion(int);
        ~Provider();
        Pack getPackage(Country*, map<int, Service_quant>);
    
    private:
        bool has_res(map<int, Service_quant>, Package *);
        
        int id;
        string name;
        map<int, Region*> regioni;
		
	};
	
	
}





#endif
