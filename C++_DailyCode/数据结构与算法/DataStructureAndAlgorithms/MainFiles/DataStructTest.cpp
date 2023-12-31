#include "DataStructTest.h"
#define DATASTRUCT_TEST_SEQ  6

/*���ݽṹ����																**/
void dataStructTest()
{
#if 1 == DATASTRUCT_TEST_SEQ

	/*��̬�������															**/
	funcDynamicArrayTest();

#elif 2 == DATASTRUCT_TEST_SEQ

	/*�Ľ��涯̬�������													**/
	funcDynamicArrayAdvTest();
	
#elif 3 == DATASTRUCT_TEST_SEQ

	/*�����������															**/
	funcSingleLinkListTest();

#elif 4 == DATASTRUCT_TEST_SEQ

	/*˫���������															**/
	funcDoubleLinkListTest();

#elif 5 == DATASTRUCT_TEST_SEQ

	/*˳��ջ����															**/
	funcSequenceStackTest();

#elif 6 == DATASTRUCT_TEST_SEQ

	/*��ʽջ����															**/
	funcLinkStackTest();

#endif
}

/*��̬�������																**/
void funcDynamicArrayTest()
{
	DynamicArray dyncArray;

	/*������ݲ���															**/
	for (int i = 1; i <= 10; ++i)
	{
		dyncArray.addVal(i);
	}

	cout << "ADD DATA TEST." << endl << "Dynamic Array: ";
	for (int i = 0; i < dyncArray.getSize(); ++i)
	{
		cout << dyncArray.getVal(i) << " ";
	}
	cout << endl << "Capacity: " << dyncArray.getCapacity() << endl;
	cout <<  "Size: " << dyncArray.getSize() << endl << endl;


	/*�������ݲ���															**/
	dyncArray.insertVal(0, 0);
	dyncArray.insertVal(dyncArray.getSize(), 11);

	cout  << endl << "INSERT DATA TEST." << endl << "Dynamic Array: ";
	for (int i = 0; i < dyncArray.getSize(); ++i)
	{
		cout << dyncArray.getVal(i) << " ";
	}
	cout << endl << "Capacity: " << dyncArray.getCapacity() << endl;
	cout << "Size: " << dyncArray.getSize() << endl << endl;


	/*�޸����ݲ���															**/
	int curSize = dyncArray.getSize();
	for (int i = 0; i < curSize; ++i)
	{
		if (dyncArray.getVal(i) < 5)
			dyncArray.modifyVal(i, 0);
	}

	cout << endl << "MODIFY DATA TEST." << endl << "Dynamic Array: ";
	for (int i = 0; i < dyncArray.getSize(); ++i)
	{
		cout << dyncArray.getVal(i) << " ";
	}
	cout << endl << "Capacity: " << dyncArray.getCapacity() << endl;
	cout << "Size: " << dyncArray.getSize() << endl << endl;


	/*ɾ�����ݲ���															**/
	while (true)
	{
		int delIndex = -1;
		for (int i = 0; i < dyncArray.getSize(); ++i)
		{
			if (0 == dyncArray.getVal(i))
			{
				delIndex = i;
				break;
			}	
		}

		if (-1 == delIndex)
			break;
		else
			dyncArray.delVal(delIndex);
	}

	cout << endl << "DELETE DATA TEST." << endl << "Dynamic Array: ";
	for (int i = 0; i < dyncArray.getSize(); ++i)
	{
		cout << dyncArray.getVal(i) << " ";
	}
	cout << endl << "Capacity: " << dyncArray.getCapacity() << endl;
	cout << "Size: " << dyncArray.getSize() << endl << endl;


	/*������ݲ���															**/
	dyncArray.clear();
	cout << endl << "DELETE DATA TEST." << endl << "Dynamic Array Size: " << dyncArray.getSize();
	cout << endl << "Capacity: " << dyncArray.getCapacity() << endl;
	cout << "Size: " << dyncArray.getSize() << endl;
}

