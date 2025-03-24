
ModelProps *collect_model_props();

ModelProps * get_model_props_with_model_name(const char *model);

ModelProps * get_model_props_default();


ModelProps *newModelProps(const char *url, const char *key, const char *model);

void freeModelProps(ModelProps *modelProps);



