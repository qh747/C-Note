#pragma once
#include <iostream>
#include <memory>
#include <cstring>
#include <string>
using namespace std;

// �Ž�ģʽ
class AbstractSystem
{
public:
	virtual ~AbstractSystem() {}
	virtual void operation() = 0;
};

class WindowsSystem : public AbstractSystem
{
public:
	virtual ~WindowsSystem() {}
	virtual void operation() { cout << "Windows System Run." << endl; }
};

class LinuxSystem : public AbstractSystem
{
public:
	virtual ~LinuxSystem() { }
	virtual void operation() { cout << "Linux System Run." << endl; }
};

class AbstractComputer
{
public:
	AbstractComputer() : m_osPtr(NULL) {}
	virtual ~AbstractComputer() {}
	virtual void installSystem(AbstractSystem* osPtr) = 0;
	virtual void reinstallSystem(AbstractSystem* osPtr) = 0;

protected:
	AbstractSystem* m_osPtr;
};

class BrandFstComputer : public AbstractComputer
{
public:
	virtual ~BrandFstComputer() {}
	virtual void installSystem(AbstractSystem* osPtr);
	virtual void reinstallSystem(AbstractSystem* osPtr);
};

// �Ž�ģʽ���Ժ���
void BridgingModeTestDemo();