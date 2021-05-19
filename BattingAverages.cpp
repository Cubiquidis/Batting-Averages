// Michael Lewis
// CSIS 123
// 0382602
// 12/13/15.
// Final
// Class file

#include <iostream>
#include "Stack.h"
#include "BattingAverages.h"
#include <fstream>
upnext::upnext()
{
	this->count = 0;
}
void upnext::Records()
{
	char line[20];
	string s;

	ifstream inFile("avgs.txt");

	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			inFile.getline(line, 20);

			s = line;

			Separate(s);
		}
	}
}

void upnext::Separate(string line)
{
	string average = "";
	string name = "";
	for (int i = 0; i < line.length(); i++)
	{
		if (isdigit(line.at(i)) || ( line.at(i) == '.' && line.at(i-1) == ' '))
			average += line.at(i);
		else
			name += line.at(i);
	}
	batterUp(average, name);
}

void upnext::batterUp(string average, string name)
{
	double averages = stod(average);
	count++;
	if (count > 1)
	{
		if (averages > this->high.peek())
		{
			this->high.erases();
			this->highbatter.erases();
			this->high.push(averages);
			this->highbatter.push(name);
		}
		else if (averages == this->high.peek())
		{
			this->high.push(averages);
			this->highbatter.push(name);
		}
		else if (averages < this->low.peek())
		{
			this->low.erases();
			this->lowbatter.erases();
			this->low.push(averages);
			this->lowbatter.push(name);
		}
		else if (averages == this->low.peek())
		{
			this->low.push(averages);
			this->lowbatter.push(name);
		}
	}
	else
	{
		this->low.push(averages);
		this->lowbatter.push(name);
		this->high.push(averages);
		this->highbatter.push(name);
	}

}

void upnext::printStuff()
{
	int hsize = this->highbatter.size();
	int lsize = this->lowbatter.size();
	cout << "Highest Batters: " << endl;
	for (int i = 0; i < hsize; i++)
	{
		cout << this->highbatter.peek() << "\t" << this->high.peek() << endl;
		this->highbatter.pop();
		this->high.pop();
	}
	cout << "Lowest Batters: " << endl;
	for (int i = 0; i < lsize; i++)
	{
		cout << this->lowbatter.peek() << "\t" << this->low.peek() << endl;
		this->lowbatter.pop();
		this->low.pop();
	}
}
