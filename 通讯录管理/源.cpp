#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
//�˵���ʾ����
void showMenu() {
	cout << "*****   1�������ϵ��   *****" << endl;
	cout << "*****   2����ʾ��ϵ��   *****" << endl;
	cout << "*****   3��ɾ����ϵ��   *****" << endl;
	cout << "*****   4��������ϵ��   *****" << endl;
	cout << "*****   5���޸���ϵ��   *****" << endl;
	cout << "*****   6�������ϵ��   *****" << endl;
	cout << "*****   0���˳�����ϵͳ   ***" << endl;
};
//��ϵ�˽ṹ��
struct Person {
	//����
	string m_name;
	//�Ա�
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_phone;
	//��ַ
	string m_addr;
};
//ͨѶ¼�ṹ��
struct AddressBooks {
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼�ĸ���
	int m_Size;
};
int main() {
	//����ͨѶ¼�ṹ�����
	AddressBooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	//�����û�ѡ�����
	int select = -1;
	while (true) {
		//�˵��ĵ���
		showMenu();
		//��ȡ�û�������Ϣ
		cin >> select;
		switch (select) {
			//�����ϵ��
		case 1:
			break;
			//��ʾ��ϵ��
		case 2:
			break;
			//ɾ����ϵ��
		case 3:
			break;
			//������ϵ��
		case 4:
			break;
			//�޸���ϵ��
		case 5:
			break;
			//�����ϵ��
		case 6:
			break;
			//�˳�ϵͳ
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		};
	}
}