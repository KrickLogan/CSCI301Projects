#include <iostream>
using namespace std;

bool search(const int arr[], int size, int target) {
	if (size < 0) {
		cout << "not found" << endl;
		return false;
	}
	else if(arr[size]==target){
		cout << "found" << endl;
		return true;
	}
	else {
		return search(arr, size-1, target);
	}
}

int main() {
	int userTarget;

	int arr[9] = { 12, 6, 5, 2, 27, 17, 8, 19, 13 };
	cout << "Enter the target: ";
	cin >> userTarget;
	search(arr, 9, userTarget);

	system("pause");
	return 0;
}