#pragma once
#include <iostream>
#include "Currency.h"
using namespace std;
class Euro :public Currency
{	public:
    Euro(){}
	Euro(long D, unsigned char P) : Currency(D, P)
	{}
	~Euro()override{}
	void Print()override
	{
		cout << m_main << "," << (int)m_k<<" EU";
	}
	long GetEuro()const
	{
		return m_main;
	}
	int GetCent()const
	{
		return m_k;
	}
	Euro RubConvert()const
	{
		Euro temp(*this);
		temp=temp * 70.0 / 65.0;
		return temp;
	}
	friend Euro operator+(const Euro& m, const Euro& n)
	{
		unsigned char K = m.m_k + n.m_k;
		long R = m.m_main + n.m_main + K / 100;
		K = K % 100;
		return Euro(R, K);
	}
	friend Euro operator-(const Euro& m, const Euro& n)
	{
		int total = (m.m_main * 100 + m.m_k) - (n.m_main * 100 + n.m_k);
		long R = total / 100;
		unsigned char K = total % 100;
		return Euro(R, K);
	}
	friend Euro operator/(const Euro& m, const Euro& n)
	{
		double total = ((double)m.m_main * 100 + m.m_k) / ((double)n.m_main * 100 + n.m_k);
		long R = int(total);
		unsigned char K = (int)(total * 100.0) % 100;
		return Euro(R, K);
	}
	Euro operator/(double n)
	{
		double total = ((double)m_main * 100 + m_k) / (n * 100);
		long R = int(total);
		unsigned char K = (int)(total * 100.0) % 100;
		return Euro(R, K);
	}
	Euro operator*(double n);
};

//Euro operator*(double n, const Euro& m);
