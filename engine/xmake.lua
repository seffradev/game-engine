add_rules("mode.debug", "mode.release")

target("engine")
set_kind("static")
add_files("src/**.cc")
add_includedirs("src", { public = true })
