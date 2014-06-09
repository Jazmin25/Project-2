// SHOPCLASSES SPECIFICATION FILE
#include <string>

#ifndef ShopClasses_H
#define	ShopClasses_H
using namespace std;


//VIRTUAL FUNCTION
class Total
{
protected: 
	float total;
public:
	void setTotal(float);
	virtual float getTotal() const;
};
// STUCT DATAB DISPLAYS THE ARRAY OR FLOWERS
struct DataB
{
    string Name;
    float price;
};

//CLASS ORDER USED TO PLACE ORDERS FOR BOUQUETS
class Order : public Total
{
private:
	char save;
	string to;
	string from;
    char delivery, Msg;
    string address;
	string msg;
public:
	Order();
	Order(char, char, char, string, string, string, string);
	void setSave(char);
	void setDel(char);
	void setMsg(char);
	void setTo(string);
	void setFrom(string);
	void setAdd(string);
	void setMess(string);
	char getSave() const;
	char getDel() const;
	char getMsg() const;
	string getTo() const;
	string getFrom() const;
	string getAdd() const;
	string getMess() const;
	
    
  };

//CLASS PACKAGE USED TO PURCHASE WEDDING FLOWERS
class Package : public Order
{
private:
	string phone, color1, color2;
	string flower, filler;	
	string ribColor;
public:

	void setFill(string);
	void setFlower(string);
	void setPhone(string);
	void setRCol(string);
	void setPCol(string);
	void setSCol(string);
	string getPCol() const;
	string getSCol() const;
	string getPhone() const;
	string getFill() const;
	string getFlower() const;
	string getRCol() const;

};

//TEMPLATE USED FOR RECIEVING NEWLETTER INFO
template<class T>
class MailingList
{
private:
	T email;
	T name;
public:
	MailingList();
	MailingList(T, T);
	void setEmail(T);
	void setName(T);
	T getEmail() const;
	T getName() const;
};

template<class T>
MailingList<T>::MailingList()
{email = ""; name="";		}

template<class T>
MailingList<T>::MailingList(T a, T b)
{email = a; name = b;}

template<class T>
void MailingList<T>::setEmail(T a)
{email =a;}

template<class T>
void MailingList<T>::setName(T n)
{name = n;}

template<class T>
T MailingList<T>::getEmail() const
{return email;	}

template<class T>
T MailingList<T>::getName() const
{return name;}



#endif	/* STRUCT_H */