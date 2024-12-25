#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

void clean();

class RAM {
	struct Process {
		string name = "";
		int bytes_process;
		int bytes_block;
		int addr;
	};
	struct Block {
		bool f = 0;
		Process Pr;
		int bytes = 0;
		int addr = 0;
		int ptr = 0;
	};
	vector<Block> massive;
public:
	void add();
	void del();
	void info_ram();
	void info_process();
	RAM(int n);
};




#endif // !HEADER_H