
### Project Workflow and use case

When the project starts at [main.c](/src/main.c) the first thing that its to create the 
globals objects located in [globals](/src/globals.main_obj.c): 
### Globals 
- **args_obj** object to store the argv keys , check[C-argv-parser](https://github.com/OUIsolutions/C-argv-parser)
for more details

- **config_path** object to store the path of the [config_json](/docs/json_model_config.md) file
    that uses the macro **AiRagTemplate_get_key** and **AiRagTemplatekey_size** to get the encryption key

- **encryption** object to read and write the [config_json](/docs/json_model_config.md) file and encrypt the data
  check [DoTHeWorld Encryption Docs](https://github.com/OUIsolutions/DoTheWorld/blob/main/docs/encryption.md) for more details


after it , it gets the **action** from the user,  witch correspond to the first **argv[1]**argument of the program
and then, call one of the actions functions located at [actions](/src/actions/)

### Actions

### int configure_model();

The `configure_model` function, located in `src/actions/configure_model/fdefine.configure_model.c`, is responsible for configuring a language model. It checks if the necessary arguments (`model`, `key`, and `url`) have been provided. If any are missing, it displays an error message. Otherwise, it reads the content of the configuration file, checks if the model already exists, and updates or adds the model to the configuration file in JSON format. The function uses encryption to read and write the configuration file.

- **Functionality**: Configures a language model by checking for required arguments and updating the configuration file.
- **Error Handling**: Displays error messages if `model`, `key`, or `url` are not provided.
- **File Operations**: Reads and writes to the configuration file using encryption.
- **JSON Handling**: Manages the JSON structure of the configuration file, adding or updating model entries as needed.

