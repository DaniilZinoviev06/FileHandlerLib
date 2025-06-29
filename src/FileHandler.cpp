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

        cout << "Файл открыт";
    }


    ~FileHandler() {
        if(file.is_open()) {
            file.close();
            cout << "Файл закрыт";
        }
    }


    void readLine() {

    }

    void writeLine() {

    }

private:
    std::ofstream file
}
