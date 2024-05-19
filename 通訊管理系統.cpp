#include<iostream>
using namespace std;
#include<string>
#define Max 1000

struct person {
	string m_name;
	string m_phone;
	int m_age;
	int m_sex;
	string m_adrs;
};


struct addressbooks {
	struct person personArray[Max];
	int m_size;
};
void showmenu()
{
	cout << "*****1.�K�[�p���H*****" << endl;
	cout << "*****2.����p���H*****" << endl;
	cout << "*****3.�R���p���H*****" << endl;
	cout << "*****4.�d���p���H*****" << endl;
	cout << "*****5.�ק��p���H*****" << endl;
	cout << "*****6.�M���p���H*****" << endl;
	cout << "*****7.�h�X�q�T��*****" << endl;
}

void addperson(addressbooks* abs)
{//abs�n�O�o�եΦa�}���ƾڤ~�వ�B��
	if (abs->m_size == Max)
	{
		cout << "�p���H�w��" << endl;
		return;
	}
	else {
		string name;
		cout << "�п�J�p���H�m�W: " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;


		cout << "�п�J�p���H�ʧO" << endl;
		cout << "1--�k" << endl;
		cout << "2--�k" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "���s��J" << endl;
		}
		cout << "�п�J�~��: " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		string phone;
		cout << "�п�J���p���H�q�ܸ��X: " << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		cout << "�п�J�p���H�a�}: " << endl;
		string adrs;
		cin >> adrs;
		abs->personArray[abs->m_size].m_adrs = adrs;

		abs->m_size++;
		cout << "�K�[���\!" << endl;
		system("pause");
		system("cls");
	}
}
void showperson(addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "��e��������" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "�m�W: " << abs->personArray[i].m_name << "\t";
			cout << "�ʧO: " << (abs->personArray[i].m_sex == 1 ? "�k" : "�k") << "\t";
			cout << "�~��: " << abs->personArray[i].m_age << "\t";
			cout << "�q��: " << abs->personArray[i].m_phone << "\t";
			cout << "��}: " << abs->personArray[i].m_adrs << endl;
		}
	}
	system("pause");//��J���N��
	system("cls");
}
int isExist(addressbooks*abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return-1;
}
void deletperson(addressbooks* abs)
{
	cout << "�п�J�z�n�R�����p���H: " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	//ret!=1�d��F
	//ret==-1�S�d��
	if(ret!=-1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			//�ƾګe��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
			cout << "�R�����\" << endl;
	}
	else
	{
		cout << "�d�L���H" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks* abs)
{
	cout << "�п�J�z�n�j�M���p���H: " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "�m�W: " << abs->personArray[ret].m_name << "\t";
		cout << "�ʧO: " << (abs->personArray[ret].m_sex == 1 ? "�k" : "�k") << "\t";
		cout << "�~��: " << abs->personArray[ret].m_age << "\t";
		cout << "�q��: " << abs->personArray[ret].m_phone << "\t";
		cout << "��}: " << abs->personArray[ret].m_adrs << endl;
	}
	else
	{
		cout << "�d�L���H" << endl;
	}
	system("pause");
	system("cls");
}
void modifyperson(addressbooks* abs)
{
	cout << "�п�J�z�n�ק諸�p���H: " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "�п�J�m�W" << endl;
		cin>>name;
		abs->personArray[ret].m_name;
		cout << "�п�J�ʧO" << endl;
		cout << "1--�k" << endl;
		cout << "2--�k" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "���s��J" << endl;
		}
		int age;
		cout << "�п�J�~��" << endl;
		cin >> sex;
		abs->personArray[ret].m_age;
		string adrs;
		cout << "�п�J��}" << endl;
		cin >> adrs;
		abs->personArray[ret].m_adrs;
		string phone;
		cout << "�п�J�q��" << endl;
		cin >> phone;
		abs->personArray[ret].m_phone;
		cout << "�ק令�\!" << endl;
	}
	else {
		cout << "�d�L���H" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(addressbooks* abs)
{
	abs->m_size = 0;
	cout << "�w�M�ũҦ��p���H" << endl;
	system("pause");
	system("cls");
}

int main() {

	//�O�o�Ыص��c���ܶq
	addressbooks abs;
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
		//{
			//cout << "�п�J�n�R�����p���H: " << endl;
			//string name;
			//cin >> name;
			//if (isExist(&abs, name) == -1)
			//{
				//cout << "�d�L���H" << endl;
			//}
			//else
			//{
				//cout << "��즹�H" << endl;

			//}
		
		// }
			deletperson(& abs);
			break;
		case 4:
			findperson(&abs);
			break;
		case 5:
			modifyperson(&abs);
			break;
		case 6:
			cleanperson(&abs);
			break;
		case 0:
			cout << "�w��U���ϥ�" << endl;
			return 0;
			break;
		default:
			break;

		}
	}


	return 0;
}