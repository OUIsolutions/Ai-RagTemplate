//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "imports/imports.fdefine.h"
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

int main(int argc, char const *argv[]){
    start_namespace();
    args_obj  = args.newCArgvParse(argc, argv);


    /*

    OpenAiInterface *openAi = openai.openai_interface.newOpenAiInterface(URL, KEY, MODEL);

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
      const char *first_answer = openai.response.get_content_str(response,FIRST_CHOICE);
      printf("%sAnswer: %s%s\n", BLUE, first_answer, RESET);
      openai.openai_interface.add_response_to_history(openAi, response,FIRST_CHOICE);
  
    }
    openai.openai_interface.free(openAi);
    */
}