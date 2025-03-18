


function create_assets()
    
    
    local actual_sha = darwin.dtw.generate_sha_from_file("src/assets/globals.assets.c")
    if actual_sha == "7be7fa1c4ebc2b051dc52c5bfe2b1314084bedc30f6f1e42c0e8ac3ed0a31d63" then
        return false
    end

    darwin.dtw.remove_any("src/assets/globals.assets.c")
    local assset_contents = io.open("src/assets/globals.assets.c","a")

    assset_contents:write("Asset assets[] = {\n")
    local concat_path = false;
    local assets,size  = darwin.dtw.list_files_recursively("assets",false) 

    for i=1,size do 
        local asset = assets[i]
        local content = darwin.dtw.load_file("assets/"..asset)
        assset_contents:write("(Asset){")
        assset_contents:write(".path="..'"'..asset..'"'..",")
        assset_contents:write(".data=(unsigned char[])".."{")
        
        for j=1,#content do 
            local current_char = string.sub(content, j, j)
            local byte = string.byte(current_char)
            assset_contents:write(byte..",")
        end
        assset_contents:write("0")
        assset_contents:write("},")



        assset_contents:write(".size="..#content)
        assset_contents:write("},\n")
    end 
    assset_contents:write("};\n")
    assset_contents:close()

 
    return true 
end 