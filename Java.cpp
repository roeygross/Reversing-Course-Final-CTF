
#pragma warning(disable : 4996)
#include <windows.h>
#include <stdio.h>

extern "C" {
	__declspec(dllexport) void XorForever() { //export XorForever
		char str[8] = { 0x39,0x39,0x39,0x39,0x39,0x39,0x39,0 };
		char abc[] = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" };
		printf("Password:\n");
		char buffer[21];
		scanf("%s", buffer);
		char second = buffer[1];
		int i, j = 0;
		do
		{
			i = j;
			j++;
		} while (buffer[i] != 0); //find index of [NULL]+1 

		int len = j - 1; //length of password string 
		if (len != 0) //if string is not empty
		{
			int sum = 0; //calculate ASCII sum of password
			for (int i = 0; i < len; i++)
			{
				sum += buffer[i];
			}

			if (sum == 1337)
			{

				str[0] = abc[55]; //3
				str[1] = abc[45]; //T
				str[2] = abc[22]; //w
				str[3] = abc[27]; //B
				//39h 9
				//39h 9
				str[6] = abc[5];//f
				printf("bit.ly/%s\n", str);
			}
		}
	}
}

BOOL APIENTRY DllMain(
	HINSTANCE hinstDLL, // handle to DLL module
	DWORD fdwReason, // reason for calling function
	LPVOID lpReserved ) // reserved
{
	if (fdwReason == DLL_PROCESS_ATTACH) //when loaded by a proccess
	{
		if (IsDebuggerPresent() != 0) //if there is a debugger - exit
		{
			ExitProcess(0);
		}
	}

	return 1;
}