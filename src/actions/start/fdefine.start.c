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

//ai can read the assets too
char *get_ai_chosen_asset(cJSON *args, void *pointer){

  cJSON *asset = cJSON_GetObjectItem(args, "doc");
  if(!cJSON_IsString(asset)){
        return NULL;
  }

  Asset *current_aset = get_asset(asset->valuestring);

  if(!current_aset){
    return NULL;
  }

  return (char*)current_aset->data;
}
void configure_read_asset_callbacks(OpenAiInterface *openAi){
    cJSON *assets_json = cJSON_CreateArray();
    DtwStringArray *all_assets = list_assets_recursively(NULL);
    for(int i = 0; i < all_assets->size; i++){
        cJSON_AddItemToArray(assets_json, cJSON_CreateString(all_assets->strings[i]));
    }
    char *assets_printed = cJSON_PrintUnformatted(assets_json);
    char *message = malloc(strlen(assets_printed) + 100);
    sprintf(message, "The following docs are available: %s", assets_printed);
    
    openai.openai_interface.add_system_prompt(openAi,message);
    OpenAiCallback *callback = new_OpenAiCallback(get_ai_chosen_asset, NULL, "get_doc", "get a  do to help users in question", false);
    OpenAiInterface_add_parameters_in_callback(callback, "doc", "Pass the name of doc you want to read.", "string", true);
    OpenAiInterface_add_callback_function_by_tools(openAi, callback);


    dtw.string_array.free(all_assets);
    free(assets_printed);
    cJSON_Delete(assets_json);
}


int start_action(){
    
    ModelProps *props =collect_model_props();
    if(!props){
        return 1;
    }
    OpenAiInterface *openAi = openai.openai_interface.newOpenAiInterface(props->url, props->key, props->model);
    
    
    Asset * main_system_rules = get_asset("system_instructions.md");
    openai.openai_interface.add_system_prompt(openAi,(char*)main_system_rules->data);
    configure_read_asset_callbacks(openAi);


    while (true){
        printf("%sEnter your message:%s\n", GREEN, RESET);
        char input[1000] ={0};
        colect_user_imput(input,sizeof(input)-1);
        if(strcmp(input,"exit") == 0){
            break;
        }     

        openai.openai_interface.add_user_prompt(openAi, input);

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
        printf("%sAnswer: %s%s\n", BLUE, first_answer, RESET);
        openai.openai_interface.add_response_to_history(openAi, response,0);

       char *messages = cJSON_Print(openAi->messages);
        long agora = time(NULL);
        char caminho[100] ={0};
        sprintf(caminho,"history/%ld.json",agora);
        dtw.write_string_file_content(caminho, messages);
        free(messages);

    }  



    openai.openai_interface.free(openAi);
    freeModelProps(props);

    return 0;
}