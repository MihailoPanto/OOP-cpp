#ifndef VOznaka_h
#define VOznaka_h
#include<ostream>
#include <string>

using namespace std;

class VOznaka
{

	int god, mes, dan, sat, min;

public:

	VOznaka(int go, int me, int da, int sa, int mi) :god(go), mes(me), dan(da), sat(sa), min(mi) {}

	friend ostream& operator <<(ostream& it, const VOznaka& v) {
		return it << v.dan << '.' << v.mes << '.' << v.god << '-' << v.sat << ':' << v.min;
	}
};

#endif
