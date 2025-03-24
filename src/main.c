



int main(int argc, char  *argv[]){
    start_namespace();
    args_obj  = args.newCArgvParse(argc, argv);
    encryption = dtw.encryption.newAES_Custom_CBC_v1_interface("test");
    
    const char *action = args.get_arg(&args_obj, 1);

    if(action == NULL){
      printf("%sError: %s%s\n", RED, "No action provided", RESET);
      return 1;
    }
    if(strcmp(action, START) == 0){
      return start_action();
   }
    if(strcmp(action, CONFIG_MODEL) == 0){
      return configure_model();
    }
    
    if(strcmp(action, RESSET) == 0){
      return resset();
    }
    if(strcmp(action, LIST_MODEL) == 0){
      return list_model();
    }
    if(strcmp(action, REMOVE_MODEL) == 0){
      return remove_model();
    }
    if(strcmp(action, SET_MODEL_AS_DEFAULT) == 0){
      return set_model_as_default();
    }
    if(strcmp(action, HELP) == 0 || args.is_flags_present(&args_obj, help_flags, help_size)){
      Asset * help = get_asset("help.txt");

      printf("%s%s%s\n", BLUE,(char*)help->data, RESET);
      return 0;
    }
    
    printf("%sError: %s%s\n", RED, "Invalid action", RESET);
    return 1;

}