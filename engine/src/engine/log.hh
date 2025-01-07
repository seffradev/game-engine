#pragma once

#include <string_view>

class Logger {
public:
  enum class Level {
    Fatal,
    Error,
    Warning,
    Info,
    Trace,
    Debug,
  };

  Logger(Level level) : level(level) {}

  void log(Level level, std::string_view str) const;

private:
  [[nodiscard]] std::string_view level_to_string(Level level) const;

  Level level;
};
