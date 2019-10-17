#include "Utils.h"
#include <iostream>
#include <string>
#include <cstdlib>

Utils::Utils(){
        std::cout<<"\n************************************" << std::endl;
        std::cout<<"Welcome to the Chessboard Challenge! \n" << std::endl;
}

//**************************************************************************//

Utils::InputMessage(std::string cmd){

    if(cmd == "Start"){
        std::cout<<"Choose a starting point (x,y) between #1-8. "<<std::endl;
    }else if(cmd == "End"){
        std::cout<<"\nChoose an ending point (a,b) between #1-8. "<<std::endl;
    }else{
        std::cout<<"Error: Incorrect format for Input Message";
    }
}

//**************************************************************************//

bool Utils::StrLenCheck(std::string str1, std::string str2){

    if(str1.length() == 3 && str2.length() == 3){
        return true;
    }else if(str1.length() != 3 || str2.length() != 3){
        return false;
    }
}

//**************************************************************************//

void Utils::InputData(std::string &Str){
    std::cin>>Str;
}

//**************************************************************************//

bool Utils::CheckIfDigits(std::string x){

    if(isdigit(x[0]) && isdigit(x[2])){
       return true;
    }else{
        return false;
    }
}

//**************************************************************************//

std::string Utils::CheckForContinue(){
    std::string y_n;
    std::cout<<"Would you like to continue? (y/n)"<<std::endl;
    std::cin>>y_n;
    return y_n;
}


