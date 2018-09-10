#include <list>
#include <string>
#include <iostream>
#include "auto.h"
using namespace std;

string word_in;
string mas[9];

class factory
{
	public:
	~factory();
	list<Auto*> list;
	Auto * Add(string name, istream&is);
	Auto * Add_file(string name, string id, fstream&ofs);
	void Print(string type, ostream&os);
	void Save(ostream&fr, ostream&fv,string type);
};

factory::~factory()
{
	for (Auto *ptr : list)
	delete ptr;
}

void factory::Save(ostream&fr, ostream&fv, string type){
for (Auto *ptr : list)
{
	if (ptr->Type().name == "l_car") 
	{
		fr<<ptr->Type().name <<endl;
		fr<< (*ptr) <<endl;
	}
	if (ptr->Type().name == "h_car") 
	{
		fv<<ptr->Type().name <<endl;
		fv<< (*ptr) <<endl;
	}
	if (ptr->Type().name == "t_car") 
	{
		fv<<ptr->Type().name <<endl;
		fv<< (*ptr) <<endl;
	}

}
}
Auto * factory::Add_file(string typ, string id, fstream&ofs)
{
	int i = 0;
	for (AutoType *type : get_types())
	if (type->name == typ)
	{
		Auto *ptr = type->make();
		while (ofs>>word_in)
		{
			if (word_in == typ)
			{
				ofs>>word_in;
				if (word_in == id) 
				{
					while (word_in != ";")
					{
						mas[i] = word_in;
						ofs>>word_in;
						i++;
					}
				list.push_back(ptr);
				ptr->set(mas, ptr);
				ptr->Print2(ofs);
				ptr->Print3(ofs);
				return ptr;
				}
				else 
				{
					while (word_in != ";")
					ofs>>word_in;
				}
			}
			else 
			{
				while (word_in != ";")
				ofs>>word_in;
			}
		}
	}
}

Auto * factory::Add(string name, istream&is)
{
	for (AutoType *type : get_types())
	if (type->name == name)
	{
		Auto *ptr = type->make();
		list.push_back(ptr);
		is>> (*ptr);
		return ptr;
	}
}
void factory::Print(string type, ostream&os)
{
	bool flag = (type == "");
	for (Auto *ptr : list)
	if (flag || ptr->Type().name == type)
	{
		os<<endl<< (*ptr);
	}
}
