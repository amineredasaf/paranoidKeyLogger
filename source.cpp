//                    ___ 	|
//                   / __)	| Author	: Amine Reda Saf
//    ____ ___  ____| |__ 	|
//   / ___)___)/ _  |  __)	| Github	: https://github.com/amineredasaf
//  | |  |___ ( ( | | |   	|
//  |_|  (___/ \_||_|_|   	| Name		: paranoidKeyLogger
//                        	|

#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <winternl.h>

// log file path
using namespace std;

#define LOGF_PATH "/.log.md"
int main(void){

	std::ofstream tmpfile;

	tmpfile.open(LOGF_PATH,  fstream::app);
	// tmpfile << key;
	tmpfile.close();
}