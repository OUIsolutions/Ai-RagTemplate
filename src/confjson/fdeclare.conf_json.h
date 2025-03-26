
bool get_user_config_models_path();


cJSON *create_model_obj(const char *model, const char *key, const char *url);

///ensure that the schema of json its correct
cJSON * get_parsed_json(const char *json);