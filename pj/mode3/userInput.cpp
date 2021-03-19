#include<iostream>
#include<fstream>

using namespace std;
class userInput{
public:
void firstinclude(string);
void userinclude();
void lastinclude();
};
void userInput::firstinclude(string stagename)
{

    ofstream filewritter("input.cpp");
    filewritter<<"#include<iostream>\n#include<fstream>\n#include<string>\n#include<cmath>\n#include<cstdlib>\nusing namespace std;\nint main(int argc,char* argv[]){\n";
    filewritter<<"string stagename=\""<<stagename<<"input.txt\";";
    if (stagename == "5_")
    {
        filewritter << "\nint data[10]={40,35,50,60,75,95,69,88,70,242};";
    }
    filewritter<<"\nfstream file(stagename.c_str(), ios::out); \nstring line;\n";
    filewritter<<"streambuf* stream_buffer_cout = cout.rdbuf();\n"
    << "streambuf* stream_buffer_cin = cin.rdbuf();\n"
    << "streambuf* stream_buffer_file = file.rdbuf();\n"
    << "cout.rdbuf(stream_buffer_file);\n";
    filewritter.close();
}
void userInput::userinclude()
{
    string textline;
    ofstream filewritter("input.cpp",ios::app);
    int i=1;
    while ((getline(cin,textline))&&textline!="exit")
    {
       
       
        if( textline.substr(0, textline.find(">>"))=="cin")
        {
            textline.erase(0, 5);
            textline=textline.substr(0, textline.find(";"));
            textline=textline+"=atoi(argv["+to_string(i)+"]);";
            i++;
        }
        filewritter<<textline;
        filewritter<<"\n";
    }
    filewritter.close();
}
void userInput::lastinclude()
{
    ofstream filewritter("input.cpp",ios::app);
    filewritter<<"file.close();\nreturn 0;\n}";
    filewritter.close();
}