


function create_assets()
    local assets,size  = darwin.dtw.list_files_recursively("assets") 

    darwin.dtw.remove_any("src/assets/globals.assets.c")
    local assset_contens = io.open("src/assets/globals.assets.c","a")

    assset_contens:write("Asset assets[] = {\n")
    for i=1,size do 
        local asset = assets[i]
    end 
    assset_contens:write("};\n")
end 