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
  printf("%s AI READDED DOCS: %s\n",YELLOW,asset->valuestring, RESET);

  Asset *current_aset = get_asset(asset->valuestring);

  if(!current_aset){
    return NULL;
  }

  return (char*)current_aset->data;
}


void configure_read_asset_callbacks(OpenAiInterface *openAi){
    cJSON *assets_json = cJSON_CreateArray();
    DtwStringArray *all_assets = list_assets_recursively("docs");
    for(int i = 0; i < all_assets->size; i++){
        cJSON_AddItemToArray(assets_json, cJSON_CreateString(all_assets->strings[i]));
    }
    char *assets_printed = cJSON_PrintUnformatted(assets_json);
    char *message = malloc(strlen(assets_printed) + 100);
    sprintf(message, "The following docs are available: %s", assets_printed);
            
    openai.openai_interface.add_system_prompt(openAi,message);
    OpenAiCallback *callback = new_OpenAiCallback(agent_get_ai_chosen_asset, NULL, "get_doc", "get a documentation text", false);
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
    DtwStringArray *all_itens = dtw.list_files_recursively(path->valuestring,false);
    cJSON *all_intens_cjson = cJSON_CreateArray();
    for(int i = 0; i < all_itens->size; i++){

        char *current_file = all_itens->strings[i]; 

        bool is_hidden = dtw_starts_with(current_file, ".");
        if(!is_hidden){
            char *joined = dtw_concat_path(path->valuestring, current_file);
            cJSON_AddItemToArray(all_intens_cjson, cJSON_CreateString(joined));
            free(joined);
        }

    }
    dtw.string_array.free(all_itens);
    char *all_intens_string = cJSON_PrintUnformatted(all_intens_cjson);
    cJSON_Delete(all_intens_cjson);
    printf("%s AI LISTED RECURSIVELY: %s\n",YELLOW, path->valuestring, RESET);
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

char *agent_execute_command(cJSON *args, void *pointer){
    cJSON *command = cJSON_GetObjectItem(args, "command");
    if(!cJSON_IsString(command)){
        return NULL;
    }
    int result = system(command->valuestring);
    printf("%s AI EXECUTED COMMAND: %s\n",YELLOW, command->valuestring, RESET);
    char *result_str = malloc(20);
    sprintf(result_str, "%d", result);
    return result_str;
}

void configure_execute_command_callbacks(OpenAiInterface *openAi){
    OpenAiCallback *callback = new_OpenAiCallback(agent_execute_command, NULL, "execute_command", "execute a command", false);
    OpenAiInterface_add_parameters_in_callback(callback, "command", "Pass the command you want to execute.", "string", true);
    OpenAiInterface_add_callback_function_by_tools(openAi, callback);
}

char *agent_remove_file(cJSON *args, void *pointer){
    cJSON *path = cJSON_GetObjectItem(args, "path");
    if(!cJSON_IsString(path)){
        return NULL;
    }
    dtw.remove_any(path->valuestring);
    printf("%s AI REMOVED: %s\n",YELLOW, path->valuestring, RESET);
    return "file or directory removed";
}

void configure_remove_file_callbacks(OpenAiInterface *openAi){
    OpenAiCallback *callback = new_OpenAiCallback(agent_remove_file, NULL, "remove_file", "remove a file or directory", false);
    OpenAiInterface_add_parameters_in_callback(callback, "path", "Pass the path you want to remove.", "string", true);
    OpenAiInterface_add_callback_function_by_tools(openAi, callback);
}