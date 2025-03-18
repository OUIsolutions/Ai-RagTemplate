//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
//silver_chain_scope_end

char * get_user_config_models_path(){
    const char *homedir =  getenv("HOME");
    if(homedir == NULL){
        return NULL;
    }
    return dtw.concat_path(homedir,models_json);
}