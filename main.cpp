#include "head.hpp"
#include "AT.hpp"

int main() {

    if (!AutoTest()) {
        std::cout << "Autotests failed!\n";
        return 0;
    }
    else {
        std::cout << "Input 1 to archive:" << std::endl;
        std::cout << "Input 2 to unarchive:" << std::endl;
        
        
        std::cout << "Input 0 to end" << std::endl;
        
        
        
        while(true){
            std::cout << "Input the command" << std::endl;
            int enter;
            std::cin >> enter;
            
            if (enter!=0 && enter != 1 && enter != 2 ) {
                std::cout <<"Error! Unknown command!!!" << std::endl;
                continue;
            }
            if(enter == 0) break;
            
            else if(enter == 1){
                std::cout << "Input file to archive: ";
                std::string file;
                std::cin >> file;
                
                std::cout << "Iput place of zip file: ";
                std::string zip_file;
                std::cin >> zip_file;
                
                zip z1(file, zip_file);
                z1.archivator();
                
                    continue;
                }
                
                
            
            else if(enter == 2){
                std::cout << "Input file to unarchive: ";
                std::string unarch_f;
                std::cin >> unarch_f;
                
                zip z2(unarch_f);
                z2.unarchivator();
            }
           
        }
    }
    return 0;
}
