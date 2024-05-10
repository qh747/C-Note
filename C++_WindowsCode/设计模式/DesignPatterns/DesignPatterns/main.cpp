#include "../ObjectPrinciple/OpenClosePrinciple.h"
#include "../ObjectPrinciple/DMTPrinciple.h"
#include "../ObjectPrinciple/SyncMultipPrinciple.h"
#include "../ObjectPrinciple/RelyInersionPrinciple.h"
#include "../CreateType/SimpleFactory.h"
#include "../CreateType/FactoryMethod.h"
#include "../CreateType/AbstractFactory.h"
#include "../CreateType/HungrySingleton.h"
#include "../CreateType/LazySingleton.h"
#include "../CreateType/ThreadSingleton.h"
#include "../CreateType/Builder.h"
#include "../CreateType/ProtoType.h"
#include "../StructuralType/ObjAdapter.h"
#include "../StructuralType/Facade.h"
#include "../StructuralType/ShareElement.h"
#include "../StructuralType/Proxy.h"
#include "../StructuralType/Decorator.h"
#include "../StructuralType/Component.h"
#include "../StructuralType/Bridging.h"
#include "../BehavioralType/TemplateMethod.h"
#include "../BehavioralType/Strategy.h"
#include "../BehavioralType/Observer.h"
#include "../BehavioralType/Command.h"
#include "../BehavioralType/ResponsibilityChain.h"
#include "../BehavioralType/Memento.h"
#include "../BehavioralType/Mediator.h"
#include "../BehavioralType/StateMode.h"
#include "../BehavioralType/Interpreter.h"
#include "../BehavioralType/VistorMode.h"

// ����������ԭ����Գ���
void ObjectPrincipleTestDemo();

// ���������ģʽ
void CreateTypeDesignModeTestDemo();

// �ṹ�����ģʽ
void StructrualTypeDesignModeTestDemo();

// ��Ϊ�����ģʽ
void BehavioralTypeDesignModeTestDemo();

int main()
{
	// ����������ԭ����Գ���
	// ObjectPrincipleTestDemo();

	// ���������ģʽ
	// CreateTypeDesignModeTestDemo();

	// �ṹ�����ģʽ
	// StructrualTypeDesignModeTestDemo();

	// ��Ϊ�����ģʽ
	BehavioralTypeDesignModeTestDemo();

	return 0;
}

// ����������ԭ����Գ���
void ObjectPrincipleTestDemo()
{
	// ����ԭ����Ժ���
	// OpenClosePrincipleTestDemo();

	// ���������ģʽ
	// CreateTypeDesignModeTestDemo();

	// �����ط�����Ժ���
	// DMTPrincipleTestDemo();

	// �ϳɸ��ò��Ժ���
	// SyncMultipPrincipleTestDemo();

	// ������תԭ����Ժ���
	// RelyOnInersionPrincipleTestDemo();
}

// ���������ģʽ
void CreateTypeDesignModeTestDemo()
{
	// �򵥹���ģʽ����
	// SimpleFactoryTestDemo();

	// ��������ģʽ����
	// FactoryMethodTestDemo();

	// ���󹤳�ģʽ���Ժ���
	// AbstractFactoryTestDemo();

	// ����ʽ����ģʽ���Ժ���
	// HungrySingletonTestDemo();

	// ����ʽ����ģʽ���Ժ���
	// LazySingletonTestDemo();

	// ���̵߳���ģʽ���Ժ���
	// ThreadSingletonTestDemo();

	// ������ģʽ���Ժ���
	// BuilderTestDemo();

	// ԭ��ģʽ���Ժ���
	// ProtoTypeTestDemo();
}

// �ṹ�����ģʽ
void StructrualTypeDesignModeTestDemo()
{
	// ������ģʽ���Ժ���
	// ClassAdapterTestDemo();
	// ObjAdapterTestDemo();

	// ���ģʽ���Ժ���
	// FacadeTestDemo();

	// ��Ԫģʽ���Ժ���
	// ShapeFactoryTestDemo();

	// ����ģʽ���Ժ���
	// ProxyTestDemo();

	// װ����ģʽ���Ժ���
	// DecoratorTestDemo();

	// ���ģʽ���Ժ���
	// ComponentModeTestDemo();

	// �Ž�ģʽ���Ժ���
	// BridgingModeTestDemo();
}

// ��Ϊ�����ģʽ
void BehavioralTypeDesignModeTestDemo()
{
	// ģ�巽��ģʽ���Ժ���
	// TemplateMethodTestDemo();

	// ����ģʽ���Ժ���
	// StrategyTestDemo();

	// �۲���ģʽ���Ժ���
	// ObserverTestDemo();

	// ����ģʽ���Ժ���
	// CommandTestDemo();

	// ������ģʽ���Ժ���
	// RespChainTestDemo();

	// ����ģʽ���Ժ���
	// MementoTestDemo();

	// �н���ģʽ���Ժ���
	// MediatorTestDemo();

	// ״̬ģʽ���Ժ���
	//StateTestDemo();

	// ������ģʽ���Ժ���
	// InterpreterTestDemo();

	// ������ģʽ���Ժ���
	VistorTestDemo();
}
