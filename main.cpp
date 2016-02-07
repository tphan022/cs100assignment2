#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void display(char& argument) {
	char* userinfo = getlogin();
	char location[20];
	gethostname(location,20);
	cout << "<" << userinfo << "@" << location << ">" << "$";
	
}


int main(void) {
	char argument[1024];
	display(*argument);

return 0;
}
