#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	ifstream file("data");
	string num;
	long long total = 0;

	while(getline(file, num)){
		int last = -1;
		string cmax = "";
		vector<int> nir;
		for (char c : num) nir.push_back(c - '0');

		for (int i = 0; i < 12; i++){
			int x = distance(nir.begin(), max_element(nir.begin() + last + 1, nir.begin() + 1 + (nir.size() - (12 - cmax.length()))));
			last = x;
			cmax += to_string(nir[x]);
			nir[x] = 0;
		}
		total += stoll(cmax);
	}

	std::cout << total << '\n';
}
