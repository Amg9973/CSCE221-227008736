#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string line, filename;
    map <string,int> coronamap;

    ifstream in;
    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);

    string partOf;

    while (in)
    {
        // your implementation here for building coronamap
    }
    
    // your implementation here to print the country with max cases
    // E.g. Most confirmed cases are in USA

    return 0;
}
