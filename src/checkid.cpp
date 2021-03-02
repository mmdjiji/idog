// checkid.cpp
// Author: mmdjiji(JiJi)
// GitHub: https://github.com/mmdjiji/idog
// GPLv3.0 License

#include "checkid.h"

bool CheckCitycode(const char* city) {
  const char* Citycode[35] = {"11", "12", "13", "14", "15", "21", "22", "23", "31", "32", "33", "34", "35", "36", "37", "41", "42", "43", "44", "45", "46", "50", "51", "52", "53", "54", "61", "62", "63", "64", "65", "71", "81", "82", "91"};
  for(int i=0; i<35; i++) {
    if(memcmp(Citycode[i], city, 2) == 0) {
      return true;
    }
  }
  return false;
}

bool CheckBorndate(char* sPaperId) {
  unsigned char Month_buf[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year = (sPaperId[6]-'0')*1000 + (sPaperId[7]-'0')*100 + (sPaperId[8]-'0')*10 + (sPaperId[9]-'0');
  int month = (sPaperId[10]-'0')*10 + (sPaperId[11]-'0');
  int day = (sPaperId[12]-'0')*10 + (sPaperId[13]-'0');
  if(month==2 && year%4==0 && year%100!=0 || year%400==0) {
    Month_buf[1]++;
  }
  if (month>12 || month<1 || day > Month_buf[month-1] || day<1 || year < TheEarlyYear) {
    return false;
  }
  return true;
}

bool CheckId(char *sPaperId) {
  if(strlen(sPaperId) != 18) {
    return false;
  }
  for (int i=0; i<18; i++) {
    if (!(sPaperId[i] >= '0' && sPaperId[i] <= '9') && !((sPaperId[i] == 'X' || sPaperId[i] == 'x') && i == 17)) {
      return false;
    }
  }
  if(!CheckCitycode(sPaperId) || !CheckBorndate(sPaperId)) {
    return false;
  }
  int lSumQT =0;
  const char rCode[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  const char sChecker[11]= {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
  for (int i=0; i<=16; i++) {
    lSumQT += (sPaperId[i]-48) * rCode[i];
  }
  if (sChecker[lSumQT%11] != sPaperId[17]) {
    return false;
  }
  return true;
}
