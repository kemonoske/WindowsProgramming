#include <iostream>
#include <windows.h>
#include "punct.h"
#include "segment.h"
#include "cerc.h"
#include "element.h"
#include <conio.h>

;using namespace std;

void ex1(void);
void ex2(void);
void ex3(void);
void drawMenu(int, int);
void setColor(int, int);

int main(int argc, char* argv[])	{

	int current = 0;
	int total = 4;

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
						exit(0);
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
			if(i == total)
				cout << i << ")" << "Iesire" <<endl;
			else
				cout << i << ")" << "Exercitiul " << i <<endl;
			setColor(15,0);

		}	else	{

			if(i == total)
				cout << i << ")" << "Iesire" <<endl;
			else
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



void ex1(void)	{

	system("cls");
	punct p(10, 20, 12312), q(50, 200, 12312); 
	cout << "Punct:" <<endl;
	p.show(); 
	cout << "Punct:" <<endl;
	q.show(); 
	segment s(10, 20, 1212, 30, 20); 
	cout << "Segment:" <<endl;
	s.show(); 
	cerc c(10, 20, 1212, 50); 
	cout << "Cerc:" <<endl;
	c.show(); 
	c.translate(1000, 1000); 
	cout << "Cerc:" <<endl;
	c.show(); 
	cin.get();

}

void ex2(void)	{

	system("cls");

	segment s(10, 20, 1212, 30, 20); 
	cout << "Segment:" <<endl;
	s.show(); 

	punct* p1 = s.secondPoint();

	cout << "Punct:" <<endl;
	p1->show();

	cin.get();

}
void ex3(void){

	system("cls");

	punct p(10, 20, 12312), q(50, 200, 12312); 
	segment s(10, 20, 1212, 30, 20); 
	cerc c(10, 20, 1212, 50); 
	c.translate(1000, 1000); 
	// Crearea listei 
	element *adr; // Adresa primului element e adr 
	element *elc; // Adresa elementului curent 
	adr = new element(&s, 1); 
	elc = adr; // Mai departe folosesc elc. 
	// Adaug cercul 
	elc->urm = new element(&c, 2); 
	elc = elc->urm; 
	// Adaug primul punct 
	elc->urm = new element(&p, 0); 
	elc = elc->urm; 
	// Afisez lista 
	// - vin pe primul element 
	elc = adr; 

	while(elc) { 
		elc->show(); 
		elc = elc ->urm; 
	}
	cin.get();

}