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

    while (true){
        printf("%sEnter your message:%s\n", GREEN, RESET);
        char input[1000] ={0};
        colect_user_imput(input,sizeof(input)-1);
        if(strcmp(input,"exit") == 0){
        break;
        }     

      openai.openai_interface.add_user_prompt(openAi, input);

      OpenAiResponse *response = openai.openai_interface.make_question(openAi);
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
  
    }

    openai.openai_interface.free(openAi);
    freeModelProps(props);

    return 0;
}