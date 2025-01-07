#include <iostream>
using std::cout;
using std::endl;
int main() {
	int n = 5;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}
