
local comands = {
    "mkdir -p dependencies",
    "curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/9.0.003/doTheWorld.c -o dependencies/doTheWorld.c",
    "curl -L https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.004/BearHttpsClient.h -o dependencies/BearHttpsClient.h",
    "curl -L https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.004/BearHttpsClient.c -o dependencies/BearHttpsClient.c",
    "curl -L https://github.com/OUIsolutions/C-argv-parser/releases/download/0.0.1/CArgvParse.h -o dependencies/CArgvParse.h",
    "curl -L https://github.com/OUIsolutions/C-argv-parser/releases/download/0.0.1/CArgvParse.c -o dependencies/CArgvParse.c",
    "curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/ClientSDKOpenAI/releases/download/0.0.6/SDK_OpenAI.c -o dependencies/SDK_OpenAI.c",
    "curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/ClientSDKOpenAI/releases/download/0.0.6/SDK_OpenAI.h -o dependencies/SDK_OpenAI.h",
}
function Install_dependencies()

    local libs = {
        {url  = "https://github.com/OUIsolutions/DoTheWorld/releases/download/9.0.003/doTheWorld.h", path = "dependencies/doTheWorld.h"},
        
    }
    os.execute("mkdir -p dependencies")
    for _, lib in ipairs(libs) do
        local executor = function ()
            os.execute("curl -L " .. lib.url .. " -o " .. lib.path)
        end

        local side_efect_verifier = function ()
            return darwin.dtw.generate_sha_from_file(lib.path)
        end

        cache_execution({"download", lib.url,lib.path},executor,side_efect_verifier)

    end

end