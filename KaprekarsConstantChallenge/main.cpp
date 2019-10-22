
//Coding Challenge
#include <iostream>
#include <string>
#include <array>

int KaprekarsConstant(int value){

    int num = value;
    int Backwards[4];

    //this will take the number and store it in an array
    for(int i = 0; i < 4; i++){
        Backwards[i] = num%10;
        num = (num - Backwards[i])/10;
    }

    //now we need to order the array
    int SmallArr[4] = {Backwards[0], Backwards[1], Backwards[2], Backwards[3]};
    int BigArr[4] = {Backwards[0], Backwards[1], Backwards[2], Backwards[3]};

    //sorting algorithm least to greatest
    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 3; i++){
            if(SmallArr[i + 1] < SmallArr[i]){
                int x = SmallArr[i];
                SmallArr[i] = SmallArr[i + 1];
                SmallArr[i + 1] = x;
            }
        }
    }

    //sorting algorithm greatest to least
    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 3; i++){
            if(BigArr[i + 1] > BigArr[i]){
                int x = BigArr[i];
                BigArr[i] = BigArr[i + 1];
                BigArr[i + 1] = x;
            }
        }
    }

    //integer values
    int BigNum = BigArr[0]*1000 + BigArr[1]*100 + BigArr[2]*10 + BigArr[3];
    int SmallNum = SmallArr[0]*1000 + SmallArr[1]*100 + SmallArr[2]*10 + SmallArr[3];

    value = BigNum - SmallNum;
    return value;

}





int main()
{
    std::cout<<"Enter a number up to four digits long with at least two distinct digits: ";
    int input;
    std::cin>>input;
    std::cout<<"You chose the number: "<<input<<std::endl;

    int Counter = 0;
    bool Lever = true;
    int Value = input;

    while(Lever){
        Value = KaprekarsConstant(Value);
        Counter++;
        if(Value == 6174){
            Lever = false;
        }
        if(Counter > 1000){
            std::cout<<"No convergence after 1000 tries."<<std::endl;
        }

    }

    std::cout<<"Return: "<<Value<<std::endl;
    std::cout<<"Operations: "<<Counter<<std::endl;
}
