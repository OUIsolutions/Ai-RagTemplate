//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
//silver_chain_scope_end


char *agent_get_ai_chosen_asset(cJSON *args, void *pointer){

  cJSON *asset = cJSON_GetObjectItem(args, "doc");
  if(!cJSON_IsString(asset)){
        return NULL;
  }

  Asset *current_aset = get_asset(asset->valuestring);

  if(!current_aset){
    return NULL;
  }

  return (char*)current_aset->data;
}


void configure_read_asset_callbacks(OpenAiInterface *openAi){
    cJSON *assets_json = cJSON_CreateArray();
    DtwStringArray *all_assets = list_assets_recursively(NULL);
    for(int i = 0; i < all_assets->size; i++){
        cJSON_AddItemToArray(assets_json, cJSON_CreateString(all_assets->strings[i]));
    }
    char *assets_printed = cJSON_PrintUnformatted(assets_json);
    char *message = malloc(strlen(assets_printed) + 100);
    sprintf(message, "The following docs are available: %s", assets_printed);
    
    openai.openai_interface.add_system_prompt(openAi,message);
    OpenAiCallback *callback = new_OpenAiCallback(agent_get_ai_chosen_asset, NULL, "get_doc", "get a  do to help users in question", false);
    OpenAiInterface_add_parameters_in_callback(callback, "doc", "Pass the name of doc you want to read.", "string", true);
    OpenAiInterface_add_callback_function_by_tools(openAi, callback);


    dtw.string_array.free(all_assets);
    free(assets_printed);
    cJSON_Delete(assets_json);
}


char *agent_list_recursively(cJSON *args, void *pointer){
    
    cJSON *path = cJSON_GetObjectItem(args, "path");
    if(!cJSON_IsString(path)){
        return NULL;
    }
    DtwStringArray *all_itens = dtw.list_files_recursively(path->valuestring,true);
    cJSON *all_intens_cjson = cJSON_CreateArray();
    for(int i = 0; i < all_itens->size; i++){

        char *current_file = all_itens->strings[i]; 
        if(!dtw_starts_with(current_file,"./." )){
            cJSON_AddItemToArray(all_intens_cjson, cJSON_CreateString(current_file));
        }
    }
    dtw.string_array.free(all_itens);
    char *all_intens_string = cJSON_PrintUnformatted(all_intens_cjson);
    cJSON_Delete(all_intens_cjson);
    printf("%s AI LISTED: %s\n",YELLOW, path->valuestring, RESET);
    return all_intens_string;    
}

void configure_list_recursively_callbacks(OpenAiInterface *openAi){
    OpenAiCallback *callback = new_OpenAiCallback(agent_list_recursively, NULL, "list_recursively", "list all files recursively in a path", false);
    OpenAiInterface_add_parameters_in_callback(callback, "path", "Pass the path you want to list recursively.", "string", true);
    OpenAiInterface_add_callback_function_by_tools(openAi, callback);
}


char *agent_read_file(cJSON *args, void *pointer){
    cJSON *path = cJSON_GetObjectItem(args, "path");
    if(!cJSON_IsString(path)){
        return NULL;
    }
    char *content =dtw.load_string_file_content(path->valuestring);
    printf("%s AI READDED: %s\n",YELLOW, path->valuestring, RESET);
    return content;
}

void configure_read_file_callbacks(OpenAiInterface *openAi){
    OpenAiCallback *callback = new_OpenAiCallback(agent_read_file, NULL, "read_file", "read a file content", false);
    OpenAiInterface_add_parameters_in_callback(callback, "path", "Pass the path you want to read.", "string", true);
    OpenAiInterface_add_callback_function_by_tools(openAi, callback);
}


char *agent_write_file(cJSON *args, void *pointer){
    cJSON *path = cJSON_GetObjectItem(args, "path");
    cJSON *content = cJSON_GetObjectItem(args, "content");
    if(!cJSON_IsString(path) || !cJSON_IsString(content)){
        return NULL;
    }
    dtw.write_string_file_content(path->valuestring, content->valuestring);
    printf("%s AI WROTE: %s\n",YELLOW, path->valuestring, RESET);
    return "file wrotted";
}

void configure_write_file_callbacks(OpenAiInterface *openAi){
    OpenAiCallback *callback = new_OpenAiCallback(agent_write_file, NULL, "write_file", "write a file content", false);
    OpenAiInterface_add_parameters_in_callback(callback, "path", "Pass the path you want to write.", "string", true);
    OpenAiInterface_add_parameters_in_callback(callback, "content", "Pass the content you want to write.", "string", true);
    OpenAiInterface_add_callback_function_by_tools(openAi, callback);
}



