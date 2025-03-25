//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.consts.h"
//silver_chain_scope_end


char *get_ai_chosen_asset(cJSON *args, void *pointer);

void configure_read_asset_callbacks(OpenAiInterface *openAi);


char *agent_list_recursively(cJSON *args, void *pointer);

void configure_list_recursively_callbacks(OpenAiInterface *openAi);


void configure_execute_command_callbacks(OpenAiInterface *openAi);

char *agent_read_file(cJSON *args, void *pointer);

void configure_read_file_callbacks(OpenAiInterface *openAi);


char *agent_write_file(cJSON *args, void *pointer);


void configure_write_file_callbacks(OpenAiInterface *openAi);

char *agent_remove_file(cJSON *args, void *pointer);

void configure_remove_file_callbacks(OpenAiInterface *openAi);