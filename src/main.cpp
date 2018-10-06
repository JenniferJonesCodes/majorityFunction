/**
 * 
 * 
 * 
 */

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace::std;


int nSquared(vector<char> data){
    int count=0;
    for (int i=0; i < data.size(); i++)
    {
        for(int j=0; j< data.size(); j++)
        {
            if (data[i] == data[j]){
                count++;
            }
        }
        if (count >= data.size()/2){
            char result = data[j];
            cout << result << " is the majority of this array" << endl;
        }
    }
}

/*
1B
int nLogN(int array[row][col], int majority, ifstream& inputFile){

}

//1C
int methodN(int array[row][col], int majority, ifstream& inputFile){

}
*/

int main (int argc, char** argv) {
    ifstream fileIn;
    ifstream fileIn("Majex1.txt");
    char ch;

    if (fileIn.fail())
    {
        cout << "File in Failure."<< endl;
        exit(1);
    }

    vector<char> data;

    //fills array
    while(fileIn)
    {
        ch = fileIn.get();
        if (fileIn.eof(0))
            break;
        if((ch >'0') && (ch <='9')
        {
            data.push_back(ch);
        }
    }

    cout << "Items: " << data.size() << endl;

    fileIn.close();

    return 0;
}