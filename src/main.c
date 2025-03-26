//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "imports/imports.fdefine.h"
//silver_chain_scope_end



int main(int argc, char  *argv[]){
    start_namespace();
    args_obj  = args.newCArgvParse(argc, argv);
    int result = -1;
    
    unsigned char *encryption_key = (unsigned char*)malloc(RagCraftkey_size);
    RagCraft_get_key(encryption_key);

    encryption = dtw.encryption.newAES_Custom_CBC_v1_interface((char*)encryption_key);
    if(encryption == NULL){
      printf("%sError: %s%s\n", RED, "Invalid encryption key", RESET);
      goto endmain;
    }

    bool configured = create_user_config_models_path(encryption_key);
    if(!configured){
      goto endmain;
    }

    const char *action = args.get_arg(&args_obj, 1);
 
    if(action == NULL){
      printf("%sError: %s%s\n", RED, "No action provided", RESET);
      result = 1;
      goto endmain;
    }
    if(strcmp(action, START) == 0){
      result = start_action();
    }
    if(strcmp(action, CONFIG_MODEL) == 0){
      result = configure_model();
    }
    
    if(strcmp(action, RESSET) == 0){
      result = resset();
    }
    if(strcmp(action, LIST_MODEL) == 0){
      result = list_model();
    }
    if(strcmp(action, REMOVE_MODEL) == 0){
      result = remove_model();
    }
    if(strcmp(action, SET_MODEL_AS_DEFAULT) == 0){
      result = set_model_as_default();
    }
    if(strcmp(action, HELP) == 0 || args.is_flags_present(&args_obj, help_flags, help_size)){
      Asset * help = get_asset("help.txt");

      printf("%s%s%s\n", BLUE,(char*)help->data, RESET);
      result = 0;
    }
    
    if(result == -1){
      printf("%sError: %s%s\n", RED, "Invalid action", RESET);
      result = 1;
    }
    
    endmain:
      if(encryption_key){
        free(encryption_key);
      }
      if(config_path){
        free(config_path);
      }
      if(encryption){
        dtw.encryption.free(encryption);
      }
      return result;

}