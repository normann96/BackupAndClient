#include "stdafx.h"
#include "client.h"

client::client(char *const pDest):m_nSize(0), m_pText(nullptr), mpBackup(nullptr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Конструктор client\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

client::~client()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Деструктор client\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void client::SetBackup( backup * pBack )
{
	mpBackup = pBack;
}

void client::WriteText( const void * pText, int nSize )
{
	
	if (mpBackup != nullptr)
	{
		mpBackup->Write(pText, nSize);
//		mpBackup->WriteTest(pText);
	}
	else
		cout << "You haven't included SetBackup!\n";

}

void client::ReadText()
{
	mpBackup->Read();
}
