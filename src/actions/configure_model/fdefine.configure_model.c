//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end



int configure_model(){
    
   const  char *model = args.get_flag(&args_obj, model_lags, model_size, 0);
    if(model == NULL){
        printf("%sError: No Model Provided %s\n", RED, RESET);
        return 1;
    }
    const char *key = args.get_flag(&args_obj, key_flags, key_size, 0);
    
    if(key == NULL){
        printf("%sError: No key provided%s\n", RED, RESET);
        return 1;
    }

    const char *url = args.get_flag(&args_obj, url_flags, url_size, 0);
    if(url == NULL){
        printf("%sError: No url provided %s\n", RED , RESET);
        return 1;
    }
    char *models_path = get_user_config_models_path();
    char *model_json_content = dtw.load_string_file_content(models_path);
    if(model_json_content == NULL){
        cJSON *empty_array = cJSON_CreateArray();
        cJSON *model_obj = cJSON_CreateObject();
        cJSON_AddItemToObject(model_obj, model, empty_array);
        cJSON_AddStringToObject(model_obj, "key", key);
        cJSON_AddStringToObject(model_obj, "url", url);
        cJSON_AddStringToObject(model_obj, "model", model);
        char *dumped = cJSON_Print(model_obj);
        dtw.write_string_file_content(models_path, dumped);
        cJSON_Delete(model_obj);
        free(dumped);
        return 0;
    }
    cJSON *parsed = get_parsed_json(model_json_content);
    if(parsed == NULL){
        return 1;
    }
    //test if model already exists
    int size = cJSON_GetArraySize(parsed);
    for(int i = 0; i < size; i++){
        cJSON *obj = cJSON_GetArrayItem(parsed, i);
        cJSON *model_obj = cJSON_GetObjectItem(obj, "model");
        if(strcmp(model_obj->valuestring, model) == 0){
            //update the model
            cJSON_ReplaceItemInObject(obj, "key", cJSON_CreateString(key));
            cJSON_ReplaceItemInObject(obj, "url", cJSON_CreateString(url));
            char *dumped = cJSON_Print(parsed);
            dtw.write_string_file_content(models_path, dumped);
            cJSON_Delete(parsed);
            free(dumped);
            return 0;
        }
    }

    cJSON *model_obj = cJSON_CreateObject();
    cJSON_AddItemToArray(parsed, model_obj);
    cJSON_AddStringToObject(model_obj, "model", model);
    cJSON_AddStringToObject(model_obj, "key", key);
    cJSON_AddStringToObject(model_obj, "url", url);
    char *dumped = cJSON_Print(parsed);
    
    
    return 0;
}