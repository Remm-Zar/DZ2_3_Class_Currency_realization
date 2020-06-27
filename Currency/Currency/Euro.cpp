#include "Euro.h"
Euro Euro::operator*(double n)
{
	double total = (static_cast<double>(m_main) * 100 + m_k) * n / 100;
	long R = int(total);
	unsigned char K = (int)(total * 100) % 100;
	return Euro(R, K);
}
/*Euro operator*(double n, const Euro& m)
{
	return m * n;
}*/