#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

/*��ҵ������    **/
class AbstractHomework
{
public:
	virtual ~AbstractHomework() { }

public:
	virtual void setTitle(const string& title) = 0;
	virtual string getTitle() = 0;

	virtual void setQuestion(const string& question) = 0;
	virtual string getQuestion() = 0;

	virtual void setStudentName(const string& stuName) = 0;
	virtual string getStudentName() = 0;

public:
	virtual AbstractHomework* clone() = 0;
};

/*������ҵ    **/
class ChineseHomework : public AbstractHomework
{
public:
	ChineseHomework() { }
	virtual ~ChineseHomework() { }

public:
	virtual void setTitle(const string& title) { m_homeworkTitle = title; }
	virtual string getTitle() { return m_homeworkTitle; }

	virtual void setQuestion(const string& question) { m_homeworkQuestion = question; }
	virtual string getQuestion() { return m_homeworkQuestion; }

	virtual void setStudentName(const string& stuName) { m_studentName = stuName; }
	virtual string getStudentName() { return m_studentName; }

public:
	virtual AbstractHomework* clone()	/*��¡���е���ҵģ��    **/
	{
		ChineseHomework* homeworkPtr = new ChineseHomework();
		homeworkPtr->setTitle(this->m_homeworkTitle);
		homeworkPtr->setQuestion(this->m_homeworkQuestion);
		homeworkPtr->setStudentName(this->m_studentName);

		return homeworkPtr;
	}

private:
	string m_homeworkTitle;
	string m_homeworkQuestion;
	string m_studentName;
};

/*��ѧ��ҵ    **/
class MathHomework : public AbstractHomework
{
public:
	MathHomework() { }
	virtual ~MathHomework() { }

public:
	virtual void setTitle(const string& title) { m_homeworkTitle = title; }
	virtual string getTitle() { return m_homeworkTitle; }

	virtual void setQuestion(const string& question) { m_homeworkQuestion = question; }
	virtual string getQuestion() { return m_homeworkQuestion; }

	virtual void setStudentName(const string& stuName) { m_studentName = stuName; }
	virtual string getStudentName() { return m_studentName; }

public:
	virtual AbstractHomework* clone()	/*��¡���е���ҵģ��    **/
	{
		MathHomework* homeworkPtr = new MathHomework();
		homeworkPtr->setTitle(this->m_homeworkTitle);
		homeworkPtr->setQuestion(this->m_homeworkQuestion);
		homeworkPtr->setStudentName(this->m_studentName);

		return homeworkPtr;
	}

private:
	string m_homeworkTitle;
	string m_homeworkQuestion;
	string m_studentName;
};

void showHomework(AbstractHomework* homeworkPtr)
{
	cout << "Homework Title: " << homeworkPtr->getTitle() << endl;
	cout << "Homework Question: " << homeworkPtr->getQuestion() << endl;
	cout << "Student Name: " << homeworkPtr->getStudentName() << endl;
}

/*��ҵ�ɷ�����    **/
void distributeHomework(AbstractHomework* homeworkPtr, const vector<string>& studentArray)
{
	for (int i = 0; i < studentArray.size(); ++i)
	{
		AbstractHomework* thisStudentHomeWorkPtr = homeworkPtr->clone();
		string thisStudentName = studentArray.at(i);
		thisStudentHomeWorkPtr->setStudentName(thisStudentName);

		showHomework(thisStudentHomeWorkPtr);
		cout << "Distrubute Success." << endl << endl;

		delete thisStudentHomeWorkPtr;
		thisStudentHomeWorkPtr = NULL;
	}
}

int main()
{
	/*�����༶    **/
	vector<string> studentArray;
	studentArray.push_back(string("Peter"));
	studentArray.push_back(string("John"));
	studentArray.push_back(string("Lisa"));

	/*����������ҵģ��    **/
	AbstractHomework* chineseHomeworkPtr = new ChineseHomework();
	chineseHomeworkPtr->setTitle(string("Chinese"));
	chineseHomeworkPtr->setQuestion(string("Introduce Yourself In 300 Words ."));
	chineseHomeworkPtr->setStudentName(string("xxx"));

	/*�ɷ�������ҵ    **/
	distributeHomework(chineseHomeworkPtr, studentArray);

	/*������ѧ��ҵģ��    **/
	AbstractHomework* mathHomeworkPtr = new MathHomework();
	mathHomeworkPtr->setTitle(string("Math"));
	mathHomeworkPtr->setQuestion(string("Calculate One Plus One Equals To ?"));
	mathHomeworkPtr->setStudentName(string("xxx"));

	/*�ɷ���ѧ��ҵ    **/
	distributeHomework(mathHomeworkPtr, studentArray);

	delete chineseHomeworkPtr;
	chineseHomeworkPtr = NULL;

	delete mathHomeworkPtr;
	mathHomeworkPtr = NULL;

	system("pause");
	return 0;
}