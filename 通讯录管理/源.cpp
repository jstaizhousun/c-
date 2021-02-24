#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
//菜单显示功能
void showMenu() {
	cout << "*****************************" << endl;
	cout << "*****   1、添加联系人   *****" << endl;
	cout << "*****   2、显示联系人   *****" << endl;
	cout << "*****   3、删除联系人   *****" << endl;
	cout << "*****   4、查找联系人   *****" << endl;
	cout << "*****   0、退出管理系统   ***" << endl;
	cout << "*****************************" << endl;
};
//联系人结构体
struct Person {
	//姓名
	string m_name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_phone;
	//地址
	string m_addr;
};
//通讯录结构体
struct AddressBooks {
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录的个数
	int m_Size;
};
//添加联系人
void addPerson(AddressBooks* abs) {
	//判断通讯录是否已满
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
	}
	else {
		//添加具体联系人
		//姓名
		cout << "请输入姓名" << endl;
		cin >> abs->personArray[abs->m_Size].m_name;
		//性别
		cout << "请输入性别，1为男，2为女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "输入错误，请重新输入性别，1为男，2为女" << endl;
			}
		};
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入电话" << endl;
		string phone = "0";
		cin >> phone;
		abs->personArray[abs->m_Size].m_phone = phone;
		//住址
		cout << "请输入住址" << endl;
		string address = "0";
		cin >> address;
		abs->personArray[abs->m_Size].m_addr = address;
		//计数增加
		abs->m_Size++;
	}
};
//显示联系人
void showPerson(AddressBooks* abs) {
	if (abs->m_Size == 0) {
		cout << "联系人为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_phone << "\t";
			cout << "住址：" << abs->personArray[i].m_addr << endl;
		}
	}
};
//删除联系人
void delPerson(AddressBooks*p){
	string name;
	cout << "请输入联系人姓名" << endl;
	cin >> name;
	//查找是否存在联系人
	for (int i = 0; i < p->m_Size; i++) {
		if (p->personArray[i].m_name == name) {
			for (int j = i; j < p->m_Size; j++) {
				p->personArray[i] = p->personArray[i + 1];
			}
			p->m_Size--;
			cout << "删除成功" << endl;
		}
		else {
			cout << "查无此人" <<endl;
		}
	}
}
//查找联系人
void findPerson(AddressBooks* p) {
	string name;
	cout << "请输入联系人姓名" << endl;
	cin >> name;
	for (int i = 0; i < p->m_Size; i++) {
		if (p->personArray[i].m_name == name) {
			cout << "姓名：" << p->personArray[i].m_name << "\t";
			cout << "性别：" << (p->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << p->personArray[i].m_Age << "\t";
			cout << "电话：" << p->personArray[i].m_phone << "\t";
			cout << "住址：" << p->personArray[i].m_addr << endl;
		}
		else {
			cout << "查无此人" << endl;
		}
	}
}
int main() {
	//创建通讯录结构体变量
	AddressBooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	//创建用户选择变量
	int select = -1;
	while (true) {
		//菜单的调用
		system("cls");
		showMenu();
		//获取用户输入信息
		cin >> select;
		switch (select) {
			//添加联系人
		case 1:
			addPerson(&abs);
			break;
			//显示联系人
		case 2:
			showPerson(&abs);
			system("pause");
			break;
			//删除联系人
		case 3:
			delPerson(&abs);
			system("pause");
			break;
			//查找联系人
		case 4:
			findPerson(&abs);
			system("pause");
			break;
			//退出系统
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		};
	}
}