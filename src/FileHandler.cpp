#include <iostream>
#include <fstream>
#include <stdexcept>

class FileHandler {
public:
    FileHandler(const std::string &file_name)
        : file(file_name) {

        if(!file.is_open()) {
            throw std::runtime_error("Ошибка - файл не открыт");
        }

        std::cout << "Файл открыт" << endl;
    }

    ~FileHandler() {
        if(file.is_open()) {
            file.close();
            std::cout << "Файл закрыт" << endl;
        }
    }

    std::string readLine() {
        if (file.is_open()) {
            std::string file_line;
            if (std::getline(file, file_line)){
                return file_line;
            } else {
                throw std::runtime_error("Ошибка при чтении строки");
            }

        } else {
            throw std::runtime_error("Ошибка - файл не открыт");
        }
    }

    void writeLine(const std::string &t_data) {
        if (file.is_open()) {
            file << t_data;
        } else {
            throw std::runtime_error("Ошибка - файл не открыт");
        }
    }

    void getWriteLine() {

    }

private:
    std::fstream file;
}
