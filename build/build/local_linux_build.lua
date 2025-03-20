

function create_objects_ar()
    local hasher = darwin.dtw.newHasher()

    hasher.digest_folder_by_content("libs")
    local TARGET_HASH = "e134d94f7ca01440c8ae04496a35db235050a6ac403c6bbb9f4da3fb43b43bf5"
    if hasher.get_value() == TARGET_HASH then
     -- return
    end
    darwin.dtw.remove_any("libs")
    os.execute("mkdir -p libs")
    local comands = {
        "gcc -c dependencies/doTheWorld.c -o libs/doTheWorld.o",
        "gcc -c dependencies/BearHttpsClient.c -o libs/BearHttpsClient.o -DBEARSSL_HTTPS_MOCK_CJSON_DEFINE",
        "gcc -c dependencies/CArgvParse.c -o libs/CArgvParse.o",
    }
    for _, command in ipairs(comands) do
        print("command: ", command)
        os.execute(command)
    end
    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("libs")
    print("new hasher is: ", new_hasher.get_value())

end 
function local_linux_build()
    silver_chain_organize()
    create_objects_ar()

    local compilation ="gcc -o "..PROJECT_NAME .." src/main.c libs/doTheWorld.o libs/BearHttpsClient.o libs/CArgvParse.o "
    print("compilation: ", compilation)
    os.execute(compilation)
   
end