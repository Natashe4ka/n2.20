#include "AT.hpp"

int AutoTest1(){
    std::string path = "/Users/nataliasafonova/Desktop/c++3/task2_20"; // путь к папке где test.bmp
    
    std::fstream file(path + "/ATtest.bmp", std::ios_base::binary | std::ios_base::in);
    file.seekg(0, std::ios::end);
    int64_t SIZE = file.tellg();
    file.close();


    zip z(path+"/ATtest.bmp", path);
    z.archivator();

    file.open(path+"ATtest.bmp_zip.myzip", std::ios_base::binary | std::ios_base::in);
    file.seekg(0, std::ios::end);
    int64_t size = file.tellg();

    if(SIZE > size) return 1;
    else return 0;
}

int AutoTest2(){
    std::string path = "/Users/nataliasafonova/Desktop/c++3/task2_20"; // путь к папке где test.bmp
    
    std::fstream file(path + "/ATtest.bmp_zip.myzip", std::ios_base::binary | std::ios_base::in);
    file.seekg(0, std::ios::end);
    int64_t size = file.tellg();
    file.close();


    zip z(path+"/ATtest.bmp_zip.myzip");
    z.unarchivator();

    file.open(path+"/new_ATtest.bmp", std::ios_base::binary | std::ios_base::in);
    file.seekg(0, std::ios::end);
    int64_t SIZE = file.tellg();

    if(SIZE > size) return 1;
    else return 0;
}

int AutoTest(){
    
    if(!AutoTest1()){
        std::cout << "AutoTest1 failed." << std::endl;
    }
    
    if(!AutoTest2()){
        std::cout << "AutoTest2 failed." << std::endl;
    }
     
    if( AutoTest1() && AutoTest2()) return 1;
    else return 0;

}

