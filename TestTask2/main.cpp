#include <iostream>
#include "HashHandler.h"

//This project maded as test task for Veeam Software on work possition QA Atomation Engineer
//Autor: Ivan Platonov
//E-Mail: Ivanplateam@gmail.com

int main()
{
	HashHandler hh;
	std::string input; // Create string for user's input
	//Example of input:<path to the input file> <path to the directory containin the files to check>
	//Example: 123123.txt C:/Users/ivanp/source/repos/TestTask2/TestTask2"
	std::getline(std::cin, input); // Fill the input
	hh.CheckHashSumm(input); // Check the hash summ by input
}