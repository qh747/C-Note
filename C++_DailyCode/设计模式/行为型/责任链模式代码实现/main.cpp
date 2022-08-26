#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*��Ϣ�ṹ��    **/
struct MessageType
{
	string messageHeader;
	string messageContent;
	string messageTail;
};


/*���Ͷ���    **/
class SenderClass
{
public:
	MessageType generateMessage(string messageContent)
	{
		MessageType message;
		message.messageHeader = string("HEADER");
		message.messageContent = messageContent;
		message.messageTail = string("TAIL");

		return message;
	}
};


/*���ն���    **/
class AbstractMessageHandler
{
public:
	AbstractMessageHandler() : m_pNextHandler(NULL) { }

	virtual ~AbstractMessageHandler() { }

public:
	void setNextHandler(AbstractMessageHandler* pHandler)
	{
		m_pNextHandler = pHandler;
	}

public:
	virtual bool messageProcess(MessageType message) = 0;

protected:
	AbstractMessageHandler* m_pNextHandler;
};


class MessageHeadHandler : public AbstractMessageHandler
{
public:
	MessageHeadHandler() { }
	virtual ~MessageHeadHandler() { }

public:
	virtual bool messageProcess(MessageType message)
	{
		if (true == message.messageHeader.empty() || string("HEADER") != message.messageHeader)
			return false;

		if (NULL == m_pNextHandler)
			return false;

		cout << "Message Head Check Success." << endl;
		return m_pNextHandler->messageProcess(message);
	}
};


class MessageContentHandler : public AbstractMessageHandler
{
public:
	MessageContentHandler() { }
	virtual ~MessageContentHandler() { }

public:
	virtual bool messageProcess(MessageType message)
	{
		if (true == message.messageContent.empty())
			return false;

		if (NULL == m_pNextHandler)
			return false;

		cout << "Message Content Check Success. Content Is: " << message.messageContent << endl;
		return m_pNextHandler->messageProcess(message);
	}
};


class MessageTailHandler : public AbstractMessageHandler
{
public:
	MessageTailHandler() { }
	virtual ~MessageTailHandler() { }

public:
	virtual bool messageProcess(MessageType message)
	{
		if (true == message.messageTail.empty() || string("TAIL") != message.messageTail)
			return false;

		cout << "Message Tail Check Success." << endl;
		return true;
	}
};


int main()
{
	/*�������Ͷ˺ͽ��ն˶���    **/
	SenderClass senderObj;
	AbstractMessageHandler* pHeaderHandler = new MessageHeadHandler();
	AbstractMessageHandler* pContentHandler = new MessageContentHandler();
	AbstractMessageHandler* pTailHandler = new MessageTailHandler();

	/*�������ն�������    **/
	pHeaderHandler->setNextHandler(pContentHandler);
	pContentHandler->setNextHandler(pTailHandler);

	/*��ϢУ������    **/
	MessageType rightMessage = senderObj.generateMessage("Right Data");
	pHeaderHandler->messageProcess(rightMessage);

	MessageType wrongMessage = senderObj.generateMessage("");
	pHeaderHandler->messageProcess(wrongMessage);

	delete pTailHandler;
	pTailHandler = NULL;

	delete pContentHandler;
	pContentHandler = NULL;

	delete pHeaderHandler;
	pHeaderHandler = NULL;


	system("pause");
	return 0;
}