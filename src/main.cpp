/*
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

int getFrequency(vector<char> data, char number) {
    int count =0;
    for(int i =0; i <data.size(); i++){
        if (data[i] ==number)
            count++;
    }
    return count;
}

char nLogN(vector<char> data){
    int size = data.size();
    char elemlsub, elemrsub;
    int rcount=0, lcount=0;
    if (size==1)
        return data[0];
    else
    {
        vector<char> left(data.begin(), data.begin() + data.size()/2);
        vector<char> right(data.begin() +data.size()/2, data.end());
        elemlsub = nLogN(left);
        elemrsub = nLogN(right);
        if (elemlsub == elemrsub)
             return elemlsub;
        lcount = getFrequency(data, elemlsub);
        rcount = getFrequency(data, elemrsub);
        if (lcount > (size/2 +1))
             return elemlsub;
        else  if (rcount > (size/2 +1))
             return elemrsub;
        else
            return '0';
    }
}

char methodN(vector<char> data){
    int majIndex =0, count =1;
    for (int i =1; i <data.size()-1; i++)
    {
        if (data[majIndex] == data[i])
            count++;
        else   
            count --;
        if (count ==0)
        {
            majIndex = i;
            count = 1;
        }
    }
    char result = data[majIndex];
    int countCheck =0;
    for (int i=0; i<data.size(); i++){
        if (data[i] == result){
            countCheck++;
        }
    }
    if (countCheck >= data.size()/2)
        return result;
    else 
        return '0';

}

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
    cout << "--------------------"<<endl;
    cout <<"nsquared" <<endl;
    nSquared(data);

    cout << "--------------------"<<endl;
    cout <<"nlogn" <<endl;
    cout << nLogN(data) << " is majority element" << endl;

    cout << "--------------------"<<endl;
    cout <<"n alg" <<endl;
    cout << methodN(data) << " is majority element" << endl;

    return 0;
}