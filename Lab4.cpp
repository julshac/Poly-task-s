#include <iostream>
#include <string>
using namespace std;

int main() {
	string values;
	getline(cin, values);
	
	string _template;
	getline(cin, _template);
	
	size_t starter = 0;
	size_t lClose = _template.find('[', starter);
	size_t rClose = _template.find(']', starter + 1);
	
	string pat, key, val;
	size_t fChar, lChar, possition;

	while (lClose != string::npos && rClose != string::npos) {

		pat = _template.substr(lClose + 1, rClose - lClose - 1);
		key = pat + '=';
		fChar = values.find(key);
		lChar = values.find(',', fChar);
		if (fChar != string::npos) {
			if (lChar == string::npos)
				lChar = values.size();
			possition = fChar + key.size();
			val = values.substr(possition, lChar - possition);
			_template.replace(lClose, rClose - lClose + 1, val);
		}
		starter = rClose + 1;
		lClose = _template.find('[', starter);
		rClose = _template.find(']', starter + 1);
    	}
	
	cout << _template << "\n";
	return 0;
}
