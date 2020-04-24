#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;

int insertLinear(int x, vector<int> & linear);
int insertQuad(int x, vector<int> & quad);
int insertDuble(int x, int dubHash, vector<int> & duble);

int main()
{
  int linCollides=0;
  int quadCollides= 0;
  int dubCollides = 0;
  int quadInc;
  int tableSize;
  bool fail = false;
  int x, count=0;
  int doubleHash;

  srand(time(NULL));
  cout<<"enter the size of the table ";
  cin>>tableSize;
  vector<int> linear(tableSize,-1);//initalize each table to -1 for empty
  vector<int> quad(tableSize,-1);  //initalize each table to -1 for empty
  vector<int> duble(tableSize,-1);  //initalize each table to -1 for empty
  do{
   doubleHash = rand()%tableSize;
  }while (doubleHash < tableSize/10 && doubleHash%tableSize==0);

  while(count < tableSize && !fail)
  {
    x= rand()%tableSize;// value to insert
	//cout << "x = " << x << endl;
	quadInc=insertQuad(x,quad);
	if (quadInc < 0)
		fail = true;
	else
	{
	 quadCollides += quadInc;
	 linCollides+=insertLinear(x,linear);
	 dubCollides+=insertDuble(x, (rand()%tableSize), duble);
	}
	//cout << "Count = " << count << endl;
	count++;
  }
  cout<<"Num linear collides "<<linCollides<<endl;
  cout<<"Num quadratic collides "<<quadCollides<<endl;
  cout<<"Num double hash collides "<<dubCollides<<endl;
  return 0;
}

int insertLinear(int x, vector<int> & linear)
{
  bool inserted = false;
  int collisions = 0;
  int insertPos = x % linear.size();
  while (!inserted){
	if (linear[insertPos] == -1){
		linear[insertPos] = x;
		inserted = true;
	}
	else{
		collisions += 1;
		//cout << "collision" << endl;
		insertPos = (insertPos + 1) % linear.size();
	}
  }
  //cout << "inserted " << x << " at " << insertPos << endl;
  return collisions;
}

int insertQuad(int x, vector<int> & quad)
{
  bool inserted = false;
  int collisions = 0;
  int insertPos = x % quad.size();
  while (!inserted){
	if (quad[insertPos] == -1){
		quad[insertPos] = x;
		inserted = true;
	}
	else{
		collisions += 1;
		//cout << "collision" << endl;
		insertPos = (insertPos + (collisions^2)) % quad.size();
	}
  }
  //cout << "inserted " << x << " at " << insertPos << endl;
  return collisions;
}

int insertDuble(int x, int dubHash, vector<int> & duble)
{
  //bool inserted = false;
  int collisions = 0;
  int insertPos = (x + collisions * dubHash)%duble.size();
  while (collisions < duble.size()){
	if (duble[insertPos] == -1){
		duble[insertPos] = x;
		return collisions;
		//inserted = true;
	}
	else{
		collisions += 1;
		//cout << "collision" << endl;
		//cout << "Trying to insert at " << insertPos << endl;
		//cout << "But duble[" << insertPos << "] is occupied by " << duble[insertPos] << endl;
		insertPos = (x + collisions * dubHash) % duble.size();
		//cout << "dubHash = " << dubHash << endl;
		//cout << "Trying to insert at " << insertPos << endl;
	}
  }
  //cout << "inserted " << x << " at " << insertPos << endl;
  return collisions;
}
