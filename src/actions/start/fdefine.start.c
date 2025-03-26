//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end

char * colect_user_imput(){
  char *buffer = (char*)malloc(1000);
  int i = 0;
  bool escape_next = false;
  while(true){
    char c = getchar();
    if(escape_next && c == '\n'){
      buffer[i++] = c;
      escape_next = false;
      continue;
    }
    if(c == '\\'){
      escape_next = true;
      continue;
    }
    if(c == '\n'){
      buffer[i] = '\0';
      break;
    }
    buffer[i] = c;
    i++;
  }
  return buffer;
}

int start_action(){
    // ... rest of the function remains unchanged
}