#include "Decorator.h"

string encryptDecorator::read(void)
{
	string encryptStreamStr = string("<encrypt> ") + this->AbstractDecorator::read();
	return encryptStreamStr;
}

void encryptDecorator::write(string streamVal)
{
	string decryptStr = string("<decrypt> ") + streamVal;
	AbstractDecorator::write(decryptStr);
}

string CompressDecorator::read(void)
{
	string compressStreamStr = string("<compress> ") + this->AbstractDecorator::read();
	return compressStreamStr;
}

void CompressDecorator::write(string streamVal)
{
	string decompresstStr = string("<decompress> ") + streamVal;
	AbstractDecorator::write(decompresstStr);
}

void DecoratorTestDemo()
{
	// ԭʼ����д���ȡ
	AbstractDataStream* fileStreamPtr = new FileStream();
	fileStreamPtr->write("file data");
	cout << fileStreamPtr->read() << endl;

	// ԭʼ���ݼ���
	AbstractDecorator* pEncryptDecorator = new encryptDecorator(fileStreamPtr);
	cout << pEncryptDecorator->read() << endl;

	// ��������ѹ��
	AbstractDecorator* pCompressDecorator = new CompressDecorator(pEncryptDecorator);
	cout << pCompressDecorator->read() << endl;
	
	// ����������
	AbstractDataStream* netStreamPtr = new NetworkStream();
	netStreamPtr->write("net data");
	cout << netStreamPtr->read() << endl;

	pEncryptDecorator->replaceStream(netStreamPtr);
	cout << pEncryptDecorator->read() << endl;
	cout << pCompressDecorator->read() << endl;

	delete fileStreamPtr;
	delete pEncryptDecorator;
	delete pCompressDecorator;
	delete netStreamPtr;
}