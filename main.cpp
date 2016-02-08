#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

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

// This function turns the array of input characters into separate tokens(strings)
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

void run(char** runcommand) {
	pid_t PID;
	int s;
	if((PID = fork()) < 0) {
		cout << "Error, forking failed" << endl;
		exit(1);
	}
	else if(PID == 0) {
		if(execvp(*runcommand, runcommand) < 0) {
			cout << "running error";
			exit(1);
		}
	}
	else {
		while(wait(&s) != PID) {};
	}
}

void 

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
		string tempo = tokens.at(0);
		char* temp[64];
		int q = 0;
		temp[q] = (char*)tokens.at(0).c_str();
		temp[q+1] = 0;
		q++;
		run(temp);
		cout << endl << "Tempval: " << *temp << endl;
		tokens.clear();
	}

return 0;
}
