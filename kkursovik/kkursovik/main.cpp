#include <iostream> 
#include <string> 
#include <fstream> 
#include <conio.h> 
#include "factory.h" 
using namespace std; 

int main() 
{ 
	setlocale (LC_ALL, "RUSSIAN"); 
	string word_in, file_in, file_in2; 
	fstreamfilestr("tree.txt", fstream::in | fstream::out); 
	file_in2 = (" tree.txt"); 
	ofstream fout("one.txt"); 
	ofstream fout2("two.txt"); 
	ofstream fout3("tre.txt"); 
	factory list; 
	string type; 
	string otobraj; 
	char choice = 0; 
	do 
	{ 
		system("cls"); 
		if (choice == 'a' || choice == 'A') 
		{ 
			cout << "input characteristics from a file or console (file, concole)"; cin >> otobraj; 
			cout << "Input auto type (l_car or h_car or t_car ) ->"; 
			int kol = 0; 
			string type; 
			metka1: cin >> type; 
			if (type != "l_car" && type != "h_car"&& type != "t_car"  ) 
			{ 
				cout << "entered an incorrect type! Try again :" << endl;
				goto metka1;
			 } 
			else 
			{ 
				if (otobraj == "File" || otobraj == "file" || otobraj == "f") 
				{ 
					fstream filestr("tree.txt", fstream::in | fstream::out); 
					while (filestr >> word_in) 
					{ 
						if (word_in == type) 
						{ 
							while (word_in != ";") { filestr >> word_in; } 
							kol++; 
						} 
						else 
						{ 
							while (word_in != ";")filestr >> word_in; 
						} 
					} 
					filestr.close(); 
					fstream filestr1("tree.txt", fstream::in | fstream::out); 
					string id; 
					cout << "number of characteristics = " << kol << endl << "Choose 						charachteristic ->"; 
					cin >> id; 
					list.Add_file(type, id, filestr1); 
					filestr1.close(); 
				} 
				else 
				{ 
					list.Add(type, cin);
				 } 
			} 
		} 

		else 
			if (choice == 'p' || choice == 'P') 
			{ 
				cout << "Example from file or console (file, console)"; cin >> otobraj; 
				cout << "Input auto type (l_car or h_car or t_car) ->"; 
				metka2: cin >> type; 
				if (type != "l_car" && type != "h_car"&& type != "t_car"  )
 				{ 
					cout << "entered an incorrect type! Try again :" << endl; 
					goto metka2; 
				} 
				else 
				{ 
					if (otobraj == "File" || otobraj == "file" || otobraj == "f") 
					{ 
						fstreamfilestr("tree.txt", fstream::in | fstream::out); 
						while (filestr >> word_in) 
						{ 
							if (word_in == type) 
							{ 
								while (word_in != ";")
								 { 
									cout << word_in << endl; 
									filestr >> word_in; 
								} 
							} 
						} 
						filestr.close(); 
					} 
					else 
					{ 
						list.Print(type, cout);
					} 
				} 
			} 
			else 
				if (choice == 's' || choice == 'S') 
				{ 
					list.Save(fout,fout2,fout3, type); 
					cout << "saved " << endl; 
				} 
		cout << endl << 
		"A - add new element to list" << endl 
		<< "P - print list of auto" << endl 
		<< "S - save results into file" << endl 
		<< "Q - quit" << endl; 

	} while ((choice =_getch()) != 'q' && choice != 'Q'); 
	fout.close(); 
}
