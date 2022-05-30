#include "SystemUser.hpp"
void help();
int load(string fileName, int& size, SystemUser accounts[], ifstream& inFile);
void login(SystemUser accounts[], int size, int& incorrect);

int main()
{
	int size=0, incorrect=0;
	SystemUser accounts[2000];
	ifstream inFile;
	string fileName, command;
	cout << "Welcome to USMASY the user management system" << endl;
	cout << "enter command:";
	cin >> command;
	while(command!="exit")
	{
		if(command=="help")
		{
			help();
		}
		else if(command=="load")
		{
			if(size==0)
			{
				cout << "enter a USMASY file name: ";
				cin >> fileName;
				load(fileName, size, accounts, inFile);
			}
			else if(size>0)
			{
				cout << "ERROR: user data already loaded." << endl;
			}
		}
		else if(command=="login")
		{
			if(size==0)
			{
				cout << "ERROR: unable to find user data" << endl;	
			}
			else if(size>0)
			{
				login(accounts, size, incorrect);
			}
		}
		else//(command!="help" || command!="load" || command!="login" || command!="exit")
		{
			cout << "ERROR: unknown command: " << command << " type help for a command list" << endl;
		}
		cout << "enter command:";
		cin >> command;
	}
	inFile.close();
	cout << "Goodbye!" << endl;
	return 0;
}
//this function opens the file, loads an array of SystemUsers then closes the file and returns the int size.
int load(string fileName, int& size, SystemUser accounts[], ifstream& inFile)
{
	inFile.open(fileName.c_str()); 
	if(inFile.fail())
	{
		cout << "unable to open " << fileName << endl;
	}
	else
	{
		while(inFile >> accounts[size])
		{
			size++;
		}
	}
	return size;
}
//this function gives a list of helpful commands
void help()
{
	cout << "The USMASY commands are: " << endl;
	cout << "* help" << endl;
	cout << "* load" << endl;
	cout << "* login" << endl;
	cout << "* exit" << endl;
	return;
}
//this function lets the user login by asking for a username and password.
void login(SystemUser accounts[], int size, int& incorrect)
{
	bool found=0;
	string inputUser, inputPw;
	cout << "username: ";
	cin >> inputUser;
	for(int i=0;i<size;i++)
	{
		while(inputUser==accounts[i].getUsername())
		{
			cout << "Password: ";
			cin >> inputPw;
			if(accounts[i].checkPassword(inputPw))
			{
				found=1;
				cout << "login successful" << endl;
				break;
			}
			else if(incorrect==2)
			{
				found=1;
				cout << "ERROR: login failed after 3 incorrect attempts" << endl;
				cout << "ERROR: incorrect password" << endl;
				incorrect=0;
				break;
			}
			else
			{
				found=1;
				cout << "ERROR: incorrect password" << endl;
				incorrect++;
			}
		}
		
	}
	if(found==0)
		{
			cout << "ERROR: unable to find user data" << endl;
		}
}
