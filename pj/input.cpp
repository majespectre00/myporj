#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(int argc,char* argv[]){
string stagename="3_input.txt";
fstream file(stagename.c_str(), ios::out); 
string line;
streambuf* stream_buffer_cout = cout.rdbuf();
streambuf* stream_buffer_cin = cin.rdbuf();
streambuf* stream_buffer_file = file.rdbuf();
cout.rdbuf(stream_buffer_file);
