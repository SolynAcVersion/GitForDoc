#pragma once
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <json/json.h>
#include <minizip/unzip.h>
#include <stdexcept>
#include <string>
#include <vector>
#include <zip.h>
#include <zlib.h>
namespace fs = std::filesystem;

class YlFile {
public:
  std::vector<std::string> readTextFromFile(std::string path);
  std::vector<fs::path> listFilesAndDirectories(fs::path path);
};

class GitForDoc {
public:
  GitForDoc(fs::path path);

  void zipToDoc();

  fs::path _docPath, _gitPath, _tmpPath;
};
std::vector<std::string> runCmdAndReceOutput(const char *cmd, ...)
    __attribute__((format(printf, 1, 2)));
void printVecStr(const std::vector<std::string> vecstr);
