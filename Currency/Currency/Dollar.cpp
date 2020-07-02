#include "Dollar.h"
Dollar operator*(const Dollar& m, double n)
{
	double total = ((double)m.m_main * 100 + m.m_k )* n / 100;
	long R = int(total);
	unsigned char K = (int)(total * 100) % 100;
	return Dollar(R, K);
}
Dollar operator*(double n, const Dollar& m)
{
	return m * n;
}