#include "SystemUser.hpp"


SystemUser::SystemUser()
{
	username="empty";
	pw="empty";
}
SystemUser::SystemUser(string inName, string inPw)
{
	username=inName;
	pw=inPw;
}
string SystemUser::getUsername()
{
	return username;
}
void SystemUser::setUsername(string inName)
{
	username=inName;
}
bool SystemUser::checkPassword(string inPw)
{
	pw==inPw;
	if(pw!=inPw)
		{
			return false;
		}
	else 
	{
		return true;
	}
}

bool operator ==(SystemUser x, SystemUser y)
{
	
	if(x.username==y.username)
	{
		return true;
	}
}

bool operator !=(SystemUser x, SystemUser y)
{
	if(x.username!=y.username)
	{
		return false;
	}
}
ostream& operator <<(ostream& out, SystemUser x)
{
	out << "Username: "<< x.username << endl;
	out << "Password: " << x.pw;
	return out;
}
istream& operator >>(istream& in, SystemUser& x)
{
	in >> x.username;
	in >> x.pw;
	return in;
}

