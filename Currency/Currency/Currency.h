#pragma once
class Currency
{
protected:
	long m_main = 0;
	unsigned char m_k = 0;
public:
	Currency(){}
	Currency(long R, int k)
	{
		m_main = R;
		m_k = (unsigned char)k;
	}
	virtual ~Currency() {}
	virtual void Print() = 0;
};

