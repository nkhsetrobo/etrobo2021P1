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
             {WALKER,{0,0},DISTANCE,{1},-1,{}},
                        
            {-1,{}, -1,{}, UNUPDATE}
                                };
};

#endif