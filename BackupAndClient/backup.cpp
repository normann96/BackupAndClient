#include "stdafx.h"
#include "backup.h"

backup::backup(char * const pDest) : m_nSize(0), m_pText(nullptr)
{
	int nLen = strlen(pDest)+1;
	m_pDestination = new char[nLen];
	memcpy(m_pDestination, pDest, sizeof(char)*nLen);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Конструктор backup\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

backup::~backup()
{
	delete [] m_pDestination;
	delete [] m_pText;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Деструктор backup\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void backup::Write( const void * pTxt, int nSize)
{
	char * pTemp = "TempFile.txt";
	FILE *fw;
	if((fw = fopen(pTemp, "ab")) == NULL)
		cout << "Cannot open file\n";
	int nBytes  = strlen((char*)pTxt);
	int nSizeWrite = 0;

	if (nSize != 0)
		nSizeWrite = fwrite(pTxt, sizeof(char), nSize, fw);
	else
		nSizeWrite = fwrite(pTxt, sizeof(char), nBytes, fw);

	cout << "Write completed (" << nSizeWrite << " simbols)\n";
	fclose(fw);
	
	if((fw = fopen(m_pDestination, "ab")) == NULL)
		cout << "Cannot open file\n";
	if (nSize != 0)
		nSizeWrite = fwrite(pTxt, sizeof(char), nSize, fw);
	else
		nSizeWrite = fwrite(pTxt, sizeof(char), nBytes, fw);
	
	m_nSize = nSizeWrite;
	fclose(fw);

	if(remove(pTemp)) 
		printf("Error removing file");
	
}

void backup::ShowTest()
{
	cout << "mSize = " << m_nSize << endl;
	cout << "mpDest = " << m_pDestination << endl;
	cout << "mpText = " << m_pText << endl;
//	cout << "mpText = " << *(int*)m_pText << endl;
}

void * backup::Read()
{
	FILE *fr;
	if((fr = fopen(m_pDestination, "rb")) == NULL)
		cout << "Cannot open file\n";

//	long sizeFile;
//	fseek(fr, 0, SEEK_END);
//	sizeFile = ftell(fr);
//	fseek(fr, 0, SEEK_SET);

	int iIdFile = _fileno(fr);
	unsigned int iFileLength = _filelength(iIdFile);
	m_pText = new char[iFileLength+1];
	m_pText[iFileLength] = '\0';
		
	fread(m_pText, sizeof(char), iFileLength+1, fr);

	fclose(fr);

	m_nSize = iFileLength;
	return m_pText;
}

/*
void backup::WriteTest( const void * pTxt, int nSize )
{
	ofstream fout(m_pDestination, ios::app);
//	fout << *(int*)pTxt;
	fout << (char*)pTxt;

	cout << "Your text successfully saved in " << m_pDestination << " file!\n";
	fout.close();
}
*/


