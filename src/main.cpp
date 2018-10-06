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
            if (data[j] == data[i]){
                count++;
            }
        }
        if (count >= data.size()/2){
            char result = data[i];
            cout << result << " is the majority of this array" << endl;
            return 0;
        }
    }
    cout << " No majority element found." << endl;
    return 0;
}

int nLogN(vector<char> data&, int start, int end){
    int number = data.size();
    int half = number/2;
    int elem1sub, elemrsub;
    //if only one element return 
    if (number ==1)
        return data(0);
    else
        elem1sub = nLogN(data, 0, data.size()-half);
        elemrsub = nLogN(data, data.size()-half +1, data.size());
        if (elem1sub == elemrsub)
            return elemrsub;
        1count = getFrequency(data, elem1sub);
        rcount = getFrequency(data, elemrsub);
        if (1count > half + 1)
            return elem1sub;
        else  if (rcount > k+1)
            return elemrsub;
        else
            return 0;
}

int getFrequency(vector<char> data, int number) {
    int count =0;
    for(int i= 0; i< data.size(); i++){
        if (data(i)== number)
            count++;
    }
    return count;
}

/*1C
int methodN(int array[row][col], int majority, ifstream& inputFile){

}
*/

int main (int argc, char** argv) {
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
        if (fileIn.eof())
            break;
        if((ch >'0') && (ch <='9'))
        {
            data.push_back(ch);
        }
    }

    cout << "Items: " << data.size() << endl;

    fileIn.close();

    nSquared(data);

    cout << nLogN(data, 0, data.size()) << " is majority element" << endl;

    return 0;
}