
The src folder its responsible for the source code of the project, the src folder is:
```txt
src
├── actions
│   ├── configure_model
│   │   ├── fdeclare.configure_model.h
│   │   └── fdefine.configure_model.c
│   ├── list_models
│   │   ├── fdeclare.list_models.h
│   │   └── fdefine.list_models.c
│   ├── remove_model
│   │   ├── fdeclare.remove_model.h
│   │   └── fdefine.remove_model.c
│   ├── resset
│   │   ├── fdeclare.resset.h
│   │   └── fdefine.resset.c
│   ├── set_model_as_default
│   │   ├── fdeclare.set_model_as_default.h
│   │   └── fdefine.set_model_as_default.c
│   └── start
│       ├── fdeclare.start.h
│       └── fdefine.start.c
├── ai_functions
│   ├── fdeclare.ai_functions.h
│   └── fdefine.ai_functions.c
├── assets
│   ├── fdeclare.assets.h
│   ├── fdefine.asset.c
│   ├── globals.assets.c
│   └── types.assets.h
├── chat
│   ├── fdeclare.chat.h
│   └── fdefine.chat.c
├── config
│   ├── consts.actions.h
│   ├── consts.flags.h
│   ├── consts.paths.h
│   └── macros.colrors.h
├── confjson
│   ├── fdeclare.conf_json.h
│   └── fdefine.conf_json.c
├── globals.main_obj.c
├── imports
│   ├── imports.consts.h
│   ├── imports.dep_declare.h
│   ├── imports.fdeclare.h
│   ├── imports.fdefine.h
│   ├── imports.fdefine,list_models.h
│   ├── imports.globals.h
│   ├── imports.macros.h
│   └── imports.types.h
├── main.c
├── model_props
│   ├── fdeclare.model_props.h
│   ├── fdefine.model_props.c
│   └── types.model_props.h
├── namespace
│   ├── fdeclare.namespace.h
│   ├── fdefine.namespace.c
│   └── globals.namespace.c
└── src_dependencies
    ├── dep_declare.dependencies.h
    └── fdefine.dependencies.c
```

The Parts explanation:
 - Action : The actions folder contains the functions that are responsible for the actions that the user can do with the project. like (start, list_models, remove_model, etc)
- Ai Functions : The ai_functions folder contains functions callbacks that the AI can call to interact with the project. 
  check [OpenAiSdk](https://www.facebook.com/groups/264059710385123?locale=pt_BR)
- Assets : The assets folder contains the functions that are responsible for the assets of the project. like (list_assets_files, get_asset, etc)
- Chat : The chat folder contains the functions that are responsible for the chat of the project. like (send_message, get_message, etc)
- Config : The config folder contains the constants of the project. like (consts.actions, consts.flags, consts.paths, macros.colors)
- Confjson : The confjson folder contains the functions that are responsible for the configuration json models of the project. like (load_config, save_config, etc)
- Imports : The imports are managed by SilverChain check [SilverChain](https://github.com/OUIsolutions/SilverChain)
- Model Props : The model_props folder contains the functions that are responsible for the model properties of the project. like (get_model_props, set_model_props, etc)
- Namespace : The namespace folder contains the initialization of project namespaces function pointers 

