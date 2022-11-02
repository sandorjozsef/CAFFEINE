#include <iostream>
#include <fstream>
#include <vector>
#include "parser.h"

using namespace std;
using namespace parsing;

int main(int argc, char* argv[]) {

    cout << "Number of arguments (argc) is " << argc << endl;
    cout << "Program name is " << argv[0];
    cout << "\nOther arguments are: " << endl;
    for (int i = 1; i < argc; i++)
    cout << "\targv[" << i << "] = " << argv[i] << endl;

    string path = argv[1];
    cout << "The given path to file: " << path << endl;

    ifstream inFile( path, ios::binary);
	if (!inFile) 
	{
		cerr << "\n File " << path << " did not open" << endl;
        return 1;
	}

    vector<char> bytes((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));

    inFile.close();

    try{
        Parser parser;
        parser.process(bytes);
    }
    catch(const char* msg){
        cerr << msg << endl;
    }
    catch(...){
        cerr << "Caught an exception.";
    }
    



    cout << endl;
    return 0;
}
