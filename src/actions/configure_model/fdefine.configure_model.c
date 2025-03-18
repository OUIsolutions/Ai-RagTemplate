//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end



int configure_model(){
    
   const  char *model = args.get_flag(&args_obj, model_lags, model_size, 0);
    if(model == NULL){
        printf("%sError: %s%s\n", RED, "No model provided", RESET);
        return 1;
    }
    const char *key = args.get_flag(&args_obj, key_flags, key_size, 0);
    
    if(key == NULL){
        printf("%sError: %s%s\n", RED, "No key provided", RESET);
        return 1;
    }

    const char *url = args.get_flag(&args_obj, url_flags, url_size, 0);
    if(url == NULL){
        printf("%sError: %s%s\n", RED, "No url provided", RESET);
        return 1;
    }
    char *models_path = get_user_config_models_path();
    printf("models_path: %s\n", models_path);
    return 0;
}