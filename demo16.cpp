#include <iostream>
#include <fstream>
using namespace std;

main() {
	ifstream input("D:\\New folder\\Input.txt");
	fstream output;	
	output.open("D:\\New folder\\Output.txt", ios::out);
	string str;
	while (!input.eof()) {
		getline(input, str);
		output << str << endl;
	}
	output << "\nHello World";
	input.close();
	output.close();
}
