#include "VistorMode.h"

void VistorTestDemo()
{
	// ����ഴ��
	Computer* computer = new Computer();

	// �������ഴ��
	Vistor* simpVistor = new SimpleChecker();
	Vistor* highVistor = new HighChecker();

	// �����߷���Ԫ��
	computer->accept(simpVistor);
	computer->accept(highVistor);

	delete computer;
}