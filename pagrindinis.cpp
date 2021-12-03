#include "headeris.h"
//---------------------------------------------------------------------------------------------------------------------------
void pagrindinio_failo_kurimas(int studentu_kiekis)
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine eng(seed);
	std::uniform_int_distribution <int> Interval(1, 10), Amount(10, 20);

	int studentu_skaicius = studentu_kiekis,
		rezultatu_skaicius = Amount(eng);

	std::ofstream Write;
	Write.open("Studentai_" + std::to_string(studentu_skaicius) + ".txt");

	for (size_t j = 1; j <= studentu_skaicius; j++)
	{
		Write << "Vardas" + std::to_string(j) << " Pavarde" + std::to_string(j) << " " << Interval(eng);

		std::vector <int> Results;
		std::vector <int>::iterator iteratorius;

		for (size_t k = 0; k < rezultatu_skaicius; k++)
			Results.push_back(Interval(eng));

		for (iteratorius= Results.begin(); iteratorius< Results.end(); iteratorius++)
			Write << " " << *iteratorius;

		Write << std::endl;
	}
	Write.close();
}
//---------------------------------------------------------------------------------------------------------------------------
void pagrindinio_failo_nuskaitymas(vector<Studentas>& grupe, int studentu_kiekis)
{
	auto start = chrono::high_resolution_clock::now();      //STARTAS
	std::string vard,
		pav,
		egz,
		eilute;
	Studentas Stud;
	string ivestis;

	std::ifstream skaityti_faila("Studentai_" + std::to_string(studentu_kiekis) + ".txt");

	while (std::getline(skaityti_faila, eilute))
	{
		istringstream skaityti_eilute(eilute);
		skaityti_eilute >> vard >> pav >> egz;

		Stud.setStudentas(vard, pav, egz);

		if (skaityti_eilute)
		{
			Stud.tustiPazymiai();
			while (skaityti_eilute >> ivestis)
			{
				int pazymys = stoi(ivestis);
				if (pazymys > 0 && pazymys < 11)
					Stud.setPazymiai(pazymys);
			}
			grupe.push_back(Stud);
			skaityti_eilute.clear();
		}
		skaityti_eilute.end;
		skaityti_faila.clear();
	}
	skaityti_faila.end;
	auto end = chrono::high_resolution_clock::now();         //PABAIGA
	chrono::duration<double> skirtumas = end - start;
	cout << "Failo nuskaitymas kuriame yra " << studentu_kiekis << " studentu is viso uztruko: " << skirtumas.count() << endl;
}
//---------------------------------------------------------------------------------------------------------------------------
void nuskriaustukai_ir_galvotukai(vector<Studentas>& Eil, vector<Studentas>& galvotukai, vector<Studentas>& nuskriaustukai)
{
	auto start = chrono::high_resolution_clock::now();

	std::vector<Studentas>::iterator iteratorius= Eil.begin();

	while (iteratorius!= Eil.end())
	{
		if ((*iteratorius).GALPAZ(vidurkio_skaiciavimas) < 5)
			nuskriaustukai.push_back(*iteratorius);
		else
			galvotukai.push_back(*iteratorius);
		iteratorius++;
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> skirtumas = end - start;
	cout << "Failo rusiavimas i nuskriaustukus ir galvotukus kuriame yra " << Eil.size() << " studentu is viso uztruko: " << skirtumas.count() << endl;
}
//---------------------------------------------------------------------------------------------------------------------------
void failu_spausdinimas(ostream& out, vector<Studentas> Eil)
{
	for (std::vector<Studentas>::iterator iteratorius= Eil.begin(); iteratorius!= Eil.end(); iteratorius++)
	{
		out << (*iteratorius).getName() << string(25, ' ');
		out << (*iteratorius).getSurname() << string(25, ' ');
		streamsize prec = cout.precision();
		out << std::fixed << std::setprecision(2) << (*iteratorius).GALPAZ(vidurkio_skaiciavimas) << " " << setprecision(prec) << endl;
	}
	out << std::endl;
}
//---------------------------------------------------------------------------------------------------------------------------
void Studentas::setStudentas(std::string vard, std::string pav, std::string egz)
{
	Vard = vard;
	Pav = pav;
	Egz = std::stoi(egz);
}
//---------------------------------------------------------------------------------------------------------------------------
void Studentas::setPazymiai(int rezultatas)
{
	Pazymiai.push_back(rezultatas);
}
//---------------------------------------------------------------------------------------------------------------------------
void Studentas::tustiPazymiai()
{
	Pazymiai.clear();
}
//---------------------------------------------------------------------------------------------------------------------------
double Studentas::GALPAZ(int Egz, double mokinio_pazymiai)
{
	return 0.4 * mokinio_pazymiai + 0.6 * Egz;
}
//---------------------------------------------------------------------------------------------------------------------------
double Studentas::GALPAZ(int Egz , const std::vector<int> studento_pazymiai)
{
	if (Pazymiai.size() == 0)
		throw std::domain_error("Studentas neatliko nei vieno namu darbo.");
	return GALPAZ(Egz, vidurkio_skaiciavimas(Pazymiai));
}
//---------------------------------------------------------------------------------------------------------------------------
double Studentas::GALPAZ(double (*Criteria)(std::vector<int>))
{
	return GALPAZ(Egz, Criteria(Pazymiai));
}
//---------------------------------------------------------------------------------------------------------------------------
double vidurkio_skaiciavimas(std::vector<int> mokinio_pazymiai)
{
	return std::accumulate(mokinio_pazymiai.begin(), mokinio_pazymiai.end(), 0.0) / mokinio_pazymiai.size();
}
//---------------------------------------------------------------------------------------------------------------------------
