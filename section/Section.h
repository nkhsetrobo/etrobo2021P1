#ifndef EV3_UNIT_SECTION_H_
#define EV3_UNIT_SECTION_H_

class Section{
    public:
        Section();
        bool run();
        void init();

    private:
        Walker* mWalker;
        Main_Judge* mMain_Judge;
};