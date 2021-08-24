#ifndef EV3_UNIT_SMSLALOM_H_
#define EV3_UNIT_SMSLALOM_H_

#include "Section_management.h"
#include "RandomWalker.h"


class SMslalom : public Section_management{
    public:
    
        SMslalom();
        void init();
        void gonext();

    private:
        Main_Section slalompra[100]={ {ARM,{1,30}, ARMJUDGE,{25}, UNUPDATE},//280固定
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };
};

#endif