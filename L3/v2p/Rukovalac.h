#ifndef Rukovalac_h
#define Rukovalac_h

class Posiljka;

class Rukovalac
{

public:
	virtual void obradi(Posiljka& p) = 0;
};

#endif