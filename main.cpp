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

int main() {
    /*ofstream testfile;
    testfile.open("test.bat");
    writeFile(testfile,"REM TEST");
    writeFile(testfile,"@echo test");
    writeFile(testfile,"pause");
    testfile.close();*/

    string input = "";

    println("Select:");



    println("0 - Print lines");
    println("1 - Exit");

    cout << "\n >";
    getline(cin,input);

    if(input == "0") {
        
       cout << "Type in lines to add text to script. Type in \"00exit\" to quit \n >";
       println("Type in \"pause\" to make the script wait for the user to press a key");
        bool run = true;
        vector<std::string> linesv;
        //linesv.push_back("");
        //linesv.push_back();
        linesv.push_back("@echo off");
        string in = "";
        while(run) {
            getline(cin,in);
            if(in == "00exit") {
                run = false;
            }else{
                if(in != "pause") {
                    linesv.push_back("@echo " + in);
                } else {
                    linesv.push_back(in);
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


