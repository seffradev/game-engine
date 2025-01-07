add_rules("mode.debug", "mode.release")

set_warnings("all", "error")
set_languages("cxxlatest")

if is_mode("debug") then
  set_symbols("debug")
  set_optimize("none")
else
  set_symbols("hidden")
  set_optimize("fastest")
  set_strip("all")
end

includes("**/xmake.lua")
