// checkid.h
// Author: mmdjiji(JiJi)
// GitHub: https://mmdjiji.com/mmdjiji/idog
// GPLv3 License

#ifndef _CHECKID_H_
#define _CHECKID_H_

#include <stdio.h>
#include <string.h>

const int TheEarlyYear = 1900; // If birthday before the early year, we think it's fake.

bool CheckCitycode(const char* city);
bool CheckBorndate(char* sPaperId);
bool CheckId(char *sPaperId);

int TryIt(char *todo, int now, int sex);
int TryId(char *str);

#endif
