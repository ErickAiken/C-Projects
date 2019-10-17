#include "Algorithm.h"
#include <iostream>
#include <string>
#include <math.h>

Algorithm::NumOfPaths(std::string str1, std::string str2){

    //Get the x and y values separately
    int x = ConvertChar2Int(str1[0]);
    int y = ConvertChar2Int(str1[2]);

    int a = ConvertChar2Int(str2[0]);
    int b = ConvertChar2Int(str2[2]);

    //find the point closest to the origin
    int r1 = sqrt(x*x + y*y);
    int r2 = sqrt(a*a + b*b);

    //Check for each case and return appropriately
    if(r1 < r2){
        int Horizontal = a - x;
        int Vertical = b - y;
        return Combinatorial(Horizontal + Vertical, Horizontal);
    }else if(r2 < r1){
        int Horizontal = x - a;
        int Vertical = y - b;
        return Combinatorial(Horizontal + Vertical, Horizontal);
    }else if(r1 == r2){
        //check if they are the same point
        return 0;
    }

}

//**************************************************************************//

Algorithm::ConvertChar2Int(char t){
    return t-'0';
}

//**************************************************************************//

Algorithm::Combinatorial(int alpha, int beta){

    int numerator = Factorial(alpha);
    int denominator = Factorial(beta)*Factorial(alpha - beta);
    return numerator/denominator;
}

//**************************************************************************//

Algorithm::Factorial(int gamma){
int Total = 1;
for(int i = gamma; i > 0; i--){
    Total *= i;
    }
return Total;
}
