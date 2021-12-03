#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <random>
//---------------------------------------------------------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------------------------------------------------------
class Studentas
{
private:
    std::string Vard;
    std::string Pav;
    std::vector<int> Pazymiai;
    int Egz;
public:
    Studentas() : Pazymiai(0) { };
    void setStudentas(std::string, std::string, std::string);
    void setPazymiai(int);
    void tustiPazymiai();
    std::string getName() const { return Vard; }
    std::string getSurname() const { return Pav; }
    int getEgz() const { return Egz; }
    int getDydis() const { return Pazymiai.size(); }
    double GALPAZ(int, double);
    double GALPAZ(int, const std::vector<int>);
    double GALPAZ(double (*) (std::vector<int>));

    ~Studentas()
        = default; //destruktor

    Studentas(const Studentas & name) //copy constructor
    {
        Vard = name.Vard;
        Pav = name.Pav;
        Pazymiai = name.Pazymiai;
        Egz = name.Egz;
    }

    Studentas& operator = (const Studentas & name)//copy assignment operator
    {
        Vard = name.Vard;
        return*this;
        Pav = name.Pav;
        return*this;
        Egz = name.Egz;
        return*this;

    }
};
//---------------------------------------------------------------------------------------------------------------------------
void pagrindinio_failo_kurimas(int studentu_kiekis);
void pagrindinio_failo_nuskaitymas(vector<Studentas>& Eil, int studentu_kiekis);
void nuskriaustukai_ir_galvotukai(vector<Studentas>& Eil, vector<Studentas>& galvotukai, vector<Studentas>& nuskriaustukai);
void failu_spausdinimas(ostream& out, vector<Studentas> Eil);
double vidurkio_skaiciavimas(std::vector<int> mokinio_pazymiai);
//---------------------------------------------------------------------------------------------------------------------------
