// BackupAndClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "backup.h"
#include "client.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "");
	{
		client * pClient = new client;
		backup * pBackup = new backup("1.txt");
		pClient->SetBackup(pBackup);
		
		char Str[] = "It is dealing in unformatted memory.\
This is what operator new and malloc return: a pointer to a \
block of memory of a certain size. Since the memory does not \
have a type (because it does not have a properly constructed \
object in it yet), it is typeless.!";
		//pClient->WriteText(Str);

		int n1 = 87;
		pClient->WriteText(Str);

		pClient->ReadText();
		pBackup->ShowTest();
		delete pClient;
		delete pBackup;
	}




	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leak!\n";

	_getch();
	return 0;
}

