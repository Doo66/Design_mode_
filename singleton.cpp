// 5实现一个单例类 class Singleton.
//单例模式的要点有三个:
//一是某个类只能有一个实例；
//二是它必须自行创建这个实例；
//三是它必须自行向整个系统提供这个实例。

//从具体实现角度来说，就是以下三点：
//一是单例模式的类只提供私有的构造函数，
//二是类定义中含有一个该类的静态私有对象，
//三是该类提供了一个静态的公有的函数用于创建或获取它本身的静态私有对象。
#include <iostream>
using namespace std;

class Singleton//懒汉模式
{
private:
	Singleton()
	{}
	static Singleton *m_pInstance;

	class Release
	{
	public:
		~Release()
		{
			if(Singleton::m_pInstance != NULL)
				cout<<"GetInstance()"<<endl;
				delete Singleton::m_pInstance;
		}
	};

	static Release rel;	//用来释放单例实例
	
public:
	static Singleton *GetInstance()
	{
		if(m_pInstance == NULL)
		{
			cout<<"GetInstance()"<<endl;
			m_pInstance = new Singleton[10];
		}
		return m_pInstance;
	}
};



Singleton* Singleton::m_pInstance = NULL;

void test()
{
	Singleton *ss = Singleton::GetInstance();
}

int main()
{
	test();
	system("pause");
	return 0;
}