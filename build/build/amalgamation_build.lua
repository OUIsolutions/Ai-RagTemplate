local alreay_amalamated_done = false
function amalgamation_build()
    if alreay_amalamated_done then
        return
    end
    alreay_amalamated_done = true
    silver_chain_organize()


    local runtime = darwin.camalgamator.generate_amalgamation("src/cli/main.c")
    
  
    darwin.dtw.write_file("release/"..PROJECT_NAME.." .c", runtime)

    local api_one = darwin.camalgamator.generate_amalgamation("src/imports/imports.api_define.h")
    darwin.dtw.write_file("release/"..PROJECT_NAME.."ApiOne.h", api_one)

    local max_content = darwin.camalgamator.ONE_MB * 10
    local max_recursion = 100

    local dependencie_not_included = darwin.camalgamator.generate_amalgamation_with_callback(
        "src/imports/imports.api_define.h",
    function(import, path)
        if darwin.dtw.ends_with(import,"dependencies.h") then
            return "dont-include"
        end
        return "include-once"
    end,
    max_content,
    max_recursion
    )    
    darwin.dtw.write_file("release/"..PROJECT_NAME.."ApiNoDependenciesIncluded.h ", dependencie_not_included)


end
