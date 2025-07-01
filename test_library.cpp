#include <iostream>
#include <stdexcept>
#include <FileHandler.h>

int main(){
    try {
        FileHandler fh("example.txt");

        //FileHandler fh_2 = fh; // будет ошибка, только move

        FileHandler fh2 = std::move(fh);

        //FileHandler fh3("example.txt");

        fh2.getWriteLine();

        // Запись
        fh2.writeLine("1-я строчка");
        fh2.writeLine("2-я строчка");
        fh2.writeLine("3-я строчка");


        // Чтение
        std::cout << fh2.readLine() << std::endl;
        std::cout << fh2.readLine() << std::endl;
        std::cout << fh2.readLine() << std::endl;


        // запись с консоли
        fh2.getWriteLine();

        fh2.changeReadPos();

        std::cout << "\nДанные из файла" << std::endl;
        try {
            while(true) {
                std::cout << fh.readLine() << std::endl;
            }
        } catch (const std::runtime_error& e) {
            if (std::string(e.what()) != "Конец файла") {
                throw;
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    std::cout << "-- Обработка ошибок --";

    try {
        std::cout << "\nОткрытие несуществующего файла" << std::endl;
        FileHandler fh_nonexistent("/Загрузки/aaa/file.txt");
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nЗапись в закрытый файл" << std::endl;
        FileHandler fh_closed("a.txt");
        fh_closed.~FileHandler(); // вызов деструктора явно, для того, чтобы показать обработку ошибки
        fh_closed.writeLine("Вызываем ошибку");
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nЧтение из пустого файла" << std::endl;
        FileHandler fh_empty("b.txt");
        std::cout << fh_empty.readLine() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
