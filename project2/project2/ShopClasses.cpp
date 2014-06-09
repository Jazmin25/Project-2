//IMPLEMENTATION FOR SHOPCLASSES
#include "ShopClasses.h"
using namespace std;

//Implementation for the class Order
//CONSTRUCTORS, ACCESSORS, MUTATORS, 
Order::Order()
{save = 0; delivery =0; Msg = 0; to = " "; from = " "; address = " "; msg = " ";}

Order::Order( char a, char b, char c,  string d, string e, string f, string g)
{save = a; delivery =b; Msg = c; to = d; from = e; address = f; msg = g;  }

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

//IMPLEMENTATION FOR THE CLASS PACKAGE
//ACCESSORS AND MUTATORS
void Package::setPhone(string a)
{phone = a;	}

void Package::setRCol(string a)
{ribColor = a;	}

void Package::setFlower(string a)
{flower =a;	}

void Package::setFill(string a)
{filler = a;}

void Package::setPCol(string b)
{color1 = b;	}

void Package::setSCol(string c)
{color2 = c;	}

string Package::getPCol() const
{ return color1;	}

string Package::getSCol() const
{return color2;	}

string Package::getFill() const
{return filler;}

string Package::getFlower() const
{return flower;		}

string Package::getPhone() const
{return phone;}

string Package::getRCol() const
{ return ribColor;}


//IMPLEMENTATIONS FOR VIRTUAL FUNCTION
float Total::getTotal() const
{	return total;}	

void Total::setTotal(float a)
{ total = a;}
