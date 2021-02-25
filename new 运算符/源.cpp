#include <iostream>
using namespace std;

//new 的基本语法
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
	//释放堆区内存
	delete p;
	//内存已经被释放，再次访问为非法操作
	cout << *p << endl;
}


//利用new开辟数组

void test02() {
	//创建10个整形数据的数组
	int *array = new int[10];//数组有10个元素
	for (int i = 0; i < 10; i++) {
		array[i] = i + 100;
	}
	for (int i = 0; i < 10; i++) {
		cout << array[i] << endl;
	}
	//释放数组
	delete[] array;

}




int main() {
	test02();
	system("pause");
	return 0;
};