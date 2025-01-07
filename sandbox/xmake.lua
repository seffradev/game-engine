add_rules("mode.debug", "mode.release")

target("sandbox")
set_kind("binary")
add_files("src/*.cc")
add_deps("engine")
set_default(true)
