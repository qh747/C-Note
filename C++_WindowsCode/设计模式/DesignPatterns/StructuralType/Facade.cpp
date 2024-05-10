#include "Facade.h"

void Facade::start()
{
	m_pFileSys->startFileSystem();
	m_pIOSys->startIOSystem();
	m_pGraphWinSys->startGraphWindowSystem();
}

void Facade::close()
{
	m_pFileSys->closeFileSystem();
	m_pIOSys->closeIOSystem();
	m_pGraphWinSys->closeGraphWindowSystem();
}

void FacadeTestDemo()
{
	FileSystem* pFile = new FileSystem();
	IOSystem* pIo = new IOSystem();
	GraphWindowSystem* pGraphWin = new GraphWindowSystem();

	Facade pFacade(pFile, pIo, pGraphWin);
	// �û�������������������ͬʱ����������ϵͳ
	pFacade.start();
	// �û����������Ĺرպ���ͬʱ�ر�������ϵͳ
	pFacade.close();
	
	delete pFile;
	delete pIo;
	delete pGraphWin;
}