# Ai-RagTemplate
A Rag CLI Template for C

## About the Project
This README was written by Grok with Ai-RagTemplate, an AI model developed by xAI. AiRagTemplate is a powerful tool for creating RAG (Retrieval-Augmented Generation) based applications in C. It provides a robust framework for managing language models, configuring APIs, and building CLI applications with ease.

### Key Features
- **Model Configuration**: Easily configure and manage different language models.
- **API Integration**: Seamless integration with various APIs for enhanced functionality.
- **CLI Interface**: Build command-line interfaces with straightforward commands.
- **Cross-Platform Builds**: Support for building on multiple platforms including Linux, Windows, and macOS.
- **Encryption**: Secure storage of configuration files with encryption.

## Getting Started
To get started with AiRagTemplate, follow these steps:

1. **Install Dependencies**: The project requires Darwin and either Docker or Podman. Darwin will self-install the other dependencies. Refer to the [build_instructions.md](/docs/build_instructions.md) for installation details. 

**tip to install darwin on linux:**
```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.2.0/darwin.c -o darwin.c && gcc darwin.c -o darwin.out && sudo mv darwin.out /usr/bin/darwin
```

2. **Local Build**: Perform a local build for testing with the following command, which will create the **AiRagTemplatetest.out** file:
```bash
darwin run_blueprint build/ --mode folder local_linux_build
```

3. **Configure a Model**: Use the CLI to configure a language model. For example:
```bash
AiRagTemplate configure_model --model grok-2-latest --url https://api.x.ai/v1/chat/completions --key YOUR_API_KEY
```

4. **Start the Application**: Launch the application with:
```bash
AiRagTemplate start
```

## Docs 
| File | Description |
| --- | --- |
|[build_instructions.md](/docs/build_instructions.md)| Instructions for building the project. |
|[cli_usage.md](/docs/cli_usage.md)| Usage guide for the CLI interface. |
|[project_dependencies.md](/docs/project_dependencies.md)| List of dependencies used in the project. |
|[json_model_config.md](/docs/json_model_config.md)| Configuration of the JSON model. |
|[build_toolchain.md](/docs/build_toolchain.md)| Details about the build toolchain used in the project. |
|[build_workflow.md](/docs/build_workflow.md)| Build workflow instructions. |
|[assets_embed_vars.md](/docs/assets_embed_vars.md)| Description of the embedded variables in the assets folder. |
|[licenses.md](/docs/licenses.md)| Licenses of the dependencies used in the project. |
|[project_workfow.md](/docs/project_workfow.md)| Overview of the project workflow and use cases. |
