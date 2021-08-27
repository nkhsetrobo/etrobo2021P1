#ifndef EV3_UNIT_SMSLALOMB_H_
#define EV3_UNIT_SMSLALOMB_H_

#include "Section_management.h"
#include "RandomWalker.h"


class SMslalomb : public Section_management{
    public:
    
        SMslalomb();
        void init();
        void gonext();

    private:
        Main_Section slalombpra[100]={
             {LINETRACER,{30,1,5,50,LEFT,0}, DISTANCE,{300},-1,{}, UPDATE_ALL},
                        
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};
#endif