#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

class FileHandler {
public:
    FileHandler(const FileHandler&) = delete; // защита от копирования объекта, иначе может
    FileHandler& operator=(const FileHandler&) = delete; // быть непредсказуемое поведение

    FileHandler(const std::string &file_name);
    ~FileHandler();

    std::string readLine();
    void writeLine(const std::string &t_data);
    void getWriteLine();
    void changeReadPos();

private:
    std::fstream file;
};


// реализация в src/
