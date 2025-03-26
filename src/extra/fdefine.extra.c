//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
//silver_chain_scope_end



void release_if_not_null(void *pointer, void (*free_function)(void *)){
    if(pointer != NULL){
        free_function(pointer);
    }
}