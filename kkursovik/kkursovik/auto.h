#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
void clrFile(ostream&fname) 
{
	fname.clear();
}
class Auto;
struct AutoType;
template<class T>
Auto * AutoMaker() 
{ 
	return new T; 
}
list<AutoType*>&get_types()
{
	static list <AutoType*> types;
	return types;
}
struct AutoType
{
	int count;
	string name;
	Auto *(*make)();
	AutoType(const char *n, Auto *(*m)())
	: name(n), make(m), count(0) 
	{
		get_types().push_back(this);
	}
};
class Auto {
	protected:
	int cost;
	int amount;
	int num_of_m;
	int year;
	int year_go;
	string type_of_oil;
	int place;
	int mass;
	int number_of;
	public:
	virtual const AutoType& Type() const = 0;
	virtual void Print(ostream&os = cout) const;
	virtual void Print2(fstream&os) const;
	virtual void Read(istream&is);
	virtual void Save(ostream&os);
	virtual void set(string *mas, Auto *d);
	virtual ~Auto() {}
};
void Auto::Save(ostream&os)
{
	os<< cost <<endl;
	os<< amount <<endl;
	os<< num_of_m <<endl;
	os<< year <<endl;
	os<<year_go<<endl;
	os<< type_of_oil <<endl;
	os<<place<<endl;
	os<<mass<<endl;
	os<<number_of<<endl;

}
void Auto::Read(istream&is)
{
	cout<< " cost: "; cin>> cost;
	cout<< " amount: "; cin>> amount;
	cout<< " num_of_m: "; cin>> num_of_m;
	cout<< " year: "; cin>> year;
	cout<< " year_go: "; cin>> year_go;
	cout<< " type_of_oil: "; cin>> type_of_oil;
	cout<< " place: "; cin>> place;
	cout<< " mass: "; cin>> mass;
	cout<< " number_of: "; cin>> number_of;
}
void Auto::set(string *mas, Auto *d)
{
	d->cost = mas[1];
	d-> amount = mas[2];
	d-> num_of_m = mas[3];
	d-> year = mas[4];
	d->year_go = mas[5];
	d-> type_of_oil = mas[6];
	d->place = mas[7];
	d->mass = mas[8];
	std::istringstream ist2(mas[9]);
	ist2 >> d->number_of;
};
void Auto::Print(ostream&os) const
{
	os<< "cost: " << cost <<endl;
	os<< "amount : " <<amount <<endl;
	os<< " num_of_m: " << num_of_m <<endl;
	os<< " year: " << year <<endl;
	os<< " yaer_go: " << year_go <<endl;
	os<< " type_of_oil: " << type_of_oil <<endl;
	os<< "place: " << place <<endl;
	os<< "mass: " << mass <<endl;
	os<< "number of: " <<number_of<<endl;
};
void Auto::Print2(ostream&os) const
{
	os<< "cost: " << cost <<endl;
	os<< "amount : " <<amount <<endl;
	os<< " num_of_m: " << num_of_m <<endl;
	os<< " year: " << year <<endl;
	os<< " yaer_go: " << yaer_go <<endl;
	os<< " type_of_oil: " << type_of_oil <<endl;
	os<< "place: " << place <<endl;
	os<< "mass: " << mass <<endl;
	os<< "number of: " <<number_of<<endl;
};
void Auto::Print3(ostream&os) const
{
	os<< "cost: " << cost <<endl;
	os<< "amount : " <<amount <<endl;
	os<< " num_of_m: " << num_of_m <<endl;
	os<< " year: " << year <<endl;
	os<< " yaer_go: " << yaer_go <<endl;
	os<< " type_of_oil: " << type_of_oil <<endl;
	os<< "place: " << place <<endl;
	os<< "mass: " << mass <<endl;
	os<< "number of: " <<number_of<<endl;
};

class l_car :public Auto 
{
	static AutoType type;
	public:
	l_car() { ++type.count; }
	void Print(ostream&os);
	void Print2(fstream&os);
	void Print3(fstream&os);
	const AutoType& Type() const { return type; }
};
class h_car :public Auto 
{
	static Auto Type type;
	public:
	h_car() { ++type.count; }
	const AutoType& Type() const { return type; }
	void Print(ostream&os);
	void Print2(fstream&os); 
	void Print3(fstream&os);
};
class t_car :public Auto 
{
	static Auto Type type;
	public:
	t_car() { ++type.count; }
	const AutoType& Type() const { return type; }
	void Print(ostream&os);
	void Print2(fstream&os); 
	void Print3(fstream&os);
};

void l_car::Print(ostream&os) { Auto::Print(os); }
void l_car::Print2(fstream&os) { Auto::Print2(os); }
void l_car::Print3(fstream&os) { Auto::Print3(os); }

void h_car::Print(ostream&os) { Auto::Print(os); }
void h_car::Print2(fstream&os) { Auto::Print2(os); }
void h_car::Print3(fstream&os) { Auto::Print3(os); }
void t_car::Print(ostream&os) { Auto::Print(os); }
void t_car::Print2(fstream&os) { Auto::Print2(os); }
void t_car::Print3(fstream&os) { Auto::Print3(os); }

AutoType l_car::type("l_car", &AutoMaker<l_car>);
AutoType h_car::type("h_car", &AutoMaker<h_car>); 
AutoType t_car::type("t_car", &AutoMaker<t_car>);


istream& operator >> (istream&is, Auto &d)
{
	d.Read(is);	return is;
}
ostream& operator<<(ostream&os, const Auto &d)
{
	d.Print(os);	return os;
}
