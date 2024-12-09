#include "transformations.h"
#include <cmath>

const char* Transformations::floatToString(float num) {
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
    char digit = (integerPart % 10) + '0';
    result = digit + result;
    integerPart /= 10;
  }
  if (isNegative) {
    result = '-' + result;
  }
  
  float decimalPart = num - static_cast<int>(num);
  if (decimalPart > 0.0f) {
    result += '.';
    for (int i = 0; i < 5; ++i) {
      decimalPart *= 10;
      int digit = static_cast<int>(decimalPart);
      result += (digit + '0');
      decimalPart -= digit;
    }
  }
  char* cstr = new char[result.length() + 1];
  for (size_t i = 0; i < result.length(); ++i) {
    cstr[i] = result[i];
  }
  cstr[result.length()] = '\0';

  return cstr;
}
