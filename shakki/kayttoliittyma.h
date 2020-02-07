#pragma once
#include "asema.h"
#include "nappula.h"
#include "siirto.h"


// Shakkiohjelman käyttöliittymä, joka osaa visualisoida nykyisen aseman
// ja lukea käyttäjän syöttämät siirrot.
class Kayttoliittyma
{
public:

	Kayttoliittyma(Asema* asema) { this->_asema = asema; }
	void piirraLauta();
	Siirto annaVastustajanSiirto();
	Asema* _asema;
private:

};
