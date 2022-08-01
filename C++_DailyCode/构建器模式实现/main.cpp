#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

enum MSG_TYPE
{
	ETH_TYPE = 1,
	IP_TYPE  = 2,
};

/*��Ϣͷ    **/
struct MsgHeader
{
	MSG_TYPE m_msgType;
	int m_msgId;
};

/*��Ϣ��    **/
struct MsgDatater
{
	string m_data;
	int m_dataSize;
};

/*��Ϣβ    **/
struct MsgTail
{
	int m_tailFlag;
	int m_msgSize;
};

/*Builder����    **/
class Builder
{
public:
	virtual ~Builder() { }

public:
	virtual void buildMsgHead(MsgHeader head) = 0;
	virtual void buildMsgData(MsgDatater data) = 0;
	virtual void buildMsgTail(MsgTail tail) = 0;

public:
	virtual string getFormatMsg() = 0;
};

class EthBuilder : public Builder
{
public:
	EthBuilder()
	{
	
	}
	
	virtual ~EthBuilder()
	{

	}

public:
	virtual void buildMsgHead(MsgHeader head)
	{
		stringstream ss;
		ss << "Ethernet Msg Head: " << head.m_msgType  << " " << head.m_msgId << endl;
		m_msgFulContent.append(ss.str());
	}

	virtual void buildMsgData(MsgDatater data)
	{
		stringstream ss;
		ss << "Ethernet Msg Data: " << data.m_data << " " << data.m_dataSize << endl;
		m_msgFulContent.append(ss.str());
	}

	virtual void buildMsgTail(MsgTail tail)
	{
		stringstream ss;
		ss << "Ethernet Msg Tail: " << tail.m_tailFlag << " " << tail.m_msgSize << endl;
		m_msgFulContent.append(ss.str());
	}

public:
	virtual string getFormatMsg()
	{
		return m_msgFulContent;
	}

private:
	string m_msgFulContent;
};

class IpBuilder : public Builder
{
public:
	IpBuilder()
	{

	}

	virtual ~IpBuilder()
	{

	}

public:
	virtual void buildMsgHead(MsgHeader head)
	{
		stringstream ss;
		ss << "IP Msg Head: " << head.m_msgType << " " << head.m_msgId << endl;
		m_msgFulContent.append(ss.str());
	}

	virtual void buildMsgData(MsgDatater data)
	{
		stringstream ss;
		ss << "IP Msg Data: " << data.m_data << " " << data.m_dataSize << endl;
		m_msgFulContent.append(ss.str());
	}

	virtual void buildMsgTail(MsgTail tail)
	{
		stringstream ss;
		ss << "IP Msg Tail: " << tail.m_tailFlag << " " << tail.m_msgSize << endl;
		m_msgFulContent.append(ss.str());
	}

public:
	virtual string getFormatMsg()
	{
		return m_msgFulContent;
	}

private:
	string m_msgFulContent;
};

/*Director����    **/
class Director
{
public:
	Director(Builder* builder) :m_msgBuilder(builder)
	{

	}
	~Director()
	{

	}

public:
	void replaceBuilder(Builder* other)
	{
		m_msgBuilder = other;
	}

public:
	void constructMsg(MsgHeader head, MsgDatater data, MsgTail tail)
	{
		m_msgBuilder->buildMsgHead(head);
		m_msgBuilder->buildMsgData(data);
		m_msgBuilder->buildMsgTail(tail);
	}

	string getMsg()
	{
		return m_msgBuilder->getFormatMsg();
	}

private:
	Builder* m_msgBuilder;
};


int main()
{
	
	Builder* buildPtr = new EthBuilder();
	Director director = Director(buildPtr);

	/*������̫������    **/
	director.constructMsg(
		MsgHeader{ ETH_TYPE , 1 },
		MsgDatater{ string("Ethernet Data."), (int)strlen("Ethernet Data.")},
		MsgTail{ -1, sizeof(MsgHeader) + sizeof(MsgDatater) + sizeof(MsgTail) });

	cout << director.getMsg() << endl;

	delete buildPtr;
	buildPtr = NULL;
	buildPtr = new IpBuilder();

	director.replaceBuilder(buildPtr);

	/*����IP����    **/
	director.constructMsg(
		MsgHeader{ IP_TYPE , 2 },
		MsgDatater{ string("IP Data."), (int)strlen("IP Data.") },
		MsgTail{ -1, sizeof(MsgHeader) + sizeof(MsgDatater) + sizeof(MsgTail) });

	cout << director.getMsg() << endl;

	delete buildPtr;
	buildPtr = NULL;

	system("pause");
	return 0;
}