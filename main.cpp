#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void writeFile(std::ofstream& filetext,string message,bool close) {
    if(filetext.is_open()) {
        filetext << message << endl;
        if(close) {
            filetext.close();
        }
    }
}

void writeFile(ofstream& filetext,string message) {
    writeFile(filetext,message,false);
}

template <typename T>
void println(T const & value){
    // value is of some type T, which can be any type at all.
    cout << value << endl; 
}

string FirstWord(const string& line) {
    return line.substr(0, line.find(' '));
}

int main() {
    string input = "";

    println("Select:");



    println("0 - Print lines");
    println("1 - Exit");

    cout << "\n >";
    getline(cin,input);

    if(input == "0") {
        
       cout << "Type in lines to add text to script. Type in \"00exit\" to quit \n >";
       println("Type in \"00help\" for commands that can be used");
        bool run = true;
        vector<std::string> linesv;
        linesv.push_back("@echo off");
        string in = "";
        while(run) {
            getline(cin,in);
            if(in == "00exit") {
                run = false;
            }else if(in == "00help") {
                println("pause - makes the user wait for a key to be pressed");
                println("exit - makes the script shutdown");
                println("cleart - Clears the text");
                println("time {amount of time in seconds} - Makes the user wait for specified time\n NOTE: A timeout value of -1 means to wait indefinitely for a key press.");
            } else{
                if(in == "pause") {
                    linesv.push_back(in);
                    
                } else
                if(FirstWord(in) == "time") {

                    string timething = in.substr(in.find(' ') + 1);

                    if(!timething.empty()) {
                        linesv.push_back("timeout /t " + timething + " /NOBREAK");
                    }else{
                        println("YOU FORGOT TO SET THE TIME!");
                    }

                } else if(in == "cleart") {

                    linesv.push_back("cls");

                } else if(in == "exit") {
                    linesv.push_back("exit");
                } else if(in != ""){
                    linesv.push_back("@echo " + in);
                }
            }
        }
            ofstream textfile;
            textfile.open("script.bat");
        for(int i = 0;i < linesv.size();i++) {
            string message = linesv.at(i);
            writeFile(textfile,message);
        }
        
        textfile.close();

        println("Finished writing to batch file. You may now run it.");
        system("pause");
    }




    return 0;
}


