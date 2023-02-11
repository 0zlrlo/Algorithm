#include <iostream>
#include <map>
using namespace std;
map<string, int> mapset;
int main(void) {
string Alice;
	mapset.insert({ "Alice", 100 });
	mapset.insert({ "Bob", 200 });
    mapset["Alice"]=100;

	if (mapset.find("Alice") != mapset.end()) 
	{
		cout << mapset[Alice] << endl;
	}
	else {
		cout << "not find" << endl;
	}

	//인덱스기반
	for (auto iter = mapset.begin() ; iter !=  mapset.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}
	cout << endl;

	//범위기반
	for (auto iter : mapset) {
		cout << iter.first << " " << iter.second << endl;
	}

	return 0;
}
