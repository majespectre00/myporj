#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class compareresult{
public:
void mainCompare(string,string);
};
void compareresult::mainCompare(string answerfile,string userfile)
{
    answerfile="mode3\\allans\\"+answerfile+"ans.txt";
    userfile+="input.txt";
    ifstream answer(answerfile.c_str());
    ifstream user(userfile.c_str());
    string answerall,resulttemp;
    string userall,usertemp;
    while(getline(user,userall))
    {
        usertemp+=userall+"\n";
    }
    user.close();
    user.clear();
    while(getline(answer,answerall))
    {
       resulttemp+=answerall+"\n";
    }
    answer.close();
    answer.clear();
    cout<<"--------------------Expect-----------------\n";
    cout<<resulttemp;
    cout<<"---------------------GOT-------------------\n";
    cout<<usertemp;
    cout<<"--------------------Result-----------------\n";
    if(usertemp==resulttemp)
    cout<<"True\n";
    else
    cout<<"False\n";
}
