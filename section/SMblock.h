#ifndef EV3_UNIT_SMBLOCK_H_
#define EV3_UNIT_SMBLOCK_H_

#include "Section_management.h"
#include "RandomWalker.h"

class SMblock : public Section_management{
    public:
        SMblock();
        void init();
        void gonext();

    private:
    Main_Section blockpra[100]={
             {LINETRACER,{30,1,5,50,LEFT,0}, DISTANCE,{300},-1,{}, UPDATE_ALL},
                        
            {-1,{}, -1,{}, UNUPDATE}
                                };
};

#endif