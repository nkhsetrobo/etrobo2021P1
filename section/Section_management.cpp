#include "Section_management.h"


extern Odometer        *gOdometer;
extern Turn            *gTurn;
float Section_management::DIST = 0;
float Section_management::ANG = 0;

Section_management::Section_management()
    :mState(UNDEFINED)
{
    #if defined(MAKE_RIGHT)
        _LEFT = 0;
    #else
         _LEFT = 1;
    #endif

}

bool Section_management::do_run()
{
    switch (mState) {
    case UNDEFINED:
        execUndefined();
        break;
    case ADD_SECTION:
        add_section();
        break;
    case SECTION_RUN:
        section_run();
        break;
    case END_SECTION:
        end_section();
        //return true;
        break;   
    }
    return false;
}

void Section_management::execUndefined()
{
    section_idx = 0;
    mState = ADD_SECTION;
    init();
}

void Section_management::add_section()
{
    if(status[section_idx].walker != -1){
        update(status[section_idx].COMMAND);
        mSection = new Section();
        mSection->set_param(status[section_idx].walker, status[section_idx].w_status,
                            status[section_idx].judge, status[section_idx].j_status);
        //printf("%d\n",status[section_idx].walker);

        mState = SECTION_RUN;

    }else{
        mState = END_SECTION;
    }
}

void Section_management::section_run()
{
    bool fin = mSection->run();
    if (fin == true){
        //printf("%f\n",section_idx);
        mState = ADD_SECTION;

        section_idx++;
    }
}

void Section_management::end_section()
{
    gonext();
    mState = UNDEFINED;
    //printf("%f\n",section_idx);
}

void Section_management::init(){

}

void Section_management::update(int update_dist)
{
    switch(update_dist){
        case UPDATE_DIST:
            DIST = gOdometer->get_value();
            printf("DIST %f\n",DIST);
            break;
        case UPDATE_ANG:
            ANG = gTurn->get_value();
            printf("ANG %f\n",ANG);
            break;
        case UPDATE_ALL:
            DIST = gOdometer->get_value();
            ANG  = gTurn->get_value();
            printf("DIST, ANG %f,%f\n",DIST ,ANG);
            break;
    }
}

void Section_management::gonext(){

}