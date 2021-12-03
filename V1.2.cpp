#include "headeris.h"
//---------------------------------------------------------------------------------------------------------------------------
int main()
{
	cout << "------------------------------------------------------------------------------------------------" << endl;
	Studentas studentas;
	vector<Studentas> Eil;
	vector<Studentas> nuskriaustukai;
	vector<Studentas> galvotukai;
	int studentu_kiekis = 1000000;
	//---------------------------------------------------------------------------------------------------------------------------
	pagrindinio_failo_kurimas(studentu_kiekis);
	pagrindinio_failo_nuskaitymas(Eil, studentu_kiekis);
	nuskriaustukai_ir_galvotukai(Eil, galvotukai, nuskriaustukai);
	//---------------------------------------------------------------------------------------------------------------------------
	ofstream iNuskriaustukai;
	iNuskriaustukai.open(to_string(studentu_kiekis) + "Nuskriaustuku_Failas.txt", ios::app);
	failu_spausdinimas(iNuskriaustukai, nuskriaustukai);
	iNuskriaustukai.close();
	//---------------------------------------------------------------------------------------------------------------------------
	std::ofstream iGalvotukai;
	iGalvotukai.open(to_string(studentu_kiekis) + "Galvotuku_Failas.txt", std::ios::app);
	failu_spausdinimas(iGalvotukai, galvotukai);
	iGalvotukai.close();
	//---------------------------------------------------------------------------------------------------------------------------
	cout << "------------------------------------------------------------------------------------------------" << endl;
	return 0;
}
//---------------------------------------------------------------------------------------------------------------------------
