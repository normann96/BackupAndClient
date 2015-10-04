#ifndef backup_h__
#define backup_h__

class backup
{
private:
	unsigned int m_nSize;
	char * m_pDestination;
	char * m_pText;

public:
	backup(char *const pDest = "NewFile.txt");
	~backup();
//	void WriteTest(const void * pTxt, int nSize = 0);
	void * Read();
	void Write(const void * pTxt, int nSize = 0);
	void ShowTest();
};
#endif // backup_h__
