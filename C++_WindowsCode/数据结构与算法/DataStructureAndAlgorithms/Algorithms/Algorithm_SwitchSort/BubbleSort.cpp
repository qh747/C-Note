#include "BubbleSort.h"

void funcBubbleSort()
{
	int testArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 9, 8 };
	int arraySize = sizeof(testArray) / sizeof(testArray[0]);

	/*��ӡ����ǰ������																										**/
	cout << "Before Sort. Array: ";
	for (int i = 0; i < arraySize; ++i)
		cout << testArray[i] << " ";
	cout << endl;

	/*ð������, ���ڳ���Ϊn�����飬ֻ��Ҫ�Ƚ�n-1��Ԫ�ؼ���																	**/
	for (int foreachTimes = 0; foreachTimes < (arraySize - 1); ++foreachTimes)
	{
		int tempVal = 0;
		/*��Ϊÿһ�ֱȽϣ����ܹ���һ�����ֵ���ڶ�Ӧ��λ����, ���ÿ�ν���ѭ��ʱ��ֻ�ȶԾ���Ҫ��ȥ�ȶ�ѭ������				**/
		for (int curForeachSeq = 0; curForeachSeq < (arraySize - 1 - foreachTimes); ++curForeachSeq)
		{
			int& lftVal = testArray[curForeachSeq];
			int& rgtVal = testArray[curForeachSeq + 1];

			/*��ǰһ��Ԫ�ش��ں�һ��Ԫ��ʱ����Ҫ����ǰ��Ԫ�ص�λ��															**/
			if (lftVal > rgtVal)
			{
				tempVal = lftVal;
				lftVal = rgtVal;
				rgtVal = tempVal;
			}
		}
	}

	/*��ӡ����������																										**/
	cout << "After Sort.  Array: ";
	for (int i = 0; i < arraySize; ++i)
		cout << testArray[i] << " ";
	cout << endl;
}

void funcBubbleImproveSort()
{
	int testArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 9, 8 };
	int arraySize = sizeof(testArray) / sizeof(testArray[0]);

	/*��ӡ����ǰ������																										**/
	cout << "Before Sort. Array: ";
	for (int i = 0; i < arraySize; ++i)
		cout << testArray[i] << " ";
	cout << endl;

	/*ð������																												**/
	bool switchFlag = true;
	for (int foreachTimes = 0; foreachTimes < (arraySize - 1); ++foreachTimes)
	{
		/*��־λ�ж�, �������û�и���Ԫ��λ��, ���������������˳�ð������ѭ��											**/
		if (false == switchFlag)
			break;

		int tempVal = 0;
		/*��Ϊÿһ�ֱȽϣ����ܹ���һ�����ֵ���ڶ�Ӧ��λ����, ���ÿ�ν���ѭ��ʱ��ֻ�ȶԾ���Ҫ��ȥ�ȶ�ѭ������				**/
		switchFlag = false;
		for (int curForeachSeq = 0; curForeachSeq < (arraySize - 1 - foreachTimes); ++curForeachSeq)
		{
			int& lftVal = testArray[curForeachSeq];
			int& rgtVal = testArray[curForeachSeq + 1];

			/*��ǰһ��Ԫ�ش��ں�һ��Ԫ��ʱ����Ҫ����ǰ��Ԫ�ص�λ��															**/
			if (lftVal > rgtVal)
			{
				tempVal = lftVal;
				lftVal = rgtVal;
				rgtVal = tempVal;

				switchFlag = true;
			}
		}
	}

	/*��ӡ����������																										**/
	cout << "After Sort.  Array: ";
	for (int i = 0; i < arraySize; ++i)
		cout << testArray[i] << " ";
	cout << endl;
}
