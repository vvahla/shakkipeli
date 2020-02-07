#pragma once
#include "asema.h"
#include "nappula.h"
#include "siirto.h"


// Shakkiohjelman k�ytt�liittym�, joka osaa visualisoida nykyisen aseman
// ja lukea k�ytt�j�n sy�tt�m�t siirrot.
class Kayttoliittyma
{
public:

	Kayttoliittyma(Asema* asema) { this->_asema = asema; }
	void piirraLauta();
	Siirto annaVastustajanSiirto();
	Asema* _asema;
private:

};
