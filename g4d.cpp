#include <cstdio>
#include <cstring>
#include <filesystem>
#include <include/ylheader.h>
#include <iostream>
#include <string>

void cmd_help() {
  printf("Usage:\n"
         "  g4d <command> [options] <document>\n\n"
         "Commands:\n"
         "  init <document>              Initialize a Git repository for the "
         "document\n"
         "  diff [options] <document>    Show changes"
         "by default)\n"
         "  add [files...] <document>    Stage changes\n"
         "  commit [-m message] <document> Commit changes\n"
         "  status <document>            Show working tree status\n"
         "  log [options] <document>     Show commit history\n\n"
         "Examples:\n"
         "  g4d init ./test/doc1.docx\n"
         "  g4d diff ./test/doc1.docx\n"
         "  g4d add document.xml ./test/doc1.docx\n"
         "  g4d commit -m \"Initial commit\" ./test/doc1.docx\n"
         "  g4d status ./test/doc1.docx\n"
         "  g4d log --oneline ./test/doc1.docx\n\n"
         "\nBTW, we currently only support .doc or .docx files.\n");
}

void cmd_init(int argc, char *argv[]) {
  GitForDoc docFile = GitForDoc(argv[2]);
  printVecStr(runCmdAndReceOutput("git init --separate-git-dir=%s %s",
                                  docFile._gitPath.c_str(),
                                  docFile._tmpPath.c_str()));
  fs::remove_all(docFile._tmpPath);
}

void cmd_diff(int argc, char *argv[]) {
  GitForDoc docFile = GitForDoc(argv[argc - 1]);
  std::string cmd = "git diff ";
  for (int i = 2; i < argc - 1; i++) {
    cmd = cmd + argv[i] + " ";
  }
  printVecStr(runCmdAndReceOutput("cd %s && %s-- .tmp",
                                  docFile._gitPath.parent_path().c_str(),
                                  cmd.c_str()));

  fs::remove_all(docFile._tmpPath);
}

void cmd_add(int argc, char *argv[]) {
  GitForDoc docFile = GitForDoc(argv[argc - 1]);
  std::string cmd = "git add ";
  for (int i = 2; i < argc - 1; i++) {
    cmd = cmd + argv[i] + " ";
  }
  printVecStr(runCmdAndReceOutput(
      "cd %s && %s.tmp", docFile._gitPath.parent_path().c_str(), cmd.c_str()));

  fs::remove_all(docFile._tmpPath);
}

void cmd_commit(int argc, char *argv[]) {
  GitForDoc docFile = GitForDoc(argv[argc - 1]);
  std::string cmd = "git commit ";
  for (int i = 2; i < argc - 1; i++) {
    cmd = cmd + argv[i] + " ";
  }
  printVecStr(runCmdAndReceOutput(
      "cd %s && %s.tmp", docFile._gitPath.parent_path().c_str(), cmd.c_str()));

  fs::remove_all(docFile._tmpPath);
}

void cmd_status(int argc, char *argv[]) {
  GitForDoc docFile = GitForDoc(argv[argc - 1]);
  std::string cmd = "git status ";
  for (int i = 2; i < argc - 1; i++) {
    cmd = cmd + argv[i] + " ";
  }
  printVecStr(runCmdAndReceOutput(
      "cd %s && %s", docFile._gitPath.parent_path().c_str(), cmd.c_str()));

  fs::remove_all(docFile._tmpPath);
}

void cmd_log(int argc, char *argv[]) {
  GitForDoc docFile = GitForDoc(argv[argc - 1]);
  std::string cmd = "git log ";
  for (int i = 2; i < argc - 1; i++) {
    cmd = cmd + argv[i] + " ";
  }
  printVecStr(runCmdAndReceOutput(
      "cd %s && %s", docFile._gitPath.parent_path().c_str(), cmd.c_str()));

  fs::remove_all(docFile._tmpPath);
}

int main(int argc, char *argv[]) {
  if (argc <= 2) {
    cmd_help();
  }
  if (argc == 3 && !std::strcmp(argv[1], "init")) {
    cmd_init(argc, argv);
  }

  if (argc >= 3 && !std::strcmp(argv[1], "diff")) {
    cmd_diff(argc, argv);
  }

  if (argc >= 3 && !std::strcmp(argv[1], "add")) {
    cmd_add(argc, argv);
  }

  if (argc >= 3 && !std::strcmp(argv[1], "commit")) {
    cmd_commit(argc, argv);
  }

  if (argc >= 3 && !std::strcmp(argv[1], "status")) {
    cmd_status(argc, argv);
  }

  if (argc >= 3 && !std::strcmp(argv[1], "log")) {
    cmd_log(argc, argv);
  }
  return 0;
}
