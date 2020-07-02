#include <iostream>
#include "Dollar.h"
#include "Euro.h"
using namespace std;
void Print(Currency* c)
{
	cout << endl;
	c->Print();
}
int main()
{
	Currency* base;
	Dollar *DerDollar,d(12, 34), d1(23, 45),d2(d+d1);
	Euro *DerEuro,e(34, 56), e1(456, 76),e2(e+e1);
	cout << "\n\\\\Polimorthism (1)////\n";
	base = &d2;
	Print(base);
	base = &e2;
	Print(base);
	cout << "\n\\\\Virtual functions calls. Polimorthism (2)////\nDollar Print(): ";
	//вызов виртуальных фунуций через указатель на базовый класс
	base = &d1;
	base->Print();
	cout << "\nEuro Print():  ";
	base = &e1;
	base->Print();
	cout << "\n\\\\\ Usual methods calls/////";
	//вызовы обычных методов с помощью указателей 
	DerDollar = new Dollar(12,86);
	DerEuro = new Euro(45,99);
	//Dollar works
	cout << "\nDollars: "<<DerDollar->GetDollar();	
	cout << " Cents: "<<DerDollar->GetCent();
	cout << "\n*DerDollar+d1=";
	(*DerDollar + d1).Print();
	cout << "\nd1-*DerDollar=";
	(d1-*DerDollar ).Print();
	//Euro works
	cout << "\nEuro: " << DerEuro->GetEuro();
	cout << " Cents: " << DerEuro->GetCent();
	cout << "\n*DerEuro+e1=";
	(*DerEuro + e1).Print();
	cout << "\n*DerEuro/e1=";
	(*DerEuro/e1).Print();
	delete DerDollar;
	delete DerEuro;
	return 0;
}
