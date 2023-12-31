#include <format>
#include <iostream>

int main(int, char **) {
  std::cout << std::format("{}", "hello world") << std::endl;
  return 0;
}
