#include "Component.h"

void BranchComponent::addChild(AbstractComponent* componentPtr)
{ 
	m_componentList.push_back(componentPtr); 
}

bool BranchComponent::removeChild(const string& name)
{
	list<AbstractComponent*>::iterator iter = std::find_if(m_componentList.begin(), m_componentList.end(), [&name](AbstractComponent* pComp) {
			if (name == pComp->getName())
				return true;
			else
				return false;
		});

	if (m_componentList.end() != iter)
	{
		m_componentList.erase(iter);
		return true;
	}
	else
	{
		for (iter = m_componentList.begin(); iter != m_componentList.end(); iter++)
		{
			bool eraseResult = (*iter)->removeChild(name);
			if (true == eraseResult)
				return eraseResult;
		}
		return false;
	}
}

void BranchComponent::showName()
{
	cout << " +Dict: " << getName() << endl;
	for (list<AbstractComponent*>::iterator iter = m_componentList.begin(); iter != m_componentList.end(); iter++)
	{
		(*iter)->showName();
	}
}

AbstractComponent* BranchComponent::getChild(const string& name)
{
	list<AbstractComponent*>::iterator iter = std::find_if(m_componentList.begin(), m_componentList.end(), [&name](AbstractComponent* pComp) {
		if (name == pComp->getName())
			return true;
		else
			return false;
		});

	if (m_componentList.end() != iter)
		return *iter;
	else
	{
		for (iter = m_componentList.begin(); iter != m_componentList.end(); iter++)
		{
			AbstractComponent* pComp = (*iter)->getChild(name);
			if (nullptr != pComp)
				return pComp;
		}
		return nullptr;
	}
}

void ComponentModeTestDemo()
{
	// ���ڵ�Ŀ¼��
	AbstractComponent* rootNode = new BranchComponent(string("/"));

	// һ��Ŀ¼
	AbstractComponent* fstLevelFstNode = new BranchComponent(string("home/"));
	AbstractComponent* fstLevelSecNode = new BranchComponent(string("user/"));

	// ����Ŀ¼
	AbstractComponent* secLevelFstNode = new BranchComponent(string("image/"));
	AbstractComponent* scoLevelSecNode = new LeafComponent(string("helloWorld.cpp"));
	AbstractComponent* secLevelTrdNode = new BranchComponent(string("quhan/"));

	// ����Ŀ¼
	AbstractComponent* trdLevelFstNode = new LeafComponent(string("1.jpg"));
	AbstractComponent* trdLevelSecNode = new LeafComponent(string("2.png"));
	AbstractComponent* trdLevelTrdNode = new LeafComponent(string("record.txt"));

	// Ŀ¼�ṹ�
	rootNode->addChild(fstLevelFstNode);
	rootNode->addChild(fstLevelSecNode);

	fstLevelFstNode->addChild(secLevelFstNode);
	fstLevelFstNode->addChild(scoLevelSecNode);
	fstLevelSecNode->addChild(secLevelTrdNode);

	secLevelFstNode->addChild(trdLevelFstNode);
	secLevelFstNode->addChild(trdLevelSecNode);
	secLevelTrdNode->addChild(trdLevelTrdNode);

	// Ŀ¼�㼶��ʾ
	rootNode->showName();

	// �ڵ��Ƴ�
	rootNode->removeChild("2.png");
	rootNode->showName();

	delete rootNode;
	delete fstLevelFstNode;
	delete fstLevelSecNode;
	delete secLevelFstNode;
	delete scoLevelSecNode;
	delete secLevelTrdNode;
	delete trdLevelFstNode;
	delete trdLevelSecNode;
	delete trdLevelTrdNode;
}