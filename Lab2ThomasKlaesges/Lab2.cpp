#include <vector>
#include <iostream>
#include <string>
using namespace std;

const string keyWord{ "hello world" };


vector<char> encode(string s, int val) {
	//Copies the string into a vector
	vector<char>encoded(s.size());
	for (int i = 0; i < s.size(); i++) {
		encoded.push_back(s[i]);
	}
	char firstChar;
	char secondChar;
	vector<char> superCoded;
		for (int i = 0; i < val; i++) {
			//Select two random letters
			firstChar = 'a' + rand() % 26;
			secondChar = 'a' + rand() % 26;

			//cout << "Random letter: " << firstChar << " " << secondChar << endl; this line was for testing

			//Swapping the letters to encode
			for (int i = 0; i < encoded.size(); i++) {
				if (encoded.at(i) == firstChar) {
					encoded.at(i) = secondChar;
				}
				if (encoded.at(i) == secondChar) {
					encoded.at(i) = firstChar;
				}
			}
			//for (int i = 0; i < encoded.size(); i++) {  this for loop also for testing
			//	cout << encoded.at(i);
			//}
			//cout << endl;

		}
		return encoded;

}

void decode(vector<char> vec) {
	cout << "Current code: ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i);
	}
	cout << endl;
	cout << "Enter two letters to swap: ";
	string currKey;
	string done;
	char first;
	char second;
	cin >> done;
	first = done[0];
	while (done != "done") {
		cin >> second;

		for (int i = 0; i < vec.size(); i++) {
			if (vec.at(i) == first) {
				vec.at(i) = second;
			}
			else if (vec.at(i) == second) {
				vec.at(i) = first;
			}
		}
		cout << "Current code: ";
		for (int i = 0; i < vec.size(); i++) {
			cout << vec.at(i);
		}
		cout << endl;
		currKey.clear();
		for (char c : vec) {
			currKey += c;
		}
		//cout << currKey << endl;
		if (currKey == keyWord) {   //this is to check if the current key is correct
			cout << "You have cracked the code!" << endl;  //not sure why it doesn't work but it was
			break;                                         //optional for the assignment
		}
		cout << "Enter two letters to swap: ";
		cin >> done;
		first = done[0];

		
	}
}

void cypherMachine() {
	vector<char> code;
	code = encode(keyWord, 20);
	decode(code);
}

int main() {
	cypherMachine();
}