#include "transformations.h"
#include <cmath>

std::string Transformations::intToString(float num) {
  if (num == 0.0f) {
    return "0";
  }
  
  bool isNegative = num < 0;
  if (isNegative) {
    num = -num;
  }
  
  int integerPart = static_cast<int>(num);
  std::string result = "";

  while (integerPart > 0) {
    char digit = (integerPart % 10) + '0'; // Convertir le chiffre en caractère
    result = digit + result; // Ajouter le chiffre à la chaîne (en tête)
    integerPart /= 10; // Diviser le nombre entier par 10 pour extraire le chiffre suivant
  }
  if (isNegative) {
    result = '-' + result;
  }
  
  float decimalPart = num - static_cast<int>(num);
  if (decimalPart > 0.0f) {
    result += '.'; // Ajouter le séparateur décimal
    for (int i = 0; i < precision; ++i) {
      decimalPart *= 10;  // Déplacer la décimale d'un chiffre
      int digit = static_cast<int>(decimalPart); // Extraire le chiffre
      result += (digit + '0');  // Convertir le chiffre en caractère et l'ajouter à la chaîne
      decimalPart -= digit;  // Enlever la partie entière (garder les décimales)
    }
  }

  return result;
}
