//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


int resset(){
    char *models_path = get_user_config_models_path();
    dtw.remove_any(models_path);
    return 0;
}