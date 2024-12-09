std::string intToString(int num) {
  if (num == 0) {
    return "0";
  }
  bool isNegative = num < 0;
  if (isNegative) {
    num = -num; // Rendre le nombre positif pour faciliter la conversion
  }
  std::string result = "";
  while (num > 0) {
    char digit = (num % 10) + '0'; // Convertir le chiffre en caractère
    result = digit + result; // Ajouter le chiffre à la chaîne (en tête)
    num /= 10; // Diviser le nombre par 10 pour extraire le chiffre suivant
  }
  if (isNegative) {
    result = '-' + result;
  }
  return result
}
