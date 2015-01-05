#include <iostream>
#include <string>
#include <wiringPi.h>
#include <lcd.h>
using namespace std;

//Writes the given text to the given column on the given lcd:
void lcdWriteToColumn(int& lcd, int column, const char* text)
{
	lcdPosition(lcd, 0, column);
	lcdPuts(lcd, text);
}

//Prints usage:
void usage()
{
	std::cout << "A simple program to output to the 16x2 LCD screen.\n";
	std::cout << "Requires root!\n\n";
	std::cout << "\t-h\t\t\tDisplay this help and exit.\n";
	std::cout << "\t-1=[string]\t\tPrint [string] to the 1st row.\n";
	std::cout << "\t-2=[string]\t\tPrint [string] to the 2nd row.\n";
	std::cout << "\t-c\t\t\tClear the screen.\n";
}

int main(int argc, char* argv[])
{
	if(argc == 0)
	{
		usage();
		return 0;
	}

	if(wiringPiSetup() == -1)
	{
		std::cerr << "Error setting up pins!\n";
		return 1;
	}
	
	int lcd = lcdInit(2, 16, 4, 6, 5, 4, 0, 2, 3, 0, 0, 0, 0);
	if(lcd == -1)
	{
		std::cerr << "Error setting up LCD!\n";
		return 1;
	}

	for(int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		if((arg != "-h") && (arg != "-c") && (arg.find("-1=") == -1) && (arg.find("-2=") == -1))
		{
			std::cout << "Unrecongised option '" << arg << "'.\n";
			std::cout << "Use 'lcd -h' for help.\n";
			return 1;
		}
		else if(arg == "-h")
		{
			usage();
			return 0;
		}
		else if(arg.find("-1=") != -1)
		{
			string input = arg.substr(3, arg.size());
			lcdWriteToColumn(lcd, 0, input.c_str());
		}
		else if(arg.find("-2=") != -1)
		{
			string input = arg.substr(3, arg.size());
			lcdWriteToColumn(lcd, 1, input.c_str());
		}
		else if(arg == "-c")
			lcdClear(lcd);
	}
	return 0;
}
