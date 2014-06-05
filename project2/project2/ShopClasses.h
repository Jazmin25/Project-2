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

class SP : public Order
{
private:
	string phone;
	int ribColor;
	int ballColor;
public://NOTE MUST DO VIRTUAL FUNCTION & TEMPLETE EMAIL FOR ANYTHING ELSE BUILD ON WEDDING AND MAYBE ADD FUNERAL
	void setPhone(string);
	void setRCol(int);
	void setBColor(int);
	string getPhone() const;
	int getRCol() const;
	int getBCol() const;
};






#endif	/* STRUCT_H */