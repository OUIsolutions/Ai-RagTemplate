
## Cli Usage


### Configure a model
For Configure a model, you just need need to call **AiRagTemplate** passing **configure_model** as first argument:

```bash
AiRagTemplate configure_model --model o3-mini  --url https://api.openai.com/v1/chat/completions --key  API_KEY
```

### Start the application
For start the application, you just need to call **AiRagTemplate** passing **start** as first argument:

```bash
AiRagTemplate start
```
### Start the application with a model
For start the application with a model, you just need to call **AiRagTemplate** passing **start** as first argument and the model as second argument:

```bash
AiRagTemplate start --model o3-mini
```

### List Models 
to list the models, you just need to call **AiRagTemplate** passing **list_models** as first argument:

```bash
AiRagTemplate list_models
```

### Remove Model

For remove a model, you just need to call **AiRagTemplate** passing **remove_model** as first argument:

```bash
AiRagTemplate remove_model --model o3-mini
```

### Set model as Default 
For set a model as default, you just need to call **AiRagTemplate** passing **set_default_model** as first argument:

```bash
AiRagTemplate set_default_model --model o3-mini
```
### Resset Configuration
For reset the configuration, you just need to call **AiRagTemplate** passing **reset** as first argument:

```bash
AiRagTemplate reset
```

### Get Help
For get help, you just need to call **AiRagTemplate** passing **help** as first argument:

```bash
AiRagTemplate help
```


