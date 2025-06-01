add_rules("mode.debug", "mode.release")

set_warnings("all", "error")
set_languages("cxxlatest")

add_requires("gtest", {
  system = false,
  ---@diagnostic disable-next-line: missing-fields
  configs = {
    main = true,
    gmock = true,
  },
})

add_repositories("seffradev https://github.com/seffradev/xmake-repo.git")

add_requires("glew~2.2.0")

add_requires("seffradev::glfw~3.4", {
  system = false,
  ---@diagnostic disable-next-line: missing-fields
  configs = {
    glfw_include = "system",
    x11 = false,
    wayland = true,
  },
})

if is_mode("debug") then
  set_symbols("debug")
  set_optimize("none")
else
  set_symbols("hidden")
  set_optimize("fastest")
  set_strip("all")
end

target("core")
set_kind("static")
add_headerfiles("core/**.hpp")
add_files("core/**.mpp", { public = true })
set_policy("build.c++.modules", true)

target("renderer")
set_kind("static")
add_headerfiles("renderer/**.hpp")
add_files("renderer/**.mpp", { public = true })
set_policy("build.c++.modules", true)
add_deps("core")
add_packages("glfw", "glew")
add_links("glfw")
add_defines("GLFW_INCLUDE_VULKAN")

target("sandbox")
set_kind("binary")
add_files("sandbox/**.cpp")
add_deps("core", "renderer")
set_default(true)
add_cxxflags("gcc::-freport-bug")

-- Iterate over test files and create test targets
for _, file in ipairs(os.files("tests/**.cpp")) do
  local name = path.basename(file)
  target(name)
  set_kind("binary")
  add_packages("gtest")
  add_links("gtest_main")
  set_default(false)
  add_files(file)
  add_deps("core")
  add_tests("default")
  set_policy("build.c++.modules", true)
end

includes("@builtin/xpack")

xpack("core")
set_formats("zip")
add_targets("core")

xpack("renderer")
set_formats("zip")
add_targets("renderer")

xpack("sandbox")
set_formats("zip")
add_targets("sandbox")
set_author("Hampus Avekvist")
