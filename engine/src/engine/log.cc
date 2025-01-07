#include "log.hh"

#include <iostream>
#include <string_view>

void Logger::log(Level level, std::string_view str) const {
  if (this->level >= level) {
    std::cout << level_to_string(level) << ": " << str << '\n';
  }
}

std::string_view Logger::level_to_string(Level level) const {
  switch (level) {
  case Level::Fatal:
    return "FATAL";
  case Level::Error:
    return "ERROR";
  case Level::Warning:
    return "WARNING";
  case Level::Info:
    return "INFO";
  case Level::Trace:
    return "TRACE";
  case Level::Debug:
    return "DEBUG";
  }
  return "UNREACHABLE";
}
