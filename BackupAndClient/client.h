#ifndef client_h__
#define client_h__
#include "backup.h"

class client
{
private:
	int m_nSize;
	void * m_pText;
	backup * mpBackup;
public:
	client(char *const pDest = "NewFile.txt");
	~client();
	void SetBackup(backup * pBack);
	void WriteText(const void * pText, int nSize = 0);
	void ReadText();
};
#endif // client_h__
