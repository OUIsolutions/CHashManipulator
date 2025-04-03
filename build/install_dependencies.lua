function install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local EXPECTED_SHA = 'e79017844f3d2ffb1f91c7977c2395db924a28467f57c46a804969587f941fb3'
    if hasher.get_value() == EXPECTED_SHA then
        return
    end

    darwin.dtw.remove_any("dependencies")

    os.execute("mkdir -p dependencies")
    os.execute("curl -L https://raw.githubusercontent.com/DaveGamble/cJSON/refs/tags/v1.7.18/cJSON.c -o dependencies/cJSON.c")
    os.execute("curl -L https://raw.githubusercontent.com/DaveGamble/cJSON/refs/tags/v1.7.18/cJSON.h -o dependencies/cJSON.h")

    os.execute("curl -L https://github.com/OUIsolutions/CTextEngine/releases/download/3.0.000/CTextEngine.h -o dependencies/CTextEngine.h")
    os.execute("curl -L https://github.com/OUIsolutions/CTextEngine/releases/download/3.0.000/CTextEngine.c -o dependencies/CTextEngine.c")


    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: " .. new_hasher.get_value())
end