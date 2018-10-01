/**
 * 
 * 
 * 
 */

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <math.h>
#include <fstream>
#include <cstring>

using namespace::std;

int array[9][9] = { {4, 4, 7, 3, 4, 6, 4, 8, 8, 1}
                    {2, 2, 4, 4, 5, 1, 4, 4, 4, 9}
                    {4, 6, 1, 7, 4, 4, 4, 4, 9, 4}
                    {7, 4, 4, 4, 4, 4, 7, 2, 6, 4}
                    {5, 4, 3, 4, 9, 8, 2, 4, 4, 9}
                    {4, 4, 4, 6, 1, 4, 4, 7, 4, 4}
                    {6, 3, 3, 4, 5, 8, 4, 9, 4, 4}
                    {4, 5, 4, 2, 2, 8, 1, 7, 4, 4}
                    {5, 4, 4, 4, 1, 4, 7, 4, 3}};

//1A
int nSquared(int array[row][col], int majority, ifstream& inputFile){
    int numberArray [9] = 0;
    for (int i=0; i <row; i++){
        for (int j=0; i<col; i++){
            inputFile >> array[i][j];
            if (array[i][j] == i)
                numberArray[i]+= 1;
        }
    }
    for(int k=0; k<=9; k++){
        if (numberArray[kilo] == majority)
            cout << i << " is the majority of this array" << endl;
    }
}

/*1B
int nLogN(int array[row][col], int majority, ifstream& inputFile){

}

//1C
int methodN(int array[row][col], int majority, ifstream& inputFile){

}

*/

int main (int argc, char** argv) {
    ifstream fileIn;
    fileIn.open("Majex1.txt");
    char ch = ' ';
    int rows =0, itemsTotal =0, majority =0, col = 0;

    if (fileIn.fail()){
        cout << "File in Failure."<< endl;
        exit(1);
    }

    //determines the size of the array
    while(fileIn){
        fileIn.get(ch);
        if((ch >= 48) && (ch<= 57))
            itemsTotal++;
        if(ch == '\n')
            rows++;
    }
    col = itemsTotal / (rows) ;
    cout << "Rows: " << rows << endl;
    cout << "Col: " << col << endl;
    cout << "Items: " << itemsTotal << endl;


    //determine majority size of the array
    if (itemsTotal %2 ==0)
        majority = (itemsTotal/2) +1;
    else if (itemsTotal % 2 == 1)
        majority = (itemsTotal+1) /2;
    cout << "Amount to be majority: " << majority << endl;

    //nSquared(array[rows][col], majority, ifstream& inputFile)

    return 0;
}