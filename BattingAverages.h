// Michael Lewis
// CSIS 123
// 0382602
// 12/13/15.
// Final
// Class file

#ifndef BATTINGAVERAGES
#define BATTINGAVERAGES

#include <iostream>
#include "Stack.h"
#include <fstream>

using namespace std;

class upnext
{
private:
	Stack<double> high;
	Stack<double> low;
	Stack<string> highbatter;
	Stack<string> lowbatter;
	double count;
public:
	upnext();
	void Records();
	void Separate(string line);
	void batterUp(string average, string name);
	void printStuff();

};
#endif