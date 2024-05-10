#include "StateMode.h"

void StateTestDemo()
{
	AbstractState* sStat = new SendState();
	AbstractState* rStat = new RecvState();
	Context cont;

	// �л�Ϊ����״̬
	cont.setState(sStat);
	cont.handleData("Network Data");

	// �л�Ϊ����״̬
	cont.setState(rStat);
	cont.handleData("Network Data");

	delete sStat;
	delete rStat;
}