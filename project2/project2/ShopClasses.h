#include <string>

#ifndef ShopClasses_H
#define	ShopClasses_H
using namespace std;

struct DataB
{
    string Name;
    float price;
};

class Order
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

class Package : public Order
{
private:
	string phone, color1, color2;
	string flower, filler;
	int totalOrder;	
	string ribColor;
public:

	void setFill(string);
	void setFlower(string);
	void setPhone(string);
	void setRCol(string);
	void setTotal(int );
	void setPCol(string);
	void setSCol(string);
	string getPCol() const;
	string getSCol() const;
	string getPhone() const;
	string getFill() const;
	string getFlower() const;
	string getRCol() const;
	int getTotal() const;
	
};

class MailingList
{
private:
	string email;
	string name;
public:
	MailingList();
	MailingList(string, string);
	void setEmail(string);
	void setName(string);
	string getEmail() const;
	string getName() const;


};


#endif	/* STRUCT_H */