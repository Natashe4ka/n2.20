#include "zip.hpp"
int pow_(int n) {
  return 1<<n;
}
   
    std::string zip::get_file_name (std::string file) {
        return file.substr(file.find_last_of("/")+1, file.size()); //подстрока строки файла (индекс последнего слеша, индекс последнего символа)
    }
    
    void zip::archivator () {
        std::ifstream file (inp_file, std::ios_base::binary);//to open all type of files in binary
        std::ofstream zip_file (out_file + "/" + get_file_name(inp_file) + "_zip.myzip", std::ios_base::binary);//путь к файлу+ его новое имя
        //архиватор
        
        if (!file) {
            std::cout << "Error! Cannot open file!" << std::endl;
            return;
        }
        
        
        char c;
        std::fstream help_file (out_file + "/" + "h.txt", std::ios_base::binary |std::ios_base::out);
        
        
        while (file.get(c)) {
            std::bitset<8>bit(c) ;
            help_file << bit.to_string() ;
          
        }
        
        help_file.close();
        help_file.open(out_file + "/" + "h.txt", std::ios_base::binary | std::ios_base::in);
        
        int count = 1;
        char bef='0';
        help_file.get(c);
        bef = c;

        zip_file << bef << " ";

        while (true) {
            if (help_file.eof()) {
                zip_file << count-1 <<" ";
                
                break;
            }
            else {
                help_file.get(c);
                if (bef==c) {
                    count ++;
                }
                else {
                    zip_file << count <<" ";
                    bef = c;
                    count = 1;
                    }
        }
        }
        help_file.close();
        remove((out_file + "/" + "h.txt").c_str());

        file.close();
        zip_file.close();
    }
    


void zip::unarchivator () {
    std::ifstream file (unarch_f, std::ios_base::binary);//to open all type of files in binary
    //std::ofstream unzip_file (unarch_f.substr(0, unarch_f.find_last_of('_')), std::ios_base::binary);//путь к файлу+ его новое имя
    //разархиватор
    std::string str = unarch_f.substr(unarch_f.find_last_of('/')+1, unarch_f.size());
    str = str.substr(0, str.find_last_of('_'));
    std::ofstream unzip_file (unarch_f.substr(0, unarch_f.find_last_of('/')) + "/new_" + str , std::ios_base::binary);
    //std::cout<<str<<std::endl;
    std::fstream help_file (unarch_f.substr(0, unarch_f.find_last_of('/'))+"/h1.txt", std::ios_base::binary | std::ios_base::out);
    int get;
    int first;
    file >> first ;
    
    while (true) {
        if (file.eof()) break;
        file >> get;
        if (first == 0) {
            std::string str (get, '0');

            help_file << str;
            first = 1;
        }
        else if (first == 1) {
            std::string str (get, '1');
            help_file << str;
            first = 0;
        }

    }
    
    help_file.close();
    //work
    
    
    help_file.open(unarch_f.substr(0, unarch_f.find_last_of('/'))+"/h1.txt", std::ios_base::binary | std::ios_base::in);//
    help_file.seekg (0, std::ios::end);
    int64_t size = help_file.tellg(); //lenght
    help_file.close();
    help_file.open(unarch_f.substr(0, unarch_f.find_last_of('/'))+"/h1.txt", std::ios_base::binary | std::ios_base::in);
    size-=get;
    
    char arr [8];
    int num=0;
    
    for (int i=0; i<size/8; i++) {
        for(int j = 0; j < 8; j++){
            help_file.get(arr[j]);
        }
        
        for (int q=7; q>-1; q--) {
            
           if (arr[q] == '1')
            num += pow_(7-q);

        }
        
        
        unzip_file << char(num);
        num=0;
    }
    help_file.close();
    remove((unarch_f.substr(0, unarch_f.find_last_of('/'))+"/h1.txt").c_str());
    //std::cout<<std::endl;
    file.close();
    unzip_file.close();
}



