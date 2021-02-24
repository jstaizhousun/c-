#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
//�˵���ʾ����
void showMenu() {
	cout << "*****************************" << endl;
	cout << "*****   1�������ϵ��   *****" << endl;
	cout << "*****   2����ʾ��ϵ��   *****" << endl;
	cout << "*****   3��ɾ����ϵ��   *****" << endl;
	cout << "*****   4��������ϵ��   *****" << endl;
	cout << "*****   0���˳�����ϵͳ   ***" << endl;
	cout << "*****************************" << endl;
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
//�����ϵ��
void addPerson(AddressBooks* abs) {
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
	}
	else {
		//��Ӿ�����ϵ��
		//����
		cout << "����������" << endl;
		cin >> abs->personArray[abs->m_Size].m_name;
		//�Ա�
		cout << "�������Ա�1Ϊ�У�2ΪŮ" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "������������������Ա�1Ϊ�У�2ΪŮ" << endl;
			}
		};
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "������绰" << endl;
		string phone = "0";
		cin >> phone;
		abs->personArray[abs->m_Size].m_phone = phone;
		//סַ
		cout << "������סַ" << endl;
		string address = "0";
		cin >> address;
		abs->personArray[abs->m_Size].m_addr = address;
		//��������
		abs->m_Size++;
	}
};
//��ʾ��ϵ��
void showPerson(AddressBooks* abs) {
	if (abs->m_Size == 0) {
		cout << "��ϵ��Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_addr << endl;
		}
	}
};
//ɾ����ϵ��
void delPerson(AddressBooks*p){
	string name;
	cout << "��������ϵ������" << endl;
	cin >> name;
	//�����Ƿ������ϵ��
	for (int i = 0; i < p->m_Size; i++) {
		if (p->personArray[i].m_name == name) {
			for (int j = i; j < p->m_Size; j++) {
				p->personArray[i] = p->personArray[i + 1];
			}
			p->m_Size--;
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "���޴���" <<endl;
		}
	}
}
//������ϵ��
void findPerson(AddressBooks* p) {
	string name;
	cout << "��������ϵ������" << endl;
	cin >> name;
	for (int i = 0; i < p->m_Size; i++) {
		if (p->personArray[i].m_name == name) {
			cout << "������" << p->personArray[i].m_name << "\t";
			cout << "�Ա�" << (p->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << p->personArray[i].m_Age << "\t";
			cout << "�绰��" << p->personArray[i].m_phone << "\t";
			cout << "סַ��" << p->personArray[i].m_addr << endl;
		}
		else {
			cout << "���޴���" << endl;
		}
	}
}
int main() {
	//����ͨѶ¼�ṹ�����
	AddressBooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	//�����û�ѡ�����
	int select = -1;
	while (true) {
		//�˵��ĵ���
		system("cls");
		showMenu();
		//��ȡ�û�������Ϣ
		cin >> select;
		switch (select) {
			//�����ϵ��
		case 1:
			addPerson(&abs);
			break;
			//��ʾ��ϵ��
		case 2:
			showPerson(&abs);
			system("pause");
			break;
			//ɾ����ϵ��
		case 3:
			delPerson(&abs);
			system("pause");
			break;
			//������ϵ��
		case 4:
			findPerson(&abs);
			system("pause");
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