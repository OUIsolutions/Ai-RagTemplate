//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


char * collect_user_input(){
  char *buffer = (char*)malloc(100);
  int buffer_size = 100;
  int i = 0;
  while(true){

    char c = getchar();
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
    
    ModelProps *props =collect_model_props();
    if(!props){
        return 1;
    }
    OpenAiInterface *openAi = openai.openai_interface.newOpenAiInterface(props->url, props->key, props->model);
    
    
    Asset * main_system_rules = get_asset("system_instructions.json");
    if(!main_system_rules){
      printf("%sError: %s%s\n", RED, "No system instructions found", RESET);
      return 1;
    }
    cJSON *rules = cJSON_Parse((char*)main_system_rules->data);
    if(!rules){
      printf("%sError: %s%s\n", RED, "No system instructions found", RESET);
      return 1;
    }
    int size = cJSON_GetArraySize(rules);

    for(int i = 0; i <size;i++){
      cJSON *current_rule = cJSON_GetArrayItem(rules,i);
      openai.openai_interface.add_system_prompt(openAi,cJSON_GetStringValue(current_rule));
    }
    
    configure_read_asset_callbacks(openAi,props->model);
    configure_list_recursively_callbacks(openAi,props->model);
    configure_read_file_callbacks(openAi,props->model);
    configure_write_file_callbacks(openAi, props->model);
    configure_execute_command_callbacks(openAi,props->model);
    configure_remove_file_callbacks(openAi,props->model);

    configure_terminate_callbacks(openAi,props->model);

    while (true){
        printf("%s > %s:%s", GREEN, props->model,PURPLE);
        char *message = collect_user_input();

        if(strcmp(message,"exit") == 0){
          break;
        }
        if(strcmp(message,"clear") == 0){
          #ifdef _WIN32
            system("cls");
          #else
            system("clear");
          #endif
          continue;
        }
        openai.openai_interface.add_user_prompt(openAi, message);

        OpenAiResponse *response =  OpenAiInterface_make_question_finish_reason_treated(openAi);
        if(openai.openai_interface.error(response)){
          printf("%sError: %s%s\n", RED, openai.openai_interface.get_error_message(response), RESET);
          break;
        }
        const char *first_answer = openai.response.get_content_str(response,0);
        if(first_answer == NULL){
          printf("%sError: %s%s\n", RED, "No answer found", RESET);
          free(message);
          break;
        }
        printf("%s < %s: %s%s\n", BLUE,props->model, first_answer, RESET);
        openai.openai_interface.add_response_to_history(openAi, response,0);
        free(message);
    }  

    cJSON_Delete(rules);
    openai.openai_interface.free(openAi);
    freeModelProps(props);

    return 0;
}