#include <engine/log.hh>

int main(int argc, char **argv) {
  Logger logger{Logger::Level::Trace};
  logger.log(Logger::Level::Info, "Hello, world!");

  return 0;
}
