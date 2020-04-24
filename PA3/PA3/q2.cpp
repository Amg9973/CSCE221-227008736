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

    string country = "";
	string countStr = "";
	int count;
	char currentChar = ' ';
	bool countryCollected = false;
    
	while (in)
    {
		for (int i = 0; i < line.length(); i++){
			currentChar = line.at(i);
			if (!isspace(currentChar)){
				if (!countryCollected){
					country += currentChar;
				}
				else{
					countStr += currentChar;
				}
			}
			else{
				countryCollected = true;
			}
		}
		istringstream(countStr) >> count;
		coronamap[country] = count;
		countryCollected = false;
		country = "";
		count = 0;
		countStr = "";
	    getline(in,line);
    }
    
	map<string,int>::iterator maxIndex = coronamap.begin();
	
	for (map<string,int>::iterator it = coronamap.begin(); it != coronamap.end(); ++it){
		if (it->second > maxIndex->second){
			maxIndex = it;
		}
	}
	
	cout << "Most confirmed cases are in " << maxIndex->first << endl;
	
    return 0;
}
