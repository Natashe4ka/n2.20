#ifndef zip_hpp
#define zip_hpp

#include <iostream>
#include <fstream>

class zip{
private:
    std::string inp_file;   // файл, для архивирования
    std::string out_file;
    
    std::string unarch_f;
public:
    zip (){
        inp_file = "";
        out_file = "";
        unarch_f = "";
    }
    zip (const std::string inp, const std::string out ) {
        inp_file = inp;
        out_file = out;
        unarch_f = "";
    }
    zip (const std::string un) {
        unarch_f = un;
        inp_file = "";
        out_file = "";
    }

    
    std::string get_file_name (std::string);
    
    void archivator ();
    void unarchivator ();
    
};


#endif

