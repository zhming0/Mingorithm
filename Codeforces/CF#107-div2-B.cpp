#include <iostream>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;
string name[110];
int judge(string s)
{
	bool flag = true;
	for (int i=1; i<s.length(); i++) {
		if (s[i] != s[i-1]) {
			flag = false;
			break;
		}
	}
	if (flag) return 0;
	flag = true;
	for (int i=1; i<s.length(); i++) {
		if (s[i] >= s[i-1]) {
			flag = false;
			break;
		}
	}
	if (flag) return 1;
	return 2;
}
int main(int argc, char *argv[]) {
	int n, m;
	cin >> n;
	int max_girl=-1, max_taxi=-1, max_pizza=-1;
	vector<int> idx1, idx2, idx3;
	for (int i=0; i<n; i++) {
		cin >> m >> name[i];
		int tmp_girl = 0, tmp_taxi = 0, tmp_pizza = 0;
		for (int j=0; j<m; j++) {
			string tmp;
			cin >> tmp;
			tmp.erase(tmp.begin()+2);
			tmp.erase(tmp.begin()+4);
			int tmp_ret = judge(tmp);
			if (tmp_ret == 0) tmp_taxi++;
			if (tmp_ret == 1) tmp_pizza++;
			if (tmp_ret == 2) tmp_girl++;
		}
		//printf("%d %d %d\n", tmp_girl, tmp_taxi, tmp_pizza);
		if (tmp_girl > max_girl) {
			max_girl = tmp_girl;
			idx1.clear();
			idx1.push_back(i);
		} else if (tmp_girl == max_girl) 
			idx1.push_back(i);
			
		if (tmp_taxi > max_taxi) {
			max_taxi = tmp_taxi;
			idx2.clear();
			idx2.push_back(i);
		} else if (tmp_taxi == max_taxi) 
			idx2.push_back(i);
			
		if (tmp_pizza > max_pizza) {
			max_pizza = tmp_pizza;
			idx3.clear();
			idx3.push_back(i);
		} else if (tmp_pizza == max_pizza) 
			idx3.push_back(i);
	}
	cout << "If you want to call a taxi, you should call: ";
	for (int i=0; i<idx2.size()-1; i++) 
		cout << name[idx2[i]] << ", ";
	cout << name[idx2[idx2.size()-1]] << "." << endl;
	
	cout << "If you want to order a pizza, you should call: ";
	for (int i=0; i<idx3.size()-1; i++) 
		cout << name[idx3[i]] << ", ";
	cout << name[idx3[idx3.size()-1]] << "." << endl;
	
	cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
	for (int i=0; i<idx1.size()-1; i++) 
		cout << name[idx1[i]] << ", ";
	cout << name[idx1[idx1.size()-1]] << "." << endl;
		
	return 0;
}