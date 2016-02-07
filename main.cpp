#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;


// This display function displays the prompt and recieves the user input
void display(char& argument) {
	while(1) {
		char* userinfo = getlogin();
		char location[20];
		gethostname(location,20);
		cout << "<" << userinfo << "@" << location << ">" << "$";
		fgets(&argument,1024,stdin);
		if(argument != '\n') {
			break;
		}
	}
}

void tokenizing(char& argument, vector<string>* v) {
	char* ptr;
	ptr = strtok(&argument, " \n");
	string temp(ptr);
	v->push_back(temp);
	while(ptr != NULL) {
		
		ptr = strtok(NULL, " \n");
		if(ptr != NULL) {
			string temp2(ptr);
			v->push_back(temp2);
		}
	}
}


int main(void) {
	char argument[1024];
	vector<string> tokens;
	while(1) {
		display(*argument);
		tokenizing(*argument,&tokens);
		if(tokens.at(0) == "exit") {
			break;
		}
		for(unsigned int i = 0; i < tokens.size(); i++) {
			cout << tokens.at(i) << " ";
		}
		cout << endl;
		tokens.clear();
	}

return 0;
}
