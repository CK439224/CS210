/*
****************************
*Name: Christopher King    *
*Date: 1/29/23             *
*Clase: CS-210             *
*Project2 AirGead Banking  *
****************************
*/

#include <iostream>
#include <string>
#include "DataInput.h"
using namespace std;

void startApp() {    //Used to start and loop through program until restart is changed to false.
	bool restart = true;

	do {
		DataInput userData;
		userData.promptUser();
		restart = userData.choiceCheck();
	} while (restart);
}

int main() {  //Main program
	startApp();

	return 0;
}