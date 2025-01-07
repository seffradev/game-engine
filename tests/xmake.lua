add_requires("gtest", {
  configs = {
    main = false,
    gmock = true,
  },
})

-- Iterate over test files and create test targets
for _, file in ipairs(os.files("**.cc")) do
  local name = path.basename(file)
  target(name)
  set_kind("binary")
  add_packages("gtest")
  set_default(false)
  add_files(file)
  add_deps("engine")
  add_tests("default")
end
