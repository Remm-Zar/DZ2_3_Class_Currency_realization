#pragma once
#include <iostream>
#include "Currency.h"
using namespace std;
class Dollar :
    public Currency
{
public:
    Dollar(long D, unsigned char P) :Currency(D, P){}
	~Dollar()override{}
	long GetDollar()const 
	{
		return m_main;
	}
	int GetCent()const 
	{
		return m_k;
	}
	void Print()override
	{
		cout << m_main << "," << (int)m_k<<" $";
	}
	friend Dollar operator+(const Dollar& m, const Dollar& n)
	{
		unsigned char K = m.m_k + n.m_k;
		long R = m.m_main + n.m_main + K / 100;
		K = K % 100;
		return Dollar(R, K);
	}
	friend Dollar operator-(const Dollar& m, const Dollar& n)
	{
		int total = (m.m_main * 100 + m.m_k) - (n.m_main * 100 + n.m_k);
		long R = total / 100;
		unsigned char K = total % 100;
		return Dollar(R, K);
	}
	friend Dollar operator/(const Dollar& m, const Dollar& n)
	{
		double total = ((double)m.m_main * 100 + m.m_k) / ((double)n.m_main * 100 + n.m_k);
		long R = int(total);
		unsigned char K = (int)(total * 100.0) % 100;
		return Dollar(R, K);
	}
	Dollar operator/(double n)const
	{
		double total = ((double)m_main * 100 + m_k) / (n * 100);
		long R = int(total);
		unsigned char K = (int)(total * 100.0) % 100;
		return Dollar(R, K);
	}
	friend Dollar operator*(const  Dollar& m, double n);//REDONE
};
Dollar operator*(double n, const Dollar& m);

