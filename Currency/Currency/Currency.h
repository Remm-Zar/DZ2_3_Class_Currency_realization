#pragma once
class Currency
{
protected:
	long m_main = 0;
	unsigned char m_k = 0;
public:
	Currency(){}
	Currency(long R, unsigned char k)//REDONE
	{
		m_main = R;
		m_k = k;
	}
	virtual ~Currency() {}
	virtual void Print() = 0;
};

