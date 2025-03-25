//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end



void colect_user_imput(char *input,int max_size){
  for(int i = 0; i < max_size; i++){
    char c = getchar();
    if(c == '\n'){
      input[i] = '\0';
      break;
    }
    input[i] = c;
  }
}



int start_action(){
    
    ModelProps *props =collect_model_props();
    if(!props){
        return 1;
    }
    OpenAiInterface *openAi = openai.openai_interface.newOpenAiInterface(props->url, props->key, props->model);
    
    
    Asset * main_system_rules = get_asset("system_instructions.json");
    cJSON *rules = cJSON_Parse(main_system_rules->data);
    int size = cJSON_GetArraySize(rules);

    for(int i = 0; i <size;i++){
      cJSON *current_rule = cJSON_GetArrayItem(rules,i);
      openai.openai_interface.add_system_prompt(openAi,cJSON_GetStringValue(current_rule));
    }
    
    //configure_read_asset_callbacks(openAi);
    configure_list_recursively_callbacks(openAi);
    configure_read_file_callbacks(openAi);
    configure_write_file_callbacks(openAi);


    size_t size_buffer = REG_BUFFER_SIZE - 1;
    char *buffer = BearsslHttps_allocate(REG_BUFFER_SIZE);
    short response_buffer_input = REG_CHAT_RESPONSE_BUFFER_OK;

    while (true){

        response_buffer_input = Reg_init_chat(buffer, size_buffer, " Your message > ");
        if(response_buffer_input != REG_CHAT_RESPONSE_BUFFER_OK){
            const char *message = Reg_chat_returned_handling(response_buffer_input);
            if(message){
                printf("\n\tErro:. %s\n", message);
            }
            break;
        }

        openai.openai_interface.add_user_prompt(openAi, buffer);

        OpenAiResponse *response =  OpenAiInterface_make_question_finish_reason_treated(openAi);
        if(openai.openai_interface.error(response)){
          printf("%sError: %s%s\n", RED, openai.openai_interface.get_error_message(response), RESET);
          break;
        }
        const char *first_answer = openai.response.get_content_str(response,0);
        if(first_answer == NULL){
          printf("%sError: %s%s\n", RED, "No answer found", RESET);
          break;
        }
        printf("%s < Response: %s%s\n", GREEN, first_answer, RESET);
        openai.openai_interface.add_response_to_history(openAi, response,0);

    }  
    cJSON_Delete(rules);

    //printf("data collected: %s\n", cJSON_Print(openAi->messages));
    openai.openai_interface.free(openAi);
    freeModelProps(props);

    return 0;
}
