#include "ShareElement.h"

ShapeFactory::~ShapeFactory()
{
	for (map<string, AbstractShape*>::iterator iter = m_CircleMap.begin(); iter != m_CircleMap.end(); ++iter)
	{
		delete (iter->second);
	}
}

AbstractShape* ShapeFactory::getShape(string color)
{
	// ��ԪģʽΪ�����Ѿ����ڵĶ��󣬶��Բ����ڵĶ����´���
	map<string, AbstractShape*>::iterator iter = m_CircleMap.find(color);
	if (m_CircleMap.end() == iter)
	{
		AbstractShape* pNewObj = new CircleShape(color);
		m_CircleMap.insert(make_pair(color, pNewObj));
		return pNewObj;
	}
	else
		return m_CircleMap.find(color)->second;
}

void ShapeFactoryTestDemo()
{
	ShapeFactory circleFactory;
	// �½�һ��Ԫ��
	CircleShape* circlePtr = dynamic_cast<CircleShape *>(circleFactory.getShape("green"));
	circlePtr->setXpos(10);
	circlePtr->setYpos(10);
	circlePtr->setRadius(10);
	circlePtr->drawShape();

	// ����Ԫ��
	circlePtr = dynamic_cast<CircleShape*>(circleFactory.getShape("green"));
	circlePtr->drawShape();

	// �޸�Ԫ������
	circlePtr->setXpos(30);
	circlePtr->setYpos(30);
	circlePtr->setRadius(30);
	circlePtr->drawShape();
}