
### Build ToolChain Explanation
### IMPORTANT:
### For understand these part, read [build_instructions.md](assets/docs/build_instructions.md) and [build_toolchain.md](/assets/docs/build_toolchain.md) first

### [main.lua](/build/main.lua)
- verify if its to test a container 
  - if its to test a countainer , creates and launch that container and end build

- create the assets embed vars [Assets docs](/assets/docs/assets_embed_vars.md)
- iterate over all the functions into [build_funcs.lua](/build/build_funcs.lua)
  that are located in [builds](/build/build/) folder and execute them


### Build Functions
