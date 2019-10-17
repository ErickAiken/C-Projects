#include <iostream>
#include <string>
#include "Utils.h"
#include "Algorithm.h"

int main()
{
    //Create a utility object
    Utils Solver;

    //Loop through to find the first point
    bool sIn = false;
    std::string sPos = "";
    while(!sIn){
        Solver.InputMessage("Start");
        Solver.InputData(sPos);
        if(sPos.length() == 3 && sPos[1] == ',' && Solver.CheckIfDigits(sPos) == true){
            sIn = true;
        }else{
            std::cout<<"\n*Inputs should contain two integers separated by a comma: x,y* \n"<<std::endl;
        }
    }

    //Loop through to find the second point
    bool eIn = false;
    std::string ePos = "";
    while(!eIn){
        Solver.InputMessage("End");
        Solver.InputData(ePos);
        if(ePos.length() == 3 && ePos[1] == ',' && Solver.CheckIfDigits(ePos) == true){
            eIn = true;
        }else{
            std::cout<<"\n*Inputs should contain two integers separated by a comma: x,y*"<<std::endl;
        }
    }

    //Print the strings to confirm the choices with the user
    std::cout<<"\nYou chose a starting position of: "<<sPos<<std::endl;
    std::cout<<"You chose an ending position of: "<<ePos<<std::endl;


    //Return the number of paths
    Algorithm *pAlg;
    std::cout<<"The number of different paths is: "<< pAlg->NumOfPaths(sPos, ePos)<<"\n\n"<<std::endl;

    //Loop again?
    std::string Ans = Solver.CheckForContinue();
    if(Ans == "y"){
        main();
    }

    //end the program
    return 0;
}
