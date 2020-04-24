#include <fstream>
#include <cctype>
#include <set>
#include <string>
#include <iostream>
#include <vector>      
using namespace std;

template <class I1, class I2, class I3>
void set_diff(I1 B1, I1 E1, I2 B2, I2 E2, I3 D) {
	while (B1 != E1 && B2 != E2) {
		if (*B2 < *B1) { // *B2 not in set 1
			++B2;
		} 
		else if (*B1 < *B2) { // *B1 not in set 2
			*D++ = *B1++;
		} 
		else {
			++B1;
			++B2;
		}
	}
	while (B1 != E1) { 
		*D++ = *B1++; 
	}
}


bool specialChar(char toCheck){
	if ((toCheck == '>') || (toCheck == '<') || (toCheck == '.') || (toCheck == ':') || (toCheck == '(') ||
		(toCheck == ')') || (toCheck == '>') || (toCheck == ';') || (toCheck == '#') || (toCheck == '{') ||
		(toCheck == '}') || (toCheck == '"') || (toCheck == '!') || (toCheck == '\n')){
			return true;
		}
	return false;
}

int main()
{
    string line, filename, word;
    int pos;

    ifstream in;
    set<string> idents;
	set<string> tempIdents;
    set<string> reserved;
    string reserveArray[]= {"for", "if","else", "fstream", "set","string",
        "include", "main", "using", "namespace","std", "iostream", "string", 
        "ifstream","char","auto","size","open","while","return","int","endl"};
    
    for (int i = 0; i <22; i++)
        reserved.insert(reserved.end(),reserveArray[i]);

    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);
	word = "";
	bool ignoring;
	char waitingFor = ' ';
	
    while (in)
    {
        for (int i = 0; i < line.length(); i++){
			char currentChar = line.at(i);
			if ((ignoring && currentChar == waitingFor) || !ignoring){
				ignoring = false;
				if (!ignoring && currentChar == '"'){
					ignoring = true;
					waitingFor = '"';
				}
				if (!isspace(currentChar) && !specialChar(currentChar)){
					word += currentChar;
				}
				else if (word != ""){
					//word = removeSpecial(word);
					tempIdents.insert(tempIdents.end(), word);
					word = "";
				}
			}
		}
		getline(in,line);
    }
	
	set_diff(tempIdents.begin(), tempIdents.end(), reserved.begin(), reserved.end(), inserter(idents, idents.begin()));

    for (auto x:idents)
        cout<<x<<endl;
    return 0;
}
