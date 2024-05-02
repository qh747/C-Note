#pragma once
#include <iostream>
#include <string>
#include <map>
#include <stack>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::stack;

namespace Interpreter
{
	// �ı���
	class Context
	{
	public:
		Context(const string& text) : m_text(text) {}
		string getText() { return m_text; }

	private:
		string m_text;
	};
};

// �����������
class AbstractExpression
{
public:
	virtual ~AbstractExpression() {}
	virtual int interpret(const map<char, int>& dataMap) = 0;
};

// �ն˽�������
class TerminalExpression :public AbstractExpression
{
public:
	TerminalExpression(char val) : m_val(val) {}
	virtual ~TerminalExpression() {}
	virtual int interpret(const map<char, int>& dataMap) { return dataMap.at(m_val); }

private:
	char m_val;
};

// ���ն˽���������
class NonTerminalExpression : public AbstractExpression
{
public:
	NonTerminalExpression(AbstractExpression* l, AbstractExpression* r) : m_left(l), m_right(r) {}
	virtual ~NonTerminalExpression() {}

public:
	AbstractExpression* getLeft() { return m_left; }
	void setLeft(AbstractExpression* l) { m_left = l; }

	AbstractExpression* getRight() { return m_right; }
	void setRight(AbstractExpression* r) { m_right = r; }

public:
	virtual int interpret(const map<char, int>& dataMap) = 0;

protected:
	AbstractExpression* m_left;
	AbstractExpression* m_right;
};

// �ӷ���������
class AddExpresion : public NonTerminalExpression
{
public:
	AddExpresion(AbstractExpression* l, AbstractExpression* r) : NonTerminalExpression(l, r) {}
	virtual ~AddExpresion() {}
	virtual int interpret(const map<char, int>& dataMap) { return m_left->interpret(dataMap) + m_right->interpret(dataMap); }
};

// ������������
class ReduceExpresion : public NonTerminalExpression
{
public:
	ReduceExpresion(AbstractExpression* l, AbstractExpression* r) : NonTerminalExpression(l, r) {}
	virtual ~ReduceExpresion() {}
	virtual int interpret(const map<char, int>& dataMap) { return m_left->interpret(dataMap) - m_right->interpret(dataMap); }
};

// �ͻ���
class Client
{
public:
	Client() : m_pContext(NULL), m_pExpress(NULL), m_Result(0) {}
	~Client() { clearCache(); }

public:
	void setContext(Interpreter::Context* pContext) { m_pContext = pContext; }
	void setExpressMap(const map<char, int>& expressMap) { m_expressMap = expressMap; }
	int getResult() { return m_Result; }
	void expressProcess();

private:
	void clearCache() { releaseExpressionNode(m_pExpress); }
	void releaseExpressionNode(AbstractExpression* pCurrentNode);

private:
	map<char, int>              m_expressMap;
	Interpreter::Context*		m_pContext;
	AbstractExpression*			m_pExpress;
	int							m_Result;
};

// ������ģʽ���Ժ���
void InterpreterTestDemo();