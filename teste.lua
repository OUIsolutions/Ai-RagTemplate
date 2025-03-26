
local image = darwin.ship.create_machine("alpine:latest")
image.provider = "podman"
image.add_comptime_command("apk update")
image.add_comptime_command("apk add --no-cache gcc musl-dev curl")
os.execute("mkdir -p release")
image.start({
    volumes = {
        { "./release", "/release" },
        { "./src",     "/src" },
        { "./dependencies","/dependencies" }

    },
    command ="gcc --static /src/main.c -DDEFINE_DEPENDENCIES -o /release/alpine_static_bin.out"

})