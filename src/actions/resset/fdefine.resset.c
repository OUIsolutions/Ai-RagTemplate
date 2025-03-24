

int resset(){
    char *models_path = get_user_config_models_path();
    dtw.remove_any(models_path);
    return 0;
}