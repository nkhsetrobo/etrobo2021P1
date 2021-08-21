#ifndef EV3_UNIT_SMSLALOM_H_
#define EV3_UNIT_SMSLALOM_H_

#include "Section_management.h"

class SMslalom : public Section_management{
    public:
    
        SMslalom();
        void init();

    private:
        Main_Section lspeedpra[100]={ {WALKER,{0,20}, DISTANCE,{300}, UPDATE_ALL},//280固定
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };
};

#endif