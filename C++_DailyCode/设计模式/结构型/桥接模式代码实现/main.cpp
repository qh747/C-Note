#include <iostream>
#include <memory>
#include <cstring>
#include <string>
using namespace std;

/*�������ϵͳ��    **/
class AbstractOperatorSystem
{
public:
	virtual ~AbstractOperatorSystem() { }

public:
	virtual void operation() = 0;
};

class WindowsSystem : public AbstractOperatorSystem
{
public:
	WindowsSystem() { }
	virtual ~WindowsSystem() { }

public:
	virtual void operation()
	{
		cout << "Windows System Run." << endl;
	}
};

class LinuxSystem : public AbstractOperatorSystem
{
public:
	LinuxSystem() { }
	virtual ~LinuxSystem() { }

public:
	virtual void operation()
	{
		cout << "Linux System Run." << endl;
	}
};


/*���������    **/
class AbstractComputer
{
public:
	AbstractComputer() : m_osPtr(NULL) { }
	virtual ~AbstractComputer() { }

public:
	virtual void installSystem(AbstractOperatorSystem* osPtr) = 0;

protected:
	AbstractOperatorSystem* m_osPtr;
};

class LenovoComputer : public AbstractComputer
{
public:
	LenovoComputer() : AbstractComputer() { }
	virtual ~LenovoComputer() { }

public:
	virtual void installSystem(AbstractOperatorSystem* osPtr)
	{
		m_osPtr = osPtr;

		cout << "Lenovo Computer Open." << endl;
		cout << "System Installing..." << endl;
		this->m_osPtr->operation();
		cout << "System Install Done." << endl << endl;
	}
};

class DellComputer : public AbstractComputer
{
public:
	DellComputer() : AbstractComputer() { }
	virtual ~DellComputer() { }

public:
	virtual void installSystem(AbstractOperatorSystem* osPtr)
	{
		m_osPtr = osPtr;

		cout << "Dell Computer Open." << endl;
		cout << "System Installing..." << endl;
		this->m_osPtr->operation();
		cout << "System Install Done." << endl << endl;
	}
};

int main()
{
	/*ʹ��һ̨װ��Windowsϵͳ��Lenovo����    **/
	AbstractOperatorSystem* pSystem = new WindowsSystem();
	AbstractComputer* pComputer = new LenovoComputer();

	pComputer->installSystem(pSystem);
	delete pSystem;

	/*ʹ��һ̨װ��Linuxϵͳ��Lenovo����    **/
	pSystem = new LinuxSystem();

	pComputer->installSystem(pSystem);
	delete pSystem;

	delete pComputer;

	/*ʹ��һ̨װ��Windowsϵͳ��Dell����    **/
	pSystem = new WindowsSystem();
	pComputer = new DellComputer();

	pComputer->installSystem(pSystem);
	delete pSystem;

	/*ʹ��һ̨װ��Linuxϵͳ��Lenovo����    **/
	pSystem = new LinuxSystem();

	pComputer->installSystem(pSystem);

	delete pSystem;
	delete pComputer;

	system("pause");
	return 0;
}