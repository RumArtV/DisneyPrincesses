#include <string>
#include <iostream>

#include "cli.h"
#include "vcs.h"

bool handle_init_command(const std::vector<std::string>& args) {
  if (!args.empty()) {
    std::cerr << "Ошибка: init-команда не содержит аргументов." << std::endl;
    return false;
  }

  if (!vcs_init()) {
    std::cerr << "Ошибка: Репозиторий уже существует." << std::endl;
    return false;
  }

  std::cout << "Репозиторий успешно инициализирован." << std::endl;
  return true;
}

bool handle_commit_command(const std::vector<std::string>& args) {
  if (args.empty()) {
    std::cerr << "Ошибка: commit-команда требует наличия сообщения для коммита." << std::endl;
    return false;
  }

  return vcs_commit(args[0]);
}

bool handle_diff_command(const std::vector<std::string>& args) {
  if (!args.empty()) {
    std::cerr << "Ошибка: diff-команда не содержит аргументов." << std::endl;
    return false;
  }

  std::cout << "Показывает различия между текущим состоянием и предыдущим коммитом." << std::endl;

  return true;
}

bool handle_log_command(const std::vector<std::string>& args) {
  if (!args.empty()) {
    std::cerr << "Ошибка: log-команда не содержит аргументов." << std::endl;
    return false;
  }

  vcs_log();

  return true;
}