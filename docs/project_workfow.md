
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
