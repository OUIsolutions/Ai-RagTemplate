//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
//silver_chain_scope_end

char * get_user_config_models_path(){
    #ifdef __linux__
    const char *homedir = getenv("HOME");
    #elif _WIN32
    const char *homedir = getenv("USERPROFILE");
    #endif

    if(homedir == NULL){
        printf("%sError: No home directory found%s\n", RED, RESET);
        return NULL;
    }
    return dtw.concat_path(homedir, models_json);
}

cJSON *create_model_obj(const char *model, const char *key, const char *url){
    cJSON *model_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(model_obj, "model", model);
    cJSON_AddStringToObject(model_obj, "key", key);
    cJSON_AddStringToObject(model_obj, "url", url);
    return model_obj;
}

cJSON * get_parsed_json(const char *json){
    cJSON *parsed = cJSON_Parse(json);
    if(parsed == NULL){
        printf("%sError: Invalid json %s\n", RED, RESET);
        return NULL;
    }
    if(!cJSON_IsArray(parsed)){
        printf("%sError: main json its not a array %s\n", RED, RESET);
        cJSON_Delete(parsed);
        return NULL;
    }
    int size = cJSON_GetArraySize(parsed);
    for(int i = 0; i < size; i++){
        cJSON *obj = cJSON_GetArrayItem(parsed, i);
        if(!cJSON_IsObject(obj)){
            printf("%sError: [%d] json item its not a object%s\n", RED,i, RESET);
            cJSON_Delete(parsed);
            return NULL;
        }

        cJSON *model = cJSON_GetObjectItem(obj, "model");
        if(!cJSON_IsString(model)){
            printf("%sError: [%d]['model'] model its not a string%s\n", RED,i, RESET);
            cJSON_Delete(parsed);
            return NULL;
        }

        cJSON *key = cJSON_GetObjectItem(obj, "key");
        if(!cJSON_IsString(key)){
            printf("%sError: [%d]['key'] key its not a string%s\n", RED,i, RESET);
            cJSON_Delete(parsed);
            return NULL;
        }

        cJSON *url = cJSON_GetObjectItem(obj, "url");
        if(!cJSON_IsString(url)){
            printf("%sError: [%d]['url'] url its not a string%s\n", RED,i, RESET);
            cJSON_Delete(parsed);
            return NULL;
        }
    }
    return parsed;

}
