
## Build Instructions

### Build Requirements 
#### Darwin 
For Build the project you must have [Darwin](https://github.com/OUIsolutions/Darwin) installed on version 0.1.23
if you are on linux you can install darwin with:

```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.1.23/darwin.c -o darwin.c &&
gcc darwin.c -o darwin.out &&
sudo mv darwin.out /usr/bin/darwin
```
#### Podman or Docker 
You must have podman or docker installed on your machine to build the project, you can set what you want to use on the **build/config.lua** file.



### Local Build
make a local build to test with the following command it will create the **AiRagTemplatetest.out** file
```bash
darwin run_blueprint build/ --mode folder local_linux_build
```

### Full Build
if you want to make a full build to all platforms you can use the following command, it will create the following files:
```bash
 darwin run_blueprint build/ --mode folder amalgamation_build alpine_static_build windowsi32_build windowsi64_build rpm_static_build debian_static_build
```



Output files:
- release/AiRagTemplate64.exe
- release/AiRagTemplate.c
- release/AiRagTemplate.deb
- release/AiRagTemplatei32.exe
- release/AiRagTemplate.out
- release/AiRagTemplate.rpm


### Build Configurations
All build configurations are in the **build/config.lua** file.
the default its: 
```lua
PROJECT_NAME = "AiRagTemplate"
CONTANIZER   = "podman"
VERSION      = "0.0.9"
LICENSE      = "MIT"
URL          = "https://github.com/OUIsolutions/Ai-RagTemplate"
DESCRIPITION = "A Rag Based Template for C"
FULLNAME     = "Ai-RagTemplate"
EMAIL        = "mateusmoutinho01@gmail.com"
SUMARY       = "A Rag Based Template for C"
YOUR_CHANGES = "--"
```