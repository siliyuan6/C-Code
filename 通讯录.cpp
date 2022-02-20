#include <iostream>

#define MAX 1000

using namespace std;

void showMenu();
int run(struct addressBooks* abs);
void addPerson(struct addressBooks* abs);
void showPerson(struct addressBooks* abs);
int atPerson(struct addressBooks* abs, string name);
void deletePerson(struct addressBooks* abs);
void findPerson(struct addressBooks* abs);
void modifyPerson(struct addressBooks* abs);
void clearPerson(struct addressBooks* abs);

struct Person
{
	string name;
	int sex; //1男，2女
	int age;
	string phone;
	string address;
};
struct addressBooks
{
	struct Person personArray[MAX];
	int size;
};

void showMenu() {
	cout << "*****************************" << endl;
	cout << "******  1、添加联系人  ******"   << endl;
	cout << "******  2、显示联系人  ******"   << endl;
	cout << "******  3、删除联系人  ******"   << endl;
	cout << "******  4、查找联系人  ******"   << endl;
	cout << "******  5、修改联系人  ******"   << endl;
	cout << "******  6、清空联系人  ******"   << endl;
	cout << "******  0、推出通讯录  ******"   << endl;
	cout << "*****************************" << endl;
}
void addPerson(struct addressBooks* abs) {
	if (abs->size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		int sex; //1男，2女
		int age;
		string phone;
		string address;

		cout << "请输入联系人姓名：";
		cin >> name;
		abs->personArray[abs->size].name = name;
		while (true)
		{
			cout << "请输入联系人性别（数字1为男，数字2为女）：";
			cin >> sex;
			if ((sex==1)||(sex==2))
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			cout << "输入数字不合法，请重新输入。" << endl;
		}
		while (true)
		{
			cout << "请输入联系人年龄：";
			cin >> age;
			if ((age >= 0) && (age <= 200))
			{
				abs->personArray[abs->size].age = age;
				break;
			}
			cout << "输入年龄不合法，请重新输入：";
		}
		cout << "请输入联系人电话：";
		cin >> phone;
		abs->personArray[abs->size].phone = phone;
		cout << "请输入联系人地址：";
		cin >> address;
		abs->personArray[abs->size].address = address;
		abs->size++; 
		cout << "成功插入一个联系人，并返回菜单。" << endl;
		cout << endl;
	}

}
void showPerson(struct addressBooks* abs) {
	if (abs->size == 0) {
		cout << "记录为0，无法输出。" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->personArray[i].name    << '\t';
			cout << "性别：" << (abs->personArray[i].sex == 1 ? "男":"女") << '\t';
			cout << "年龄：" << abs->personArray[i].age     << '\t';
			cout << "电话：" << abs->personArray[i].phone   << '\t';
			cout << "地址：" << abs->personArray[i].address << endl;
		}
		system("pause");//按任意键继续
		system("cls");//清屏
		showMenu();
	}
}
int atPerson(struct addressBooks* abs, string name) {
	for (int i = 0; i < abs->size; i++)
	{
		if (name == abs->personArray[i].name)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}
void deletePerson(struct addressBooks* abs) {
	string name;
	cout << "请输入您要删除的人的姓名：";
	cin >> name;
	int index = atPerson(abs, name);
	if (index == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = index; i < abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;
	}
	cout << "删除成功" << endl;
	system("pause");
	system("cls");
	showMenu();
}
void findPerson(struct addressBooks* abs) {
	string name;
	cout << "请输入要查找的名字：";
	cin >> name;
	int index = atPerson(abs, name);
	if (index == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "姓名：" << abs->personArray[index].name << '\t';
		cout << "性别：" << (abs->personArray[index].sex == 1 ? "男" : "女") << '\t';
		cout << "年龄：" << abs->personArray[index].age << '\t';
		cout << "电话：" << abs->personArray[index].phone << '\t';
		cout << "地址：" << abs->personArray[index].address << endl;
	}
	system("pause");
	system("cls");
	showMenu();
}
void modifyPerson(struct addressBooks* abs) {
	string name;
	cout << "请输入需要修改的联系人：";
	cin >> name;
	int index = atPerson(abs, name);
	if (index == -1)
	{
		cout << "无此联系人" << endl;
	}
	else
	{
		cout << "姓名：" <<  abs->personArray[index].name << '\t';
		cout << "性别：" << (abs->personArray[index].sex == 1 ? "男" : "女") << '\t';
		cout << "年龄：" <<  abs->personArray[index].age << '\t';
		cout << "电话：" <<  abs->personArray[index].phone << '\t';
		cout << "地址：" <<  abs->personArray[index].address << endl;

		cout << "请输入联系人姓名：";
		cin >> abs->personArray[index].name;
		cout << "请输入联系人性别：";
		cin >> abs->personArray[index].sex;
		cout << "请输入联系人年龄：";
		cin >> abs->personArray[index].age;
		cout << "请输入联系人电话：";
		cin >> abs->personArray[index].phone;
		cout << "请输入联系人地址：";
		cin >> abs->personArray[index].address;
	}
}
void clearPerson(struct addressBooks* abs) {
	abs->size = 0;
	cout << "通讯录已清零" << endl;
	system("pause");
	system("cls");
	showMenu();
}
int run(struct addressBooks* abs) {
	showMenu();
	while (true){
		int select;
		cout << "请输入数字选择功能：";
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(abs);
			break;
		case 2:
			showPerson(abs);
			break;
		case 3:
			deletePerson(abs);
			break;
		case 4:
			findPerson(abs);
			break;
		case 5:
			modifyPerson(abs);
			break;
		case 6:
			clearPerson(abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			cout << "输入数字不合法" << endl;
			break;
		}
	}
}

int main() {

	addressBooks abs;
	abs.size = 0;
	run(&abs);

	return 0;
}
