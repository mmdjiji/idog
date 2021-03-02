// main.cpp
// Author: mmdjiji(JiJi)
// GitHub: https://mmdjiji.com/mmdjiji/idog
// GPLv3 License

#include <stdio.h>
#include <string.h>

#include "checkid.h"

enum MODE { TEST, CRACK };

int main(int argc, char *argv[]) {
  char in[30];
  if(argc == 1) {
    scanf("%s", in);
  } else {
    strncpy(in, argv[1], 20);
  }
  MODE mode = TEST;
  for(int i=0; i<18; i++) {
    if(in[i] == '*') {
      mode = CRACK;
      break;
    }
  }
  if(mode == TEST) {
    if(CheckId(in)) {
      printf("[Result] %s is legal.\n", in);
    } else {
      printf("[Result] %s is illegal.\n", in);
    }
  } else {
    if(strlen(in) == 18) {
      printf("[Result]\n");
      int retCount = TryId(in);
      printf("All %d possibles.\n", retCount);
    } else {
      printf("[Result] Invalid input.\n");
    }
  }
  return 0;
}
