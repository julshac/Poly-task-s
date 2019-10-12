#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string values;
	getline(cin, values);
	
	string _template;
	getline(cin, _template);
	
	vector<string> words;
	int firstIndex, lastIndex;
	bool wordFlag = false;
	for (int i = 0; i < _template.size(); i++) {
		if (_template[i] == '[') {
			wordFlag = true;
			firstIndex = i;
		}
		else if (_template[i] == ']') {
			wordFlag = false;
			words.push_back(_template.substr(firstIndex + 1, i - firstIndex));
		}
	}
	
	vector<string> wordsValues;
	for (int i = 0; i < values.size(); i++) {
		if (values[i] == '=') {
			wordFlag = true;
			firstIndex = i + 1;
		}
		else if (values[i] == ',') {
			wordFlag = false;
			wordsValues.push_back(values.substr(firstIndex, i - firstIndex));
		}
	}
	wordsValues.push_back(values.substr(firstIndex, values.size() - firstIndex));
	
	string output;
	unsigned int vector_size = words.size();
	for (int i = 0; i < vector_size; i++) {
		_template.replace(_template.find(words[i]) - 1, words[i].length() + 1, wordsValues[i]);
    }
	
	cout << _template << "\n";
	return 0;
}
