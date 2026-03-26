#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void toUpperCase(char* str) {
    if (!str) return;
    
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void printString(const char* str) {
    if (!str) {
        cout << "nullptr" << endl;
        return;
    }
    cout << str << endl;
}

class Counter {
private:
    mutable int accessCount;
    string data;
    
public:
    Counter(const string& str) : data(str), accessCount(0) {}
    
    string getData() const {
        const_cast<Counter*>(this)->accessCount++;
        return data;
    }
    
    int getAccessCount() const {
        return accessCount;
    }
    
    void display() const {
        cout << "Данные: " << data << ", Обращений: " << accessCount << endl;
    }
};

class Logger {
private:
    string logBuffer;
    mutable int logCount;
    
public:
    Logger() : logCount(0) {}
    void addLog(const string& message) const {
        logCount++;
        const_cast<Logger*>(this)->logBuffer += message + "\n";
    }
    
    void printLogs() const {
        cout << "Логов записано: " << logCount << endl;
        cout << "Содержимое:\n" << logBuffer;
    }
};

int main() {
    const char* constStr = "hello world";
    cout << "\n1. Константная строка: ";
    printString(constStr);
    
    char mutableStr[100];
    strcpy(mutableStr, constStr);
    cout << "2. Неконстантный массив (копия): ";
    printString(mutableStr);
    
    cout << "\n3. Попытка передать constStr в toUpperCase() - ОШИБКА КОМПИЛЯЦИИ" << endl;
    
    cout << "\n4. Используем const_cast (ОПАСНО!):" << endl;
    char* nonConstPtr = const_cast<char*>(constStr);
    cout << "   ВНИМАНИЕ: строковый литерал может находиться в read-only памяти!" << endl;
    cout << "   Изменение через const_cast может вызвать segmentation fault" << endl;
    
    cout << "\n   Безопасный способ (работаем с копией):" << endl;
    toUpperCase(mutableStr);
    cout << "   После преобразования: ";
    printString(mutableStr);
    
    cout << "\nДемонстрация mutable и const_cast в классе" << endl;
    
    Counter counter("Привет, мир!");
    cout << "Начальное состояние: ";
    counter.display();
    
    cout << "\nВызов getData() 3 раза (константный метод):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Вызов " << i+1 << ": " << counter.getData() << endl;
    }
    
    cout << "\nСостояние после вызовов: ";
    counter.display();
    cout << "Обратите внимание: accessCount увеличился, хотя метод константный!" << endl;
    cout << "Это стало возможным благодаря const_cast (или mutable полю)" << endl;

    cout << "\nДемонстрация Logger (mutable + const_cast)" << endl;
    Logger logger;
    
    logger.addLog("Первое сообщение");
    logger.addLog("Второе сообщение");
    logger.addLog("Третье сообщение");
    
    logger.printLogs();

    return 0;
}