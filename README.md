# Ai-RagTemplate
A Rag CLI Template for C

## About the Project
This project was written by Grok, an AI model developed by xAI. Ai-RagTemplate is a powerful tool for creating RAG (Retrieval-Augmented Generation) based applications in C. It provides a robust framework for managing language models, configuring APIs, and building CLI applications with ease.

### Key Features
- **Model Configuration**: Easily configure and manage different language models.
- **API Integration**: Seamless integration with various APIs for enhanced functionality.
- **CLI Interface**: Build command-line interfaces with straightforward commands.
- **Cross-Platform Builds**: Support for building on multiple platforms including Linux, Windows, and macOS.
- **Encryption**: Secure storage of configuration files with encryption.

## Getting Started
To get started with Ai-RagTemplate, follow these steps:

1. **Install Dependencies**: Ensure you have the necessary dependencies installed. Refer to the [project_dependencies.md](/docs/project_dependencies.md) file for a list of dependencies.

2. **Local Build**: Perform a local build for testing with the following command, which will create the **AiRagTemplatetest.out** file:
   ```bash
darwin run_blueprint build/ --mode folder local_linux_build
   ```

3. **Configure a Model**: Use the CLI to configure a language model. For example:
   ```bash
   AiRagTemplate configure_model --model o3-mini --url https://api.openai.com/v1/chat/completions --key YOUR_API_KEY
   ```

4. **Start the Application**: Launch the application with:
   ```bash
   AiRagTemplate start
   ```

## Dependencies
- **C-argv-parser**: For parsing command-line arguments.
- **BearHttpsClient**: For HTTPS API calls.
- **ClientSDKOpenAI**: Main SDK for AI functions.
- **DoTheWorld**: For file and directory operations.
- **cJSON**: For JSON parsing and manipulation.

## Build Instructions
For detailed build instructions, please refer to the [build_instructions.md](/docs/build_instructions.md) file.

## CLI Usage
For detailed CLI usage, please refer to the [cli_usage.md](/docs/cli_usage.md) file.

## Licenses
This project uses several open-source libraries. For more information on licenses, please refer to the [licenses.md](/docs/licenses.md) file.

## Project Workflow
For an overview of the project workflow, please refer to the [project_workflow.md](/docs/project_workflow.md) file.
