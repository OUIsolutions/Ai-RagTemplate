
int list_model(){

    char *models_path = get_user_config_models_path();
    if(models_path == NULL){
        return 1;
    }
    char *content = dtw.load_string_file_content(models_path);
    if(content == NULL){
        printf("%sError: No models found%s\n", RED, RESET);
        return 1;
    }
    cJSON *parsed = get_parsed_json(content);
    if(parsed == NULL){
        return 1;
    }
    int size = cJSON_GetArraySize(parsed);

    for(int i = 0; i < size; i++){
        cJSON *obj = cJSON_GetArrayItem(parsed, i);
        cJSON *model = cJSON_GetObjectItem(obj, "model");
        cJSON *url = cJSON_GetObjectItem(obj, "url");
        printf("%sModel: %s%s\n", BLUE, model->valuestring, RESET);
        printf("%sUrl: %s%s\n", BLUE, url->valuestring, RESET);
        cJSON *is_default = cJSON_GetObjectItem(obj, "default");
        if(is_default != NULL){
            printf("%sDefault: %s%s\n", BLUE, is_default->valueint == 1 ? "true" : "false", RESET);
        }
        printf("\n");
    }

}