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
	int sex; //1�У�2Ů
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
	cout << "******  1�������ϵ��  ******"   << endl;
	cout << "******  2����ʾ��ϵ��  ******"   << endl;
	cout << "******  3��ɾ����ϵ��  ******"   << endl;
	cout << "******  4��������ϵ��  ******"   << endl;
	cout << "******  5���޸���ϵ��  ******"   << endl;
	cout << "******  6�������ϵ��  ******"   << endl;
	cout << "******  0���Ƴ�ͨѶ¼  ******"   << endl;
	cout << "*****************************" << endl;
}
void addPerson(struct addressBooks* abs) {
	if (abs->size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		int sex; //1�У�2Ů
		int age;
		string phone;
		string address;

		cout << "��������ϵ��������";
		cin >> name;
		abs->personArray[abs->size].name = name;
		while (true)
		{
			cout << "��������ϵ���Ա�����1Ϊ�У�����2ΪŮ����";
			cin >> sex;
			if ((sex==1)||(sex==2))
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			cout << "�������ֲ��Ϸ������������롣" << endl;
		}
		while (true)
		{
			cout << "��������ϵ�����䣺";
			cin >> age;
			if ((age >= 0) && (age <= 200))
			{
				abs->personArray[abs->size].age = age;
				break;
			}
			cout << "�������䲻�Ϸ������������룺";
		}
		cout << "��������ϵ�˵绰��";
		cin >> phone;
		abs->personArray[abs->size].phone = phone;
		cout << "��������ϵ�˵�ַ��";
		cin >> address;
		abs->personArray[abs->size].address = address;
		abs->size++; 
		cout << "�ɹ�����һ����ϵ�ˣ������ز˵���" << endl;
		cout << endl;
	}

}
void showPerson(struct addressBooks* abs) {
	if (abs->size == 0) {
		cout << "��¼Ϊ0���޷������" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "������" << abs->personArray[i].name    << '\t';
			cout << "�Ա�" << (abs->personArray[i].sex == 1 ? "��":"Ů") << '\t';
			cout << "���䣺" << abs->personArray[i].age     << '\t';
			cout << "�绰��" << abs->personArray[i].phone   << '\t';
			cout << "��ַ��" << abs->personArray[i].address << endl;
		}
		system("pause");//�����������
		system("cls");//����
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
	cout << "��������Ҫɾ�����˵�������";
	cin >> name;
	int index = atPerson(abs, name);
	if (index == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = index; i < abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;
	}
	cout << "ɾ���ɹ�" << endl;
	system("pause");
	system("cls");
	showMenu();
}
void findPerson(struct addressBooks* abs) {
	string name;
	cout << "������Ҫ���ҵ����֣�";
	cin >> name;
	int index = atPerson(abs, name);
	if (index == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "������" << abs->personArray[index].name << '\t';
		cout << "�Ա�" << (abs->personArray[index].sex == 1 ? "��" : "Ů") << '\t';
		cout << "���䣺" << abs->personArray[index].age << '\t';
		cout << "�绰��" << abs->personArray[index].phone << '\t';
		cout << "��ַ��" << abs->personArray[index].address << endl;
	}
	system("pause");
	system("cls");
	showMenu();
}
void modifyPerson(struct addressBooks* abs) {
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�";
	cin >> name;
	int index = atPerson(abs, name);
	if (index == -1)
	{
		cout << "�޴���ϵ��" << endl;
	}
	else
	{
		cout << "������" <<  abs->personArray[index].name << '\t';
		cout << "�Ա�" << (abs->personArray[index].sex == 1 ? "��" : "Ů") << '\t';
		cout << "���䣺" <<  abs->personArray[index].age << '\t';
		cout << "�绰��" <<  abs->personArray[index].phone << '\t';
		cout << "��ַ��" <<  abs->personArray[index].address << endl;

		cout << "��������ϵ��������";
		cin >> abs->personArray[index].name;
		cout << "��������ϵ���Ա�";
		cin >> abs->personArray[index].sex;
		cout << "��������ϵ�����䣺";
		cin >> abs->personArray[index].age;
		cout << "��������ϵ�˵绰��";
		cin >> abs->personArray[index].phone;
		cout << "��������ϵ�˵�ַ��";
		cin >> abs->personArray[index].address;
	}
}
void clearPerson(struct addressBooks* abs) {
	abs->size = 0;
	cout << "ͨѶ¼������" << endl;
	system("pause");
	system("cls");
	showMenu();
}
int run(struct addressBooks* abs) {
	showMenu();
	while (true){
		int select;
		cout << "����������ѡ���ܣ�";
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
			cout << "�������ֲ��Ϸ�" << endl;
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
