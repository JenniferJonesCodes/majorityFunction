/*
 * 
 * 
 * 
 */

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>

using namespace::std;

char nSquared(vector<char> data){
    int count=0;

    for (int i=0; i < data.size(); i++)
    {
        for(int j=0; j < data.size(); j++)
        {
            if (data[j] == data[i]){
                count++;
            }
        }
        if (count > data.size()/2)
        {
            char result = data[i];
            return result;
        }
        count = 0;
    }
    return '0';
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
    {
        return data[0];
    }

    vector<char> left(data.begin(), data.begin() + data.size()/2);
    vector<char> right(data.begin() +data.size()/2, data.end());

    elemlsub = nLogN(left);
    elemrsub = nLogN(right);

    if (elemlsub == elemrsub)
    {
            return elemlsub;
    }

    lcount = getFrequency(data, elemlsub);
    rcount = getFrequency(data, elemrsub);

    if (lcount > size /2)
    {
        return elemlsub;
    }
    else  if (rcount > size /2)
    {
        return elemrsub;
    }
    else
        return '0';
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
    for (int i=0; i<data.size(); i++)
    {
        if (data[i] == result)
        {
            countCheck++;
        }
    }
    if (countCheck > data.size()/2)
        return result;
    else 
        return '0';
}

void run (string fileName) {
    ifstream fileIn(fileName);
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
    clock_t startTime = clock();
    char result = nSquared(data);
    cout << double( clock() - startTime)/(double)CLOCKS_PER_SEC << " seconds." << endl;
    if (result == '0') 
        cout << "No Majority Element" << endl;
    else 
        cout << result << " is majority element" << endl;    

    cout << "--------------------"<<endl;
    cout <<"nlogn" <<endl;
    startTime = clock();
    result = nLogN(data);
    cout << double( clock() - startTime)/(double)CLOCKS_PER_SEC << " seconds." << endl;
    if (result == '0') 
        cout << "No Majority Element" << endl;
    else 
        cout << result << " is majority element" << endl;    

    cout << "--------------------"<<endl;
    cout <<"n alg" <<endl;
    startTime = clock();
    result = methodN(data);
    cout << double( clock() - startTime)/(double)CLOCKS_PER_SEC << " seconds." << endl;
    if (result == '0') 
        cout << "No Majority Element" << endl;
    else 
        cout << result << " is majority element" << endl;
}

int main (int argc, char** argv) {
    
    cout << "_________Majex1.txt_________" << endl << endl;
    run("Majex1.txt");
    cout << endl << "_________Majex2.txt_________" << endl << endl;
    run("Majex2.txt");
    cout << endl << "_________Majex3.txt_________" << endl << endl;
    run("Majex3.txt");
    cout << endl << "_________Majex4.txt_________" << endl << endl;
    run("Majex4.txt"); 

    return 0;
}