/*�Ľ��涯̬�������														**/
void funcDynamicArrayAdvTest()
{
	DynamicArrayAdv dyncAdvArray;

	/*������ݲ���															**/
	for (int i = 1; i <= 10; ++i)
	{
		dyncAdvArray.pushBack(i);
	}

	cout << "ADD DATA TEST." << endl << "Dynamic Array Adv: ";
	for (int i = 0; i < dyncAdvArray.size(); ++i)
	{
		cout << dyncAdvArray[i] << " ";
	}
	cout << endl << "Capacity: " << dyncAdvArray.capacity() << endl;
	cout << "Size: " << dyncAdvArray.size() << endl << endl;


	/*�������ݲ���															**/
	dyncAdvArray.insert(0, 0);
	dyncAdvArray.insert(dyncAdvArray.size(), 11);

	cout << endl << "INSERT DATA TEST." << endl << "Dynamic Array: ";
	for (int i = 0; i < dyncAdvArray.size(); ++i)
	{
		cout << dyncAdvArray[i] << " ";
	}
	cout << endl << "Capacity: " << dyncAdvArray.capacity() << endl;
	cout << "Size: " << dyncAdvArray.size() << endl << endl;


	/*�޸����ݲ���															**/
	int curSize = dyncAdvArray.size();
	for (int i = 0; i < curSize; ++i)
	{
		if (dyncAdvArray[i] < 5)
			dyncAdvArray[i] = 0;
	}

	cout << endl << "MODIFY DATA TEST." << endl << "Dynamic Array: ";
	for (int i = 0; i < dyncAdvArray.size(); ++i)
	{
		cout << dyncAdvArray[i] << " ";
	}
	cout << endl << "Capacity: " << dyncAdvArray.capacity() << endl;
	cout << "Size: " << dyncAdvArray.size() << endl << endl;


	/*ɾ�����ݲ���															**/
	while (true)
	{
		int delIndex = -1;
		for (int i = 0; i < dyncAdvArray.size(); ++i)
		{
			if (0 == dyncAdvArray[i])
			{
				delIndex = i;
				break;
			}
		}

		if (-1 == delIndex)
			break;
		else
			dyncAdvArray.erase(delIndex);
	}

	cout << endl << "DELETE DATA TEST." << endl << "Dynamic Array: ";
	for (int i = 0; i < dyncAdvArray.size(); ++i)
	{
		cout << dyncAdvArray[i] << " ";
	}
	cout << endl << "Capacity: " << dyncAdvArray.capacity() << endl;
	cout << "Size: " << dyncAdvArray.size() << endl << endl;


	/*������ݲ���															**/
	dyncAdvArray.clear();
	cout << endl << "DELETE DATA TEST." << endl << "Dynamic Array Size: " << dyncAdvArray.size();
	cout << endl << "Capacity: " << dyncAdvArray.capacity() << endl;
}

/*�����������																**/
void funcSingleLinkListTest()
{
	SingleLinkList linkList;

	/*������ݲ���															**/
	for (int i = 4; i <= 6; ++i)
	{
		linkList.pushBack(i);
	}

	for (int i = 3; i >= 1; --i)
	{
		linkList.pushFront(i);
	}

	cout << "ADD DATA TEST." << endl << "Single Link Size: ";
	for (int i = 0; i < linkList.size(); ++i)
	{
		cout << linkList.at(i) << " ";
	}
	cout << endl << "Size: " << linkList.size() << endl << endl;


	/*�������ݲ���															**/
	linkList.insert(0, 0);
	linkList.insert(linkList.size() / 2, 50);
	linkList.insert(linkList.size(), 100);

	cout << endl << "INSERT DATA TEST." << endl << "Single Link Size: ";
	for (int i = 0; i < linkList.size(); ++i)
	{
		cout << linkList.at(i) << " ";
	}
	cout << endl << "Size: " << linkList.size() << endl << endl;


	/*�޸����ݲ���															**/
	int curSize = linkList.size();
	for (int i = 0; i < curSize; ++i)
	{
		if (linkList.at(i) < 5)
			linkList.at(i) = 0;
	}

	cout << endl << "MODIFY DATA TEST." << endl << "Single Link Size: ";
	for (int i = 0; i < linkList.size(); ++i)
	{
		cout << linkList.at(i) << " ";
	}
	cout << endl << "Size: " << linkList.size() << endl << endl;


	/*ɾ�����ݲ���															**/
	while (true)
	{
		int delIndex = -1;
		for (int i = 0; i < linkList.size(); ++i)
		{
			if (0 == linkList.at(i))
			{
				delIndex = i;
				break;
			}
		}

		if (-1 == delIndex)
			break;
		else
			linkList.erase(delIndex);
	}

	cout << endl << "DELETE DATA TEST." << endl << "Single Link Size: ";
	for (int i = 0; i < linkList.size(); ++i)
	{
		cout << linkList.at(i) << " ";
	}
	cout << endl << "Size: " << linkList.size() << endl << endl;


	/*������ݲ���															**/
	linkList.clear();
	cout << endl << "CLEAR DATA TEST." << endl << "Single Link Size: " << linkList.size() << endl;
}

