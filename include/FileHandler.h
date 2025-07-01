#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <unordered_set>

class FileHandler {
public:
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;
    FileHandler& operator=(FileHandler&& move_file);

    FileHandler(const std::string &file_name);

    FileHandler(FileHandler&& move_file);

    ~FileHandler();

    std::string readLine();
    void writeLine(const std::string &t_data);
    void getWriteLine();
    void changeReadPos();

private:
    std::fstream file;
    std::string file_name;
    static std::unordered_set<std::string> open_files;
};


// реализация в src/
