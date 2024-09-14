#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
	int c;
	cout <<"\t\t\t_____________________________________________________\n\n\n";
	cout <<"\t\t\t              Welcome to the login page               \n\n\n";
	cout <<"\t\t\t____________________    Menu    _______________________\n\n";
	cout <<"                                                              \n\n";
	cout <<"\t| Press 1 to LOGIN                        |"<<endl;
	cout <<"\t| Press 2 to REGISTER                     |"<<endl;
	cout <<"\t| Press 3 to if you forgot your PASSWORD  |"<<endl;
	cout <<"\t| Press 4 to EXIT                         |"<<endl;
	cout <<"\n\t\t\t Please enter your choice ::";
	cin >> c;
	cout << endl;

	switch (c)
	{
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout << "\t\t\t Thank you! \n\n";
			break;
		default:
			system("cls");
			cout << "\t\t\t Please select from the option given above \n"<<endl;
			main();
	}
}

void login()
{
	int count;
	string userId, password, id, pass;
	system("cls");
	cout << "\t\t\t Please enter your Username & Password";
	cout << "\t\t\t Username : ";
	cin >> userId;
	cout << "\t\t\t Password :";
	cin >> password;

	ifstream input("records.txt");

	while (input >> id >> pass)
	{
		int count;
		if (id == userId && pass == password)
		{
			count = 1;
			system("cls");
		}
	}
	input.close();

	if (count == 1)
	{
		cout << userId << "\n Your LOGIN successfully! \n Thanks for logging! \n";
		main();
	}
	else
	{
		cout << "\n LOGIN Error \n Please check your username & password \n";
		main();
	}
}

void registration()
{
	string reguserId, regpassword, regid, regpass;
	system("cls");
	cout << "\t\t\t Enter the Username Please : ";
	cin >> reguserId;
	cout << "\t\t\t Enter the Password : ";
	cin >> regpassword;

	ofstream f1("records.txt", ios::app);
	f1 << reguserId << '  ' << regpassword <<endl;
	system("cls");
	cout << "\n\t\t\t Registration is successfully! \n";
	main();

}

void forgot()
{
	int option;
	system("cls");
	cout << "\t\t\t Your forgot the password? No worries! \n";
	cout << "Press 1 to search your id by username : " << endl;
	cout << "Press 2 to go back to the main menu : " << endl;
	cout << "\t\t\t Enter your choice please : ";
	cin >> option;

	switch (option)
	{
		case 1:
		{
			int count = 0;
			string suserId, sId, spass;
			cout << "\n\t\t\t Enter the username which you remembered : ";
			cin >> suserId;

			ifstream f2("records.txt");
			while (f2 >> sId >> spass)
			{
				if (sId == suserId)
				{
					count = 1;
				}
			}
			f2.close();

			if (count == 1)
			{
				cout << "\n\n Your account is found! \n";
				cout << "\n\n Your password is : " << spass;
				main();
			}
			else
			{
				cout << "\n\t Sorry! Your account is not found! \n";
				main();
			}
			break;
		}
		case 2:
		{
			main();
		}
		default:
			cout << "\t\t\t Wrong choice! Please try again" <<endl;
			forgot();
	}
}
