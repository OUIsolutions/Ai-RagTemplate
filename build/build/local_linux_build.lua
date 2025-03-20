

function create_objects_ar()

    os.execute("mkdir -p libs")
    local itens = {
      {command="gcc -c dependencies/doTheWorld.c -o libs/doTheWorld.o",path="dependencies/doTheWorld.c"},
    {command="gcc -c dependencies/BearHttpsClient.c -o libs/BearHttpsClient.o -DBEARSSL_HTTPS_MOCK_CJSON_DEFINE",path="dependencies/BearHttpsClient.c"},
    {command="gcc -c dependencies/CArgvParse.c -o libs/CArgvParse.o",path="dependencies/CArgvParse.c"},
    }

    for _, item in ipairs(itens) do
        
        local executor = function()
            os.execute(item.command)
        end
        local side_effect_verifier = function()
            return darwin.dtw.generate_sha_from_file(item.path)
        end

        local sha =darwin.dtw.generate_sha_from_file(item.path)
        cache_execution({ "create .o object", item.path, item.command ,sha}, executor, side_effect_verifier)
    end


end 
function local_linux_build()
    silver_chain_organize()
    create_objects_ar()

    local compilation ="gcc -o "..PROJECT_NAME .." src/main.c libs/doTheWorld.o libs/BearHttpsClient.o libs/CArgvParse.o "
    print("compilation: ", compilation)
    os.execute(compilation)
   
end