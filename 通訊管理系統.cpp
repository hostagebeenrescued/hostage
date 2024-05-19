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
	cout << "*****1.添加聯絡人*****" << endl;
	cout << "*****2.顯示聯絡人*****" << endl;
	cout << "*****3.刪除聯絡人*****" << endl;
	cout << "*****4.查詢聯絡人*****" << endl;
	cout << "*****5.修改聯絡人*****" << endl;
	cout << "*****6.清空聯絡人*****" << endl;
	cout << "*****7.退出通訊錄*****" << endl;
}

void addperson(addressbooks* abs)
{//abs要記得調用地址的數據才能做運算
	if (abs->m_size == Max)
	{
		cout << "聯絡人已滿" << endl;
		return;
	}
	else {
		string name;
		cout << "請輸入聯絡人姓名: " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;


		cout << "請輸入聯絡人性別" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "重新輸入" << endl;
		}
		cout << "請輸入年齡: " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		string phone;
		cout << "請輸入該聯絡人電話號碼: " << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		cout << "請輸入聯絡人地址: " << endl;
		string adrs;
		cin >> adrs;
		abs->personArray[abs->m_size].m_adrs = adrs;

		abs->m_size++;
		cout << "添加成功!" << endl;
		system("pause");
		system("cls");
	}
}
void showperson(addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "當前紀錄為空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名: " << abs->personArray[i].m_name << "\t";
			cout << "性別: " << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年齡: " << abs->personArray[i].m_age << "\t";
			cout << "電話: " << abs->personArray[i].m_phone << "\t";
			cout << "住址: " << abs->personArray[i].m_adrs << endl;
		}
	}
	system("pause");//輸入任意鍵
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
	cout << "請輸入您要刪除的聯絡人: " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	//ret!=1查到了
	//ret==-1沒查到
	if(ret!=-1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			//數據前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
			cout << "刪除成功" << endl;
	}
	else
	{
		cout << "查無此人" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks* abs)
{
	cout << "請輸入您要搜尋的聯絡人: " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名: " << abs->personArray[ret].m_name << "\t";
		cout << "性別: " << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年齡: " << abs->personArray[ret].m_age << "\t";
		cout << "電話: " << abs->personArray[ret].m_phone << "\t";
		cout << "住址: " << abs->personArray[ret].m_adrs << endl;
	}
	else
	{
		cout << "查無此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyperson(addressbooks* abs)
{
	cout << "請輸入您要修改的聯絡人: " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "請輸入姓名" << endl;
		cin>>name;
		abs->personArray[ret].m_name;
		cout << "請輸入性別" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "重新輸入" << endl;
		}
		int age;
		cout << "請輸入年齡" << endl;
		cin >> sex;
		abs->personArray[ret].m_age;
		string adrs;
		cout << "請輸入住址" << endl;
		cin >> adrs;
		abs->personArray[ret].m_adrs;
		string phone;
		cout << "請輸入電話" << endl;
		cin >> phone;
		abs->personArray[ret].m_phone;
		cout << "修改成功!" << endl;
	}
	else {
		cout << "查無此人" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(addressbooks* abs)
{
	abs->m_size = 0;
	cout << "已清空所有聯絡人" << endl;
	system("pause");
	system("cls");
}

int main() {

	//記得創建結構體變量
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
			//cout << "請輸入要刪除的聯絡人: " << endl;
			//string name;
			//cin >> name;
			//if (isExist(&abs, name) == -1)
			//{
				//cout << "查無此人" << endl;
			//}
			//else
			//{
				//cout << "找到此人" << endl;

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
			cout << "歡迎下次使用" << endl;
			return 0;
			break;
		default:
			break;

		}
	}


	return 0;
}