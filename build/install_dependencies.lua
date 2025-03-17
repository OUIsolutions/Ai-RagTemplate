function Install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local TARGET_HASH = "3693deff3fef1bb40b6f25a3b45dd097b6e4cc479a29015dc0657b0815b84fd7"
    if hasher.get_value() == TARGET_HASH then
        return
    end
    local comands = {
        "mkdir -p dependencies",
        "curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/v8.002/doTheWorld.h -o dependencies/doTheWorld.h",
    }
    for _, command in ipairs(comands) do
        os.execute(command)
    end
    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: ", new_hasher.get_value())
end