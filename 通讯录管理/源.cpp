#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
//菜单显示功能
void showMenu() {
	cout << "*****   1、添加联系人   *****" << endl;
	cout << "*****   2、显示联系人   *****" << endl;
	cout << "*****   3、删除联系人   *****" << endl;
	cout << "*****   4、查找联系人   *****" << endl;
	cout << "*****   5、修改联系人   *****" << endl;
	cout << "*****   6、清空联系人   *****" << endl;
	cout << "*****   0、退出管理系统   ***" << endl;
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
		string phone ="0";
		cin >> phone;
		abs->personArray[abs->m_Size].m_phone = phone;
	}
};
int main() {
	//创建通讯录结构体变量
	AddressBooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	//创建用户选择变量
	int select = -1;
	while (true) {
		//菜单的调用
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
			break;
			//删除联系人
		case 3:
			break;
			//查找联系人
		case 4:
			break;
			//修改联系人
		case 5:
			break;
			//清空联系人
		case 6:
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