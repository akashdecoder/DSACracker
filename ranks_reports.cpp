#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int main() {
	int arr[100];
	int size;
	map <int, list<int> > rank_reports;
	map <int, list<int> > ::iterator itr;
	list <int> ::iterator list_itr;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + size);
	
	for (int i = 1; i < size; i++) {
		rank_reports[arr[0]].push_back(arr[i]);
	}
	rank_reports[arr[size-1]].push_back(0);
	for (int i = 1; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			rank_reports[arr[i]].push_back(arr[j]);
		}
	}
	
	
	for (itr = rank_reports.begin(); itr != rank_reports.end(); ++itr) {
		cout << itr->first;
		cout << "--->";
		for (list_itr = itr->second.begin(); list_itr != itr->second.end(); ++list_itr) {
			cout << *list_itr << " ";
		}
		cout << endl;
	}

	return 0;
}