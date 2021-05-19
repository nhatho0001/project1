#include"my_liprary.h"
bool check_email_student( gmail_student& a)
{
	ifstream f1;
	f1.open("gmail_student.csv", ios_base::in);
	if (f1.fail())
	{
		cout << "not file " << endl;
		return false;
	}
	int x;
	char y[50];
	cout << " + enter name email : ";
	cin >> x;
	cin.ignore();
	cout << " + enter password :";
	cin.getline(y, 49);
	   while(!f1.eof())
	   {
		  read_info_email_student(f1, a);
		   if (a.name_gmail == x)
		   {
			  if (strcmp(y, a.pw)==0)
			  {
				return true;
			  }
			return false;
		   }
	   }
	   f1.close();
	return false;
}
void read_info_email_student(ifstream& file, gmail_student& a)
{
	char b[50];
	file >> a.name_gmail;
	file.ignore();
	file.getline(b, 49,'\n');
	a.pw = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.pw, b);
	//file.ignore();
}
void create_class()
{
	fstream f;
	f.open("class.txt", ios_base::in);
	string a;
	string d;
	cout << "enter name class : ";
	getline(cin, d);
	while (!f.eof())
	{
		getline(f, a,'\n');
		if (a == d)
		{
			cout << "This class already exists" << endl;
			return;
		}
	}
	f.close();
	a = d + ".csv";
	f.open(a);
	if (f.fail())
	{
		cout << "You need to create a file for the student information of the class" << endl;
		return;
	}
	f.close();
	f.open("class.txt", ios::app);
	f <<endl<<d ;
	cout<< " you have successfully created the class " << endl;
	f.close();
}
void removed_memory(gmail_student& a)
{
	delete[]a.pw;
}
void read_info_student(ifstream& file, i_student& a)
{
	char b[50];
	file.ignore();
	file.getline(b, 49, ';');
	a.f_name = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.f_name, b);
	file.getline(b, 49, ';');
	a.l_name = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.l_name, b);
	file >> a.date;
	file.ignore();
	file >> a.month;
	file.ignore();
	file >> a.year;
	file.ignore();
	file >> a.social_id;

}
bool read_file_info_student( gmail_student& a)
{
	ifstream file;
	ifstream file2;
	string d;
	int b = 0;
	file.open("class.txt", ios_base::in);
	while (!file.eof())
	{
		getline(file, d,'\n');
		d = d + ".csv";
		file2.open(d, ios::in);
		getline(file2, d, '\n');
		while (!file2.eof())
		{
			file2 >> b;
			if (a.name_gmail == b)
			{
				read_info_student(file2, a.i_s);
				file.close();
				file2.close();
				return true;
			}
			getline(file2, d, '\n');
		}
		file2.close();
	}
	file.close();
	return false;
}