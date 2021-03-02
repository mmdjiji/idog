// tryid.cpp
// Author: mmdjiji(JiJi)
// GitHub: https://mmdjiji.com/mmdjiji/idog
// GPLv3 License

#include "checkid.h"

int TryIt(char *todo, int now, int sex) {
  static int count = 0;
  if(now == 18) {
    if(sex == 0) {
      if(CheckId(todo)) {
        count++;
        printf("%s\n",todo);
      }
    }else if((todo[16]-'0')%2 == sex%2 && CheckId(todo)) {
      count++;
      printf("%s\n",todo);
    }
  }else{
    if(todo[now] == '*'){
      for(int i=0;i<=9;i++){
        todo[now] = i + '0';
        TryIt(todo, now+1, sex);
        todo[now] = '*';
      }
      if(now == 17){
        todo[now] = 'X';
        TryIt(todo, 18, sex);
        todo[now] = '*';
      }
    }else{
      TryIt(todo, now+1, sex);
    }
  }
  return count;
}

int TryId(char *str) {
  int sex = -1;
  if(strlen(str) == 18) {
    if(str[16] == '*') { // unknown
      sex = 0;
    } else if(str[16] == 'o') { // male, odd
      sex = 1;
      str[16] = '*';
    } else if(str[16] == 'e') { // female, even
      sex = 2;
      str[16] = '*'; 
    } else if(str[16] >= '0' && str[16] <= '9') {
      if((str[16]-'0') % 2 == 0) {
        sex = 2;
      } else {
        sex = 1;
      }
    } else {
      return (-1);
    }
    return TryIt(str, 0, sex);
  }
  return (-1);
}
