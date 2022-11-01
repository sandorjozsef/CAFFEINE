#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    cout << "Number of arguments (argc) is " << argc << endl;
    cout << "Program name is " << argv[0];
    cout << "\nOther arguments are: " << endl;
    for (int i = 1; i < argc; i++)
    cout << "\targv[" << i << "] = " << argv[i] << endl;

    string path = argv[1];
    cout << "The given path to file: " << path << endl;

    ifstream input(path, std::ios::binary);
    vector<char> bytes( (istreambuf_iterator<char>(input)), (istreambuf_iterator<char>()));
    input.close();

    cout << "\nThe content of the file: \n\n";
    for (int i = 0; i < 200; i++){
        cout << bytes[i];
    }
    cout << "\n ... \n";



    cout << endl;
    return 0;
}
