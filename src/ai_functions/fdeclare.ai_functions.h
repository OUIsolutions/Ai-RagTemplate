

char *get_ai_chosen_asset(cJSON *args, void *pointer);

void configure_read_asset_callbacks(OpenAiInterface *openAi);


char *agent_list_recursively(cJSON *args, void *pointer);

void configure_list_recursively_callbacks(OpenAiInterface *openAi);


/*

char *agent_list(cJSON *args, void *pointer);

void configure_list_callbacks(OpenAiInterface *openAi);

*/
char *agent_read_file(cJSON *args, void *pointer);

void configure_read_file_callbacks(OpenAiInterface *openAi);


char *agent_write_file(cJSON *args, void *pointer);

void configure_write_file_callbacks(OpenAiInterface *openAi);