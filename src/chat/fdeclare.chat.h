//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.consts.h"
//silver_chain_scope_end


#define REG_CHAT_RESPONSE_ERROR_ALOCATED -3
#define REG_CHAT_RESPONSE_INVALID_READ -2
#define REG_CHAT_RESPONSE_BUFFER_BURST -1

#define REG_CHAT_RESPONSE_BUFFER_OK 0
#define REG_CHAT_RESPONSE_EXIT_COMMAND 1
#define REG_CHAT_RESPONSE_CLEAR_COMMAND 2

#define REG_CHAT_RESPONSE_GENERIC_ERROR "Unexpected internal error."
#define REG_CHAT_RESPONSE_BUFFER_BURST_MESSAGE "Input text is too large."
#define REG_CHAT_RESPONSE_INVALID_READ_MESSAGE "The input text contains invalid characters."
#define REG_CHAT_RESPONSE_ERROR_ALOCATED_MESSAGE "Error internal in allocated buffer temp."
#define REG_CHAT_RESPONSE_CLEAR_COMMAND_MESSAGE "The screen has been cleared."

short Reg_init_chat(char *buffer, size_t size_max_buffer, const char *initial_caracter);

const char *Reg_chat_returned_handling(short response_chat);


