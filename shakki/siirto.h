#pragma once
#include "ruutu.h"


class Nappula;

// Siirto kuvaa nappulan siirtymisen ruudusta toiseen, mukaanlukien erikoissiirrot
// (linnoitus ja ohestalyönti).
class Siirto
{
public:
	Siirto(Ruutu, Ruutu);
	Siirto() {}
	Siirto(bool, bool); // Linnoitus lyhesti (K-siipi) tai pitkästi (D-siipi?
	Ruutu getAlkuruutu();
	Ruutu getLoppuruutu();
	bool onkoLyhytLinna();
	bool onkoPitkalinna();
	Nappula* _miksikorotetaan = 0;

private:
	Ruutu _alkuRuutu;
	Ruutu _loppuRuutu;
	bool _lyhytLinna;
	bool _pitkaLinna;
};


