#include "../include/FileHandler.h"

FileHandler::FileHandler(const std::string &file_name)
    : file(file_name, std::ios::in | std::ios::out | std::ios::app) {

    if(!file.is_open()) {
        throw std::runtime_error("Ошибка - файл не открыт");
    }

    std::cout << "Файл открыт" << std::endl;
    file.seekg(0, std::ios::beg);
}


FileHandler::FileHandler(FileHandler&& move_file)
    : file(std::move(move_file.file)), file_name(std::move(move_file.file_name)) {
    std::cout << "Файл перемещен" << std::endl;
};

FileHandler& FileHandler::operator=(FileHandler&& move_file) {
    file = std::move(move_file.file);
    file_name = std::move(move_file.file_name);

    return *this;
}

FileHandler::~FileHandler() {
    if(file.is_open()) {
        file.close();
        std::cout << "Файл закрыт" << std::endl;
    }
}

std::string FileHandler::readLine() {
    if (file.is_open()) {
        std::string file_line;
        if (std::getline(file, file_line))
            return file_line;

        if (file.eof()) {
            file.clear();
            throw std::runtime_error("Достигнут конец файла");
        } else {
            throw std::runtime_error("Ошибка при чтении строки");
        }
    } else {
        throw std::runtime_error("Ошибка - файл не открыт");
    }
}

void FileHandler::writeLine(const std::string &t_data) {
    if (file.is_open()) {
        std::streampos read_pos = file.tellg();
        file.seekp(0, std::ios::end);
        file << t_data << '\n';
        file.flush();

        if (read_pos != std::streampos(-1))
            file.seekg(read_pos);

        std::cout << "Данные записаны в файл\n";
    } else {
        throw std::runtime_error("Ошибка - файл не открыт");
    }
}

void FileHandler::getWriteLine() {
    if (file.is_open()) {
        std::cout << "Введите текст(/exit_input - для выхода):\n";
        std::string stream_line;

        while(true) {
            std::getline(std::cin, stream_line);

            if (stream_line == "/exit_input")
                break;

            writeLine(stream_line);
        }
    } else {
        throw std::runtime_error("Ошибка - файл не открыт");
    }
}

void FileHandler::changeReadPos() {
    if (file.is_open()) {
        file.seekg(0);
    } else {
        throw std::runtime_error("Ошибка - файл не открыт");
    }
}
