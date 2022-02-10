/*
    Auther  : YSSH
    Date    : 09/02/2022

    This program aims to calculate total size of each category files (Music, Image, Movie, and Others).
    
    The program gets input from user through console input stream:
        
        - first line: consists of space separated integers
            T1,T2,T3 ... Tq. Specifies the number of test cases that will run and the subsequent numbers will describe the number of lines for each test case these numbers will be of number Q.
        
        - The next lines will be the test cases, for each test case the number of lines will be T1 .. Tq.
            *valid extensions:
                Music (only extensions: mp3,aac,flac)
                Image (only extensions: jpg,bmp,gif)
                Movie (only extensions: mp4,avi,mkv)
                Others (all other extensions; for example 7z, txt, zip, etc)
    The output tells the total size of each category files for each test case.

*/


#include<iostream>                                                      // for input output stream
#include<string>                                                        // for string
#include<sstream>                                                       // for string stream
#include<vector>                                                        // for vector
#include <cstring>                                                      // strstr       --> to check if substring exists in a string
#include <cctype>                                                       // tolower      --> to convert extensions if uppercase to lower
#include <algorithm>                                                    // transform    --> to apply tolower on a string not just a char

using std::cout;                                                        // cout
using std::cin;                                                         // cin
using std::endl;                                                        // end line
using std::string;                                                      // string
using std::stringstream;                                                // string stream
using std::vector;                                                      // vector
using std::stoi;                                                        // convert string to int

// enum category for file types
enum category{
    Music,
    Image,
    Movie,
    Others
};

int main(void){
    int tstCasesNo = 0;                                                 // number of test cases enters in input stream
    int i = 0;                                                          // counter to loop on test cases
    int j = 0;                                                          // counter to loop on lines in each test case
    int f = Music;                                                      // counter to loop on enum categry
    int **tstCaseCategorySize = NULL;                                   // pointer to pointer to array of test cases to hold size of each category (2D Array)
    int *linesNo = NULL;                                                // pointer to array holding number of lines for the corresponding test case
    string line = "";                                                   // string line from input stream
    string word = "";                                                   // string word from stringstream
    vector<string> *lines = NULL;                                       // pointer to array of vectors, each vector holds the lines of test case
    stringstream s;                                                     // string stream object
    category fileType;                                                  // object of enum
    string ext = "";                                                    // string holding file's extension
    // array of extensions
    string extensions[3]= { "mp3 aac flac ",                            // Music
                            "jpg bmp gif ",                             // Image
                            "mp4 avi mkv "};                            // Movie

    cin >> tstCasesNo;                                                  // get test cases number

    tstCaseCategorySize = new int*[tstCasesNo];                         // allocate test cases
    for(i = 0; i < tstCasesNo; i++){
        tstCaseCategorySize[i] = new int[4]();                          // allocate 4 categories for each test case
    }

    linesNo = new int[tstCasesNo];                                      // allocate the array
    for(i = 0; i < tstCasesNo; i++){
        cin >> linesNo[i];                                              // get number of lines for each test case
    }


    lines = new vector<string>[tstCasesNo];                             // assign by the test case size 
    getline(cin, line);                                                 // problem
    for(i = 0; i < tstCasesNo; i++){
        for(j = 0; j < linesNo[i]; j++){
            getline(cin, line);                                         // getline from cin and assign it in string line
            lines[i].push_back(line);                                   // push line to the vector of test case
        }
    }

    for(i = 0; i < tstCasesNo; i++){
        for(j = 0; j < linesNo[i]; j++){
            /*
                get extension --> substring from the letter after the last "." till the last " " occurance
                substr(indexOfDot + 1, range)    -- range = indexOfWhiteSpace - indexOfDot
            */
            ext = lines[i][j].substr(lines[i][j].rfind(".")+1, lines[i][j].rfind(" ") - lines[i][j].rfind("."));

            if(lines[i][j].rfind(" ") == lines[i][j].length()-1){
                /*  
                    in case user enters space at the end of the line
                    "file.mp3 10b "
                    then take the first word of the obtained extension "mp3 10b "
                */
                s.str(ext);                                             // get stringstream of the extension (wrong extension)
                s >> ext;                                               // get first word which is the wanted extension
                s.clear();                                              // clear the string stream
            }

            transform(ext.begin(), ext.end(), ext.begin(), ::tolower);  //transform any uppercase letter in extension to lowercase

            for(f = Music; f != Others; f++){
                if(strstr(extensions[f].c_str(),ext.c_str())){          // if extensions exists in the giveen array of extensions
                    fileType = (category)f;                             // set filetype by f(counter on the extensions array)
                    break;                                              // break from the loop if extension is found
                }
                fileType = Others;                                      // if not found in the extensions array --> it's Others
            }

            // get file size
            s.str(lines[i][j]);                                         // get stringstream of the line
            while (s >> word);                                          // to get the last word in the line (when separated by spaces)
            tstCaseCategorySize[i][fileType] += stoi(word);             // word = size
            s.clear();                                                  // clear the string stream
        }
    }
 
    // print total size for each test case
    for(i = 0 ; i < tstCasesNo; i++){
        cout<< " music "    << tstCaseCategorySize[i][Music]<<"b"   << " images "  << tstCaseCategorySize[i][Image]<<"b";
        cout<< " movies "   << tstCaseCategorySize[i][Movie]<<"b"   << " other "   << tstCaseCategorySize[i][Others]<<"b"   <<endl;
    }
 
    return 0;
}