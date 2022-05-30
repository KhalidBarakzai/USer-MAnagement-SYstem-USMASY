#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;

class SystemUser
{
	public: 
	SystemUser(); //constructor
	SystemUser(string inName, string inPw); //additional constructor with user input variables
	string getUsername(); //gets username
	void setUsername(string inName); //sets username with input string
	bool checkPassword(string inPw); //checks if password is correct with login name.
	friend bool operator ==(SystemUser x, SystemUser y); 
	friend bool operator !=(SystemUser x, SystemUser y); 
	friend ostream& operator <<(ostream& out, SystemUser x);
	friend istream& operator >>(istream& out, SystemUser& x);
	
	
	private:
	string username; 
	string pw;
};
