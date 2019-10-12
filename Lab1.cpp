#include <iostream>
#include <string>
using namespace std;

int main() {
	int counter = 0;
	int number = 0;
	string result = "";
	while (counter < 4) {
		cout << "Type a number from 1 to 255: ";
		cin >> number;
		if (number <= 255 && number >= 1) { 
        	counter += 1;
        	result += to_string(number) + ".";
    	} else {
        	cout << "Number not in {1; 255}" << endl;
    	}
    }
    cout << "Result: " << result.substr(0, result.size()-1);
	return 0;
}
