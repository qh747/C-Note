#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;

/*ͼ�λ���    **/
class Shape
{
public:
	virtual ~Shape() { }

public:
	virtual void drawShape() = 0;
};

/*Բ�ξ�����    **/
class Circle : public Shape
{
public:
	Circle(string color = "white", int xPos = 0, int yPos = 0, int radius = 0) : m_color(color), m_xPos(xPos), m_yPos(yPos), m_radius(radius) { }
	virtual ~Circle() { }

public:
	virtual void drawShape()
	{
		cout << "In <" << m_xPos << "," << m_yPos << "> With Color " << m_color << " Draw A Circle." << endl;
	}

public:
	void setColor(string color) { m_color = color; }
	void setXpos(int pos) { m_xPos = pos; }
	void setYpos(int pos) { m_yPos = pos; }
	void setRadius(int radius) { m_radius = radius; }

private:
	string	m_color;
	int		m_xPos;
	int		m_yPos;
	int		m_radius;
};

/*ͼ���๤��    **/
class ShapeFactory
{
public:
	ShapeFactory() { }
	~ShapeFactory()
	{
		for (map<string, Shape*>::iterator iter = m_CircleMap.begin(); iter != m_CircleMap.end(); ++iter)
		{
			delete (iter->second);
		}
	}

public:
	Shape* getShape(string color)
	{
		Shape* circlePtr = NULL;
		if (m_CircleMap.end() == m_CircleMap.find(color))	/*��ԪģʽΪ�����Ѿ����ڵĶ��󣬶��Բ����ڵĶ����´���    **/
		{
			cout << "Create New Circle." << endl;
			circlePtr = new Circle(color);
			m_CircleMap.insert(make_pair(color, circlePtr));
		}
		else
		{
			cout << "Use A Exists Circle." << endl;
			circlePtr = m_CircleMap.find(color)->second;

		}

		return circlePtr;
	}

private:
	map<string, Shape*> m_CircleMap;
};

int main()
{
	ShapeFactory circleFactory;
	/*�´���һ����ɫ��Բ    **/
	Circle* circlePtr = dynamic_cast<Circle *>(circleFactory.getShape("green"));
	circlePtr->setXpos(10);
	circlePtr->setYpos(10);
	circlePtr->setRadius(10);
	circlePtr->drawShape();

	/*�´���һ����ɫ��Բ    **/
	circlePtr = dynamic_cast<Circle*>(circleFactory.getShape("red"));
	circlePtr->setXpos(20);
	circlePtr->setYpos(20);
	circlePtr->setRadius(20);
	circlePtr->drawShape();

	/*ʹ��һ���Ѿ����ڵ���ɫ��Բ    **/
	circlePtr = dynamic_cast<Circle*>(circleFactory.getShape("green"));
	circlePtr->setXpos(30);
	circlePtr->setYpos(30);
	circlePtr->setRadius(30);
	circlePtr->drawShape();

	system("pause");
	return 0;
}