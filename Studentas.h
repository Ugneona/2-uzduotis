#pragma once
#ifndef STUDENTAS_H
#define STUDENTAS_H


#include "Antraste.h"
#include "Uzklausos.h"
/// class Zmogus talpina informacija
/// 
/// Apie zmogaus varda ir pavarde
class Zmogus
{
protected:
    string vardas_, pavarde_;
public:
    /// Konstruktorius
    /// 
    /// </summary>
    Zmogus() {};
    ///Destruktorius
    ///
    /// 
    ~Zmogus() {};
    virtual string GautiVarda() const = 0;
    virtual string GautiPavarde() const = 0;

};
/// class Studentas yra isvestine klase
/// 
/// Joje yra tokie studento duomenys: nd pazymiai, egzamino pazymys ir galutiniai ivertinimai pagal vidurki ir mediana
class Studentas : public Zmogus
{
private:
    vector <double> nd_;
    double egz_;
    double galutinis_vidurkis;
    double galutinis_mediana;
public:
    /// Konstruktorius
    /// 
    /// </summary>
    Studentas() : egz_(0), galutinis_vidurkis(0), galutinis_mediana(0) {};
    /// Destruktorius
    ///
    /// 
    ~Studentas() { nd_.clear(); };
    /// Kopijavimo konstruktorius
    /// 
    /// </summary>
    /// @param s studentas
    Studentas(const Studentas& s)
    {
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        egz_ = s.egz_;
        nd_ = s.nd_;
        galutinis_mediana = s.galutinis_mediana;
        galutinis_vidurkis = s.galutinis_vidurkis;
    }
    /// Priskirimo operatorius
    /// 
    /// </summary>
    /// @param s Studentas
    /// @return nuoroda i studenta
    Studentas& operator= (const Studentas& s)
    {
        if (&s == this) return *this;
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        egz_ = s.egz_;
        nd_ = s.nd_;
        galutinis_mediana = s.galutinis_mediana;
        galutinis_vidurkis = s.galutinis_vidurkis;
        return *this;
    }
    /// Komanda suzinoti apie studenta
    /// 
    /// </summary>
    /// @return studento varda
    inline std::string GautiVarda() const { return vardas_; }
    /// Komanda suzinoti apie studenta
    /// 
    /// </summary>
    /// @return studento pavarde
    inline std::string GautiPavarde() const { return pavarde_; }
    /// Komanda suzinoti apie studenta
    /// 
    /// </summary>
    /// @return studento egzamino pazymi
    inline double GautiEgzamina() const { return egz_; }
    /// Komanda suzinoti apie studenta
    /// 
    /// </summary>
    /// @return kiek studentas turi pazymiu is namu darbu
    inline int GautiNdDydi() const { return nd_.size(); }
    /// Komanda suzinoti apie studenta
    /// 
    /// </summary>
    /// @param i namu darbu numeris
    /// @return namu darbu pazymi
    inline double GautiElementa(int i) const { return nd_.at(i); }
    /// Papildo studento duomenis
    /// 
    /// Priskiria varda ir pavarde
    /// @param vardas
    /// @param pavarde
    void SetVardasPavarde(string vardas, string pavarde)
    {
        vardas_ = vardas;
        pavarde_ = pavarde;
    }
    /// Papildo studento duomenis
    /// 
    /// Priskiria egzamina
    /// @param egzaminas
    void SetEgzaminas(double egzaminas)
    {
        egz_ = egzaminas;
    }
    /// Papildo studento duomenis
    /// 
    /// Nustato, kiek bus pazymiu is nd
    /// @param ndKiek namu darbu skaicius
    void NdReserve(int ndKiek)
    {
        nd_.reserve(ndKiek);
    }
    /// Papildo studento duomenis
    /// 
    /// Iraso namu darbu pazymi
    /// @param pazymys is namu darbu
    void NdIdeti(double pazymys)
    {
        nd_.push_back(pazymys);
    }
    /// Istrina namu darbu pazymius
    /// 
    /// </summary>
    void NdIsvalymas()
    {
        nd_.clear();
    }
    /// Papildo studento duomenis
    /// 
    /// Apskaiciuoja galutini pazymi su mediana
    void SetGalutinisMediana()
    {
        sort(nd_.begin(), nd_.end());

        int ndKiek1 = nd_.size();
        double mediana = ndKiek1 % 2 == 0 ? (nd_[(ndKiek1 / 2) - 1] + nd_[ndKiek1 / 2]) / 2.0 : nd_[ndKiek1 / 2];

        galutinis_mediana = 0.4 * mediana + 0.6 * egz_;
    }
    /// Komanda suzinoti apie studenta
    /// 
    /// </summary>
    /// @return grazina galutini pazymi, apskaiciuota su mediana
    inline double GetGalutinisMediana() const { return galutinis_mediana; }
    /// Papildo studento duomenis
    /// 
    /// Apskaiciuoja galutini pazymi su vidurkiu
    void SetGalutinisVidurkis()
    {
        double sum = 0.;
        double kiekis = 0.;
        double vid = 0.;

        for (int i = 0; i < nd_.size(); i++)
        {
            sum += nd_.at(i);
            kiekis++;
        }

        vid = sum / kiekis;

        galutinis_vidurkis = 0.4 * vid + 0.6 * egz_;
    }
    /// Komanda suzinoti apie studenta
    /// 
    /// </summary>
    ///  @return grazina galutini pazymi, apskaiciuota su vidurkiu
    inline double GetGalutinisVidurkis() const { return galutinis_vidurkis; }

};
void failoNuskaitymas(vector <Studentas>& grupe1, int& v1);
void rusiavimas(vector <Studentas>& grupe1, vector <Studentas>& protingi, vector <Studentas>& tinginiai, vector <double>& laikas, char& atsakymas);
void spausdinimas(int& v1, char& atsakymas, vector <Studentas>& sarasas, vector <double>& laikas, string& pav);
void spausdinimas(char& atsakymas, vector <Studentas>& grupe1);
void spausdinti_vector_nr2(char& atsakymas, vector <Studentas>& grupe1);
void rusiavimas_strategija_nr2(vector <Studentas>& grupe_vector, vector <Studentas>& tinginiai_vector, vector <double>& laikas_vector, char& atsakymas);
void studentoUzpildymasVardPavardNdEgz(int& studentuSkaicius, vector <Studentas>& grupe);
void studentoUzpildymasRnd(int& studentuSkaicius, vector <Studentas>& grupe);
bool rusiuotiMediana(Studentas& a, Studentas& b);
bool rusiuotiVidurki(Studentas& a, Studentas& b);

#endif