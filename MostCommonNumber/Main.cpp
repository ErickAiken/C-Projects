#include <iostream>
#include<unordered_map>

//Prototyping
void mostFrequentValue(int values[], int numValues, int& result, int& resultFreq);
void printValues(int arr[], int num);

//The purpose of this program is to find the most common number in an array of values.
int main()
{

    //Define the array of values and store the total number of entries.
    int values[10] = {1, 4, 2, 3, 12, 5, 10, 9, 10, 10};
    int numValues = sizeof(values)/sizeof(values[0]);

    //print out the values in the terminal.
    printValues(values, numValues);

    //Run the method.
    int resultValue = -1;
    int resultFreq  = -1;
    mostFrequentValue(values, numValues, resultValue, resultFreq);

    if(resultFreq > 1){
        std::cout<< "The most frequent value is: "<<resultValue<<std::endl;
        std::cout<< "Frequency: "<<resultFreq<<std::endl;
    }else{
        std::cout<<"Each value is unique."<<std::endl;
    }

}//end Main


void mostFrequentValue(int values[], int numValues, int& resultValue, int& resultFreq){

    //Declare processing...
    std::cout<<"Finding the most frequent value..."<<std::endl<<"\n";

    //Create a storage container to catalog the values.
    std::unordered_map<int, int> catalog;

    //Iteratively check each value in the list.
    for(int i = 0; i != numValues; i++){
        if(catalog.find(values[i]) == catalog.end()){
            catalog.insert(std::make_pair(values[i], 1));
        }else{
            catalog[values[i]]++;
        }
    }//end For

    //Search the catalog for the largest frequency.
    for(auto iter = catalog.begin(); iter != catalog.end(); iter++){
        if(iter->second > resultFreq){
            resultFreq = iter->second;
            resultValue = iter->first;
        }
    }//end For

}//end mostFrequentValues


void printValues(int arr[], int num){
    std::cout<<"List of values: "<<"[";
    for(int j = 0; j != num; j++){
        std::cout<<arr[j];
        if(j != num -1){
            std::cout<<",";
        }else{
            std::cout<<"]"<<std::endl;
            std::cout<<"\n";
        }
    }//end For

}//end printValues