/*˫���������																**/
void funcDoubleLinkListTest()
{
	DoubleLinkList linkList;

	/*������ݲ���															**/
	for (int i = 4; i <= 6; ++i)
	{
		linkList.pushBack(i);
	}

	for (int i = 3; i >= 1; --i)
	{
		linkList.pushFront(i);
	}

	cout << "ADD DATA TEST." << endl << "Double Link Size: ";
	for (int i = 0; i < linkList.size(); ++i)
	{
		cout << linkList.at(i) << " ";
	}
	cout << endl << "Size: " << linkList.size() << endl << endl;


	///*�������ݲ���															**/
	linkList.insert(0, 0);
	linkList.insert(linkList.size() / 2, 50);
	linkList.insert(linkList.size(), 100);

	cout << endl << "INSERT DATA TEST." << endl << "Double Link Size: ";
	for (int i = 0; i < linkList.size(); ++i)
	{
		cout << linkList.at(i) << " ";
	}
	cout << endl << "Size: " << linkList.size() << endl << endl;


	/*�޸����ݲ���																**/
	int curSize = linkList.size();
	for (int i = 0; i < curSize; ++i)
	{
		if (linkList.at(i) < 5)
			linkList.at(i) = 0;
	}

	cout << endl << "MODIFY DATA TEST." << endl << "Double Link Size: ";
	for (int i = 0; i < linkList.size(); ++i)
	{
		cout << linkList.at(i) << " ";
	}
	cout << endl << "Size: " << linkList.size() << endl << endl;


	/*ɾ�����ݲ���																**/
	while (true)
	{
		int delIndex = -1;
		for (int i = 0; i < linkList.size(); ++i)
		{
			if (0 == linkList.at(i))
			{
				delIndex = i;
				break;
			}
		}

		if (-1 == delIndex)
			break;
		else
			linkList.erase(delIndex);
	}

	cout << endl << "DELETE DATA TEST." << endl << "Double Link Size: ";
	for (int i = 0; i < linkList.size(); ++i)
	{
		cout << linkList.at(i) << " ";
	}
	cout << endl << "Size: " << linkList.size() << endl << endl;


	/*������ݲ���																**/
	linkList.clear();
	cout << endl << "CLEAR DATA TEST." << endl << "Double Link Size: " << linkList.size() << endl;
}

/*˳��ջ����																**/
void funcSequenceStackTest()
{
	SequenceStack fstSeqStack;

	cout << "First Stack Push: ";
	for (int i = 1; i <= 10; ++i)
	{
		fstSeqStack.push(i);
		cout << i << " ";
	}
	cout << endl << endl;

	cout << "First Stack Size: " << fstSeqStack.size() << endl << endl;

	cout << "First Stack Pop: ";
	while (!fstSeqStack.empty())
	{
		int topVal = fstSeqStack.top();
		fstSeqStack.pop();

		cout <<  topVal << " ";
	}
	cout << endl << endl;

	SequenceStack secSeqStack(10);

	cout << "Second Stack Push: ";
	for (int i = 11; i <= 21; ++i)
	{
		secSeqStack.push(i);
		cout << i << " ";
	}
	cout << endl << endl;

	cout << "Second Stack Size: " << secSeqStack.size() << endl << endl;

	cout << "Second Stack Pop: ";
	while (!secSeqStack.empty())
	{
		int topVal = secSeqStack.top();
		secSeqStack.pop();

		cout << topVal << " ";
	}
	cout << endl << endl;
}

/*��ʽջ����																**/
void funcLinkStackTest()
{
	LinkStack fstLinkStack;

	cout << "First Stack Push: ";
	for (int i = 1; i <= 10; ++i)
	{
		fstLinkStack.push(i);
		cout << i << " ";
	}
	cout << endl << endl;

	cout << "First Stack Size: " << fstLinkStack.size() << endl << endl;

	cout << "First Stack Pop: ";
	while (!fstLinkStack.empty())
	{
		int topVal = fstLinkStack.top();
		fstLinkStack.pop();

		cout << topVal << " ";
	}
	cout << endl << endl;

	LinkStack secLinkStack(10);

	cout << "Second Stack Push: ";
	for (int i = 11; i <= 21; ++i)
	{
		secLinkStack.push(i);
		cout << i << " ";
	}
	cout << endl << endl;

	cout << "Second Stack Size: " << secLinkStack.size() << endl << endl;

	cout << "Second Stack Pop: ";
	while (!secLinkStack.empty())
	{
		int topVal = secLinkStack.top();
		secLinkStack.pop();

		cout << topVal << " ";
	}
	cout << endl << endl;
}