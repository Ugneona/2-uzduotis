#include "Patikrinimas.h"
/// Patikrinimas.
/// 
/// tikrina ar gautas kintamasis yra zodis, t. y. visi kintamojo simboliai yra ne skaiciai
/// @param str gautas zodis/kintamasis
/// @return true, jei gautas kintamsis zodis, false, jei nera zodis, turi simboli skaitmeni
bool check_string(string& str)
{
    int sum = 0;

    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false) sum += 1;

    if (sum == str.length()) return true;
    else return false;
}
/// Patikrinimas
/// 
/// tikrina ar gauta raide yra is galimu raidziu saraso, t. y. ar raide yra t/T ar n/N
/// @param chr raide
/// @return true, jei gauta raide yra is galimu raidziu saraso, false, jei ne
bool check_alpha(char& chr)
{
    if (chr == 't' || chr == 'T' || chr == 'n' || chr == 'N') return true;
    else return false;
}
/// Patikrina ar gauta raide yra v/V, m/M ar A/a
/// 
/// v/V - vidurkis, m/M - mediana, A/a - vidurkis ir mediana
/// @param chr raide
/// @return true, jei gauta raide yra is galimu raidziu saraso, false, jei ne
bool check_vma(char& chr)
{
    if (chr == 'v' || chr == 'V' || chr == 'm' || chr == 'M' || chr == 'A' || chr == 'a') return true;
    else return false;

}