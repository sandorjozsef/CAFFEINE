#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void parse(vector<char> bytes){

    cout << "\nThe content of the file: \n\n";

    int ID = bytes[0];
    if ( ID >= 1 && ID <= 3){
        cout << "ID = " << ID << endl;
    }
    else{
        throw "Invalid ID";
    }

    // TODO: int is enough for 8 byte integer
    // TODO: checking long enough the bytes vector ??
    int length = 0;
    for (int i = 0; i < 8; i++){
        length += (bytes[i+1] << (i * 8)); // bit shifting
    }
    
    cout << "length = " << length;

    // switch case ID = 1, 2, 3 ...
    
}

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
        parse(bytes);
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
