#include <iostream>
using namespace std;

//new �Ļ����﷨
int* func() {
	int* p = new int(10);
	return p;
}
void test01() {
	int* p = func();
	cout << p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//�ͷŶ����ڴ�
	delete p;
	//�ڴ��Ѿ����ͷţ��ٴη���Ϊ�Ƿ�����
	cout << *p << endl;
}


//����new��������

void test02() {
	//����10���������ݵ�����
	int *array = new int[10];//������10��Ԫ��
	for (int i = 0; i < 10; i++) {
		array[i] = i + 100;
	}
	for (int i = 0; i < 10; i++) {
		cout << array[i] << endl;
	}
	//�ͷ�����
	delete[] array;

}




int main() {
	test02();
	system("pause");
	return 0;
};