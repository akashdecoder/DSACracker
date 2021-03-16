#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <list>
#include <cstdbool>
#include <iomanip>

using namespace std;

int main() {
	string number_string, dup_string="";
	cin >> number_string;
	bool flag = false;
	int final_length;
	int zero_count = 0;
	
	if (number_string[0] == '-' && number_string[1] == '0') {
		flag = true;
		for (int a = 1; a < number_string.size(); a++) {
			dup_string += number_string[a];
		}
		zero_count += 1;
		for (int i = 2; i < number_string.size(); i++) {
			if (number_string[i] != 0) {
				break;
			}
			else {
				zero_count += 1;
			}
		}
	}
	
	if (flag == true) {
		final_length = dup_string.size();
		stringstream ss(dup_string);
		int x = 0;
		ss >> x;
		cout<<"-" << setw(final_length) << setfill('0') << x;
	}
	else {
		final_length = number_string.size();
		stringstream ss(number_string);
		int x = 0;
		ss >> x;
		cout << setw(final_length) << setfill('0') << x;
	}
	
	return 0;
}