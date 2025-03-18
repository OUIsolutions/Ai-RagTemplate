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

int main(int argc, char  *argv[]){
    start_namespace();
    args_obj  = args.newCArgvParse(argc, argv);
    
    const char *action = args.get_arg(&args_obj, 1);

    if(action == NULL){
      printf("%sError: %s%s\n", RED, "No action provided", RESET);
      return 1;
    }
    if(strcmp(action, START) == 0){
      return start_action();
   }
    if(strcmp(action, CONFIG_MODEL) == 0){
      return configure_model();
    }
    

    
    if(strcmp(action, HELP) == 0 || args.is_flags_present(&args_obj, help_flags, help_size)){
      Asset * help = get_asset("help.txt");

      printf("%s%s%s\n", BLUE,(char*)help->data, RESET);
      return 0;
    }
    printf("%sError: %s%s\n", RED, "Invalid action", RESET);
    return 1;

}