
### Build Process Explanation
### IMPORTANT:
### For understand these part, read [Build Instructions](/docs/build_instructions.md) first


The Build process use [darwin](https://github.com/OUIsolutions/Darwin) to build the project  in mode full folder, 
witch means, it recursively list over the foder [Build Folder](/build/) and execute the code insided, starting 
by the [main.lua](/build/main.lua) file.

the build code use the following dependencies:

### LuaDotheWorld
[LuaDoTheWorld](https://github.com/OUIsolutions/LuaDoTheWorld) its a wrapper of the original [DoTheWorld](https://github.com/OUIsolutions/LuaDoTheWorld) project, and [LuaDoTheWorld](https://github.com/OUIsolutions/LuaDoTheWorld) provides a series of 
function, to manipulate files and dirs, like hashers, listages, read and write in files, etc.

### LuaShip
[LuaShip](https://github.com/OUIsolutions/LuaShip) its a Podman/Docker wrapper , that its used to create some releases such as:

- release/AiRagTemplate64.exe
- release/AiRagTemplate.deb
- release/AiRagTemplatei32.exe
- release/AiRagTemplate.out
- release/AiRagTemplate.rpm

all the builds functions,are located  in the [build functions](/build/build) part


