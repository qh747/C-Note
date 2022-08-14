#include <iostream>
#include <cstring>
#include <string>
#include <memory>
using namespace std;

/*��������    **/
class AbstractStream
{
public:
	virtual ~AbstractStream() { }

public:
	virtual string read(void)           = 0;
	virtual void   write(string stream) = 0;
};

/*�ļ�����    **/
class FileStream : public AbstractStream
{
public:
	FileStream() { }
	virtual ~FileStream() { }

public:
	virtual string read(void)
	{
		return string("File Stream.");
	}

	virtual void write(string stream)
	{
		cout << "File Write: " << stream << endl;
	}
};

/*��������    **/
class NetworkStream : public AbstractStream
{
public:
	NetworkStream() { }
	virtual ~NetworkStream() { }

public:
	virtual string read(void)
	{
		return string("Network Stream.");
	}

	virtual void write(string stream)
	{
		cout << "Network Write: " << stream << endl;
	}
};

/*����װ������    **/
class AbstractDecorator : public AbstractStream
{
public:
	AbstractDecorator(AbstractStream* stream) : m_streamPtr(stream)
	{

	}

	virtual ~AbstractDecorator()
	{

	}

public:
	virtual string read(void)
	{
		return m_streamPtr->read();
	}

	virtual void write(string stream)
	{
		m_streamPtr->write(stream);
	}

private:
	AbstractStream* m_streamPtr;
};

/*����װ������    **/
class encryptClass : public AbstractDecorator
{
public:
	encryptClass(AbstractStream* stream) : AbstractDecorator(stream)
	{

	}

	virtual ~encryptClass()
	{

	}

public:
	virtual string read(void)
	{
		string srcStreamStr = AbstractDecorator::read();

		string encryptStreamStr = string("<encrypt> ") + srcStreamStr;		/*����<>���ű�ʾԭʼ�������Ĵ�����    **/
		return encryptStreamStr;
	}

	virtual void write(string stream)
	{
		string encryptStr = string("<encrypt> ") + stream;
		AbstractDecorator::write(encryptStr);
	}
};

/*ѹ��װ������    **/
class CompressClass : public AbstractDecorator
{
public:
	CompressClass(AbstractStream* stream) : AbstractDecorator(stream)
	{

	}

	virtual ~CompressClass()
	{

	}

public:
	virtual string read(void)
	{
		string srcStreamStr = AbstractDecorator::read();

		string compressStreamStr = string("<compress> ") + srcStreamStr;
		return compressStreamStr;
	}

	virtual void write(string stream)
	{
		string compresstStr = string("<compress> ") + stream;
		AbstractDecorator::write(compresstStr);
	}
};

int main()
{
	/*ԭʼ���ļ�����    **/
	shared_ptr<AbstractStream> streamPtr = make_shared<FileStream>();
	cout << streamPtr->read() << endl;

	/*����װ����װ���ļ���, �����ļ������ܡ��������    **/
	shared_ptr<AbstractDecorator> encryptPtr = make_shared<encryptClass>(streamPtr.get());	
	cout << encryptPtr->read() << endl;

	/*ѹ��װ������װ�μ���װ����, �����ļ���ѹ�������ܡ��������    **/
	shared_ptr<AbstractDecorator> encryptCompressPtr = make_shared<CompressClass>(encryptPtr.get());
	cout << encryptCompressPtr->read() << endl;

	system("pause");
	return 0;
}