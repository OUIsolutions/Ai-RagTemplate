function Install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local TARGET_HASH = "d1d528e4b01631a77a490164d1c91f229afdd0110ba73d5207616bc847c7b6b7"
    if hasher.get_value() == TARGET_HASH then
        return
    end
    local comands = {
        "mkdir -p dependencies",
        "curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/9.0.003/doTheWorld.h -o dependencies/doTheWorld.h",
        "curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/9.0.003/doTheWorld.c -o dependencies/doTheWorld.c",
        "curl -L https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.004/BearHttpsClient.h -o dependencies/BearHttpsClient.h",
        "curl -L https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.2.004/BearHttpsClient.c -o dependencies/BearHttpsClient.c",
        "curl -L https://github.com/OUIsolutions/C-argv-parser/releases/download/0.0.1/CArgvParse.h -o dependencies/CArgvParse.h",
        "curl -L https://github.com/OUIsolutions/C-argv-parser/releases/download/0.0.1/CArgvParse.c -o dependencies/CArgvParse.c",
        "curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/ClientSDKOpenAI/releases/download/0.0.6/SDK_OpenAI.c -o dependencies/SDK_OpenAI.c",
        "curl -L https://github.com/SamuelHenriqueDeMoraisVitrio/ClientSDKOpenAI/releases/download/0.0.6/SDK_OpenAI.h -o dependencies/SDK_OpenAI.h",
    }
    for _, command in ipairs(comands) do
        os.execute(command)
    end
    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: ", new_hasher.get_value())
end