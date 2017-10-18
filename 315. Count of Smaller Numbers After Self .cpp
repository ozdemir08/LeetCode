#include <iostream>
#include <map>

using namespace std;

int main(){
	map<int, int> M;
	map<int, int>::iterator itlow;
	M[1] = 2;
	M[2] = 4;
	M[5] = 32;
	M[7] = 128;
	M[10] = 1024;
	itlow = M.lower_bound(3);
	cout << itlow -> first << " " << itlow -> second << endl;
	cout << M.end() - itlow << endl;

	return 0;
}