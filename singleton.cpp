// 5ʵ��һ�������� class Singleton.
//����ģʽ��Ҫ��������:
//һ��ĳ����ֻ����һ��ʵ����
//�������������д������ʵ����
//��������������������ϵͳ�ṩ���ʵ����

//�Ӿ���ʵ�ֽǶ���˵�������������㣺
//һ�ǵ���ģʽ����ֻ�ṩ˽�еĹ��캯����
//�����ඨ���к���һ������ľ�̬˽�ж���
//���Ǹ����ṩ��һ����̬�Ĺ��еĺ������ڴ������ȡ������ľ�̬˽�ж���
#include <iostream>
using namespace std;

class Singleton//����ģʽ
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

	static Release rel;	//�����ͷŵ���ʵ��
	
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