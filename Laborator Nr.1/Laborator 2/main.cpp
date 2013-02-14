#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "om.h"
#include "nod.h"

;using namespace std;

void drawMenu(int, int);
void setColor(int, int);
void ex1(void); //Exercitiul 1 din lab
void ex2(void); //Exercitiul 4
void ex3(void); //Exercitiul 5
void ex4(void); //Exercitiul 6
void ex5(void); //Exercitiul 7

int main(int argc, char* argv[])	{

	int current = 0;
	int total = 5;

	cout.precision(2);
	cout.setf(ios_base::fixed,ios::floatfield);

	while(true)	{
		
		drawMenu(current, total);

		char command = _getch();

		switch(command)	{

			case 72:

				if(current > 0)
					current--;
                else
					current = total -1;

				break;

			case 80:
				
				if(current != (total - 1))
					current++;
                else
					current = 0;


				break;

			case 13:
				
				switch(current)	{

					case 0:
						ex1();
						break;

					case 1:
						ex2();
						break;

					case 2:
						ex3();
						break;

					case 3:
						ex4();
						break;

					case 4:
						ex5();
						break;

				}

				current = 0;

				break;

			default:

				continue;

				break;

		}

	}

}

void drawMenu(int current, int total)	{

	system("cls");
	setColor(15,0);
	for(int i = 1; i <= total ; i++)	{

		if( (i - 1) == current)	{

			setColor(12,15);
			cout << i << ")" << "Exercitiul " << i <<endl;
			setColor(15,0);

		}	else	{

			cout << i << ")" << "Exercitiul " << i <<endl;

		}

	}

}

void setColor(int fgColor, int bgColor)	{

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int k = 0;

	k |= bgColor << 4;
	k |= fgColor;

	SetConsoleTextAttribute(hConsole, k);

}




void ex1()	{
	
	system("cls");

	om Vasile, Ioan; 
	Vasile.create("Vasile", 1.78, 88); 
	Ioan.create("Ioan", 1.82, 91); 

	cout << "Numele:" <<Vasile.getName() << endl
		<< "Inaltimea: " << Vasile.getHeight()<< endl
		 << "Greutatea: " << Vasile.getWeight()<< endl<<endl; 

	cout << "Numele:" <<Ioan.getName() << endl
		 << "Inaltimea: " << Ioan.getHeight()<< endl
		 << "Greutatea: " << Ioan.getWeight()<< endl<<endl; 

	cin.get();

}

void ex2(void)	{

	system("cls");

	om *fedot = new om("Fedot", 2.10, 100);

	cout << "Numele:" <<fedot->getName() << endl
		 << "Inaltimea: " << fedot->getHeight()<< endl
		 << "Greutatea: " << fedot->getWeight()<< endl; 

	cin.get();

}

void ex3(void){
	
	system("cls");

	om *Vasile = new om("Vasile", 12.58, 98);
	Vasile->show();

	cin.get();

}

void ex4(void){

	system("cls");

	om Vasile, Ioan; 
	Vasile.create("Vasile", 1.78, 88); 
	Ioan.create("Ioan", 1.82, 91); 

	Vasile.show();
	
	cout << endl;

	Ioan.show();

	cout << (om::equals(&Vasile, &Ioan)?"Ioan si vasile sunt egali":"Ioan si vasile nu sunt egali")<<endl;

	cin.get();

}

void ex5(void){

	system("cls");

	nod first;
	nod *curent;
	curent = &first;
	char *aux;
	string name;
	float h,w;
	do	{
		cout<<"Introduceti Numele: ";
		getline(cin,name);	

		if (name.empty())
			break;

		cout<<"Introduceti inaltimea: ";
		cin>>h;	cin.ignore(256,'\n');
		cout<<"Introduceti greutatea: ";
		cin>>w;	cin.ignore(256,'\n');

		aux = (char *)malloc(name.length());
		strcpy(aux, name.c_str());

		if(curent->getO() == NULL){

			curent->setO(new om(aux, h, w));

		} else	{

			curent->setNext(new nod(new om(aux, h, w)));
			curent = curent->getNext();

		}
		cout<<endl;

	} while (!name.empty());

	cout<<"Afisam lista pastrata: "<<endl;

	curent = &first;
	while(curent->getO() != NULL && curent != NULL)	{

		curent->getO()->show();

		cout << endl;

		if(curent->getNext() == NULL)
			break;

		curent = curent->getNext();

	}

	cin.get();

}