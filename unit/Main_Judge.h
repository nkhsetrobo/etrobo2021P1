#ifndef EV3_UNIT_MAINJUDGE_H_
#define EV3_UNIT_MAINJUDGE_H_

class Main_Judge{
    public:
        Main_Judge();
        bool judge();
        virtual float  get_value();
        void set();


    private:

};

#endif 