#ifndef BUFF_H
#define BUFF_H

#include <string.h>

using namespace std;

class Buff
{
 public:

	 void display();
	 void setup(string type1, string value1, string key1);
	 
	 Buff()
		:type(""), value(""), key("")
	{}
	Buff(string type1, string value1, string key1)
		:type(type1), value(value1), key(key1)
	{}

	// getters and setters
	string getName(){return type;}
	void setName(string type1){type = type1;}

	string getValue(){return value;}
	void setValue(string value1){value = value1;}

	string getKey(){return key;}
	void setKey(string key1){key = key1;}
	//--------------------------------------------
 private:
   string type;
   string value;
   string key;          
};

#endif
