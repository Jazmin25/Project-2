//Implementation of ShopClasses
#include "ShopClasses.h"
using namespace std;
char save;
	string to;
	string from;
    char delivery, Msg;
    string address;
	string msg;

Order::Order()
{save = 0; delivery =0; Msg = 0; to = " "; from = " "; address = " "; msg = " ";}
Order::Order( char a, char b, char c, string d, string e, string f, string g)
{save =a; delivery = b; Msg = c; to = d; from = e; address = f; msg = g; }
void Order::setSave(char a)
{save = toupper(a);}
void Order::setDel(char b)
{delivery = toupper(b);}
void Order::setMsg(char c)
{Msg = toupper(c);}
void Order::setTo(string d)
{to = d;}
void Order::setFrom(string e)
{from =e;}
void Order::setAdd(string f)
{address = f;}
void Order::setMess(string g)
{msg =g;}
char Order::getSave() const
{return save;}
char Order::getDel() const
{return delivery;}
char Order::getMsg() const
{return Msg;}
string Order::getTo() const
{return to;}
string Order::getFrom() const
{return from;}
string Order::getAdd() const
{return address;}
string Order::getMess() const
{return msg;}
