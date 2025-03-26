//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
//silver_chain_scope_end


short Reg_init_chat(char *buffer, size_t size_max_buffer, const char *initial_caracter){

  memset(buffer, 0, size_max_buffer);
  long size_buffer_temp = size_max_buffer + 1;
  char *buffer_temp = (char*)malloc(size_buffer_temp);
  if(!buffer_temp){
    return REG_CHAT_RESPONSE_ERROR_ALOCATED;
  }
  long size_max = size_max_buffer - 1;
  long size_buffer = 0;

  while(size_max > 0){
    memset(buffer_temp, 0, size_max_buffer + 1);
    if(initial_caracter){
      printf("%s%s%s", BLUE, initial_caracter, RESET);
    }

    if (fgets(buffer_temp, size_max, stdin) != NULL) {
      long temp_size = strlen(buffer_temp);

      if (temp_size > size_max) {
        return REG_CHAT_RESPONSE_BUFFER_BURST;
      }

      long now_temp_size = temp_size - 2;
      if(strcmp(buffer_temp + now_temp_size, "\
") == 0){ 
        memcpy(buffer + size_buffer, buffer_temp, now_temp_size);
        size_max -= now_temp_size;
        size_buffer += now_temp_size + 1;
        buffer[size_buffer - 1] = '\n';
        continue;
      }

      memcpy(buffer + size_buffer, buffer_temp, temp_size - 1);
      size_max -= temp_size;
      size_buffer += temp_size;
      buffer[size_buffer - 1] = '\0';
      break;
    }

    return REG_CHAT_RESPONSE_INVALID_READ;
  }

  if(size_max <= 0){
    return REG_CHAT_RESPONSE_BUFFER_BURST;
  }

  if(strcmp(buffer, "exit") == 0){
    return REG_CHAT_RESPONSE_EXIT_COMMAND;
  }
  if(strcmp(buffer, "clear") == 0){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    return REG_CHAT_RESPONSE_CLEAR_COMMAND;
  }

  return REG_CHAT_RESPONSE_BUFFER_OK;
}

const char *Reg_chat_returned_handling(short response_chat){
  if(!(response_chat < 0)){
    return NULL;
  }
  if(response_chat == REG_CHAT_RESPONSE_BUFFER_BURST){
    return REG_CHAT_RESPONSE_BUFFER_BURST_MESSAGE;
  }
  if(response_chat == REG_CHAT_RESPONSE_INVALID_READ){
    return REG_CHAT_RESPONSE_INVALID_READ_MESSAGE;
  }
  if(response_chat == REG_CHAT_RESPONSE_ERROR_ALOCATED){
    return REG_CHAT_RESPONSE_ERROR_ALOCATED_MESSAGE;
  }
  if(response_chat == REG_CHAT_RESPONSE_CLEAR_COMMAND){
    return REG_CHAT_RESPONSE_CLEAR_COMMAND_MESSAGE;
  }
  return REG_CHAT_RESPONSE_GENERIC_ERROR;
}