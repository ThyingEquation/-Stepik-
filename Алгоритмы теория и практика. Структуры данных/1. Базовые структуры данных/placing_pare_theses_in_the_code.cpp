#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector <pair<char, int>> arr;

	int i;
	char x;

	for (i = 0; (x = cin.get()) != '\n';) {

		if (x == '(' || x == '[' || x == '{') {
		
		arr.push_back(make_pair(x, i));
		
		}

		else if (x != '(' && x != ')' && x != '[' && x != ']' && x != '{' && x != '}') {

		}

		else if (arr.size() == 0 || (arr[arr.size()-1].first == '(' && x != ')') || (arr[arr.size()-1].first == '{' && x != '}') || (arr[arr.size()-1].first == '[' && x != ']')) {

			cout << ++i;
			return 0;
		}

		else {

			arr.pop_back();
		}

		i++;
	}


	if (arr.size() == 0) {

		cout << "Success" << endl;


	else {

		cout << arr[arr.size() - 1].second + 1;
	}

	return 0;
}
