#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Объявление переменных
    int intVal = 66;
    double doubleVal = 3.1415;
    float floatVal = 2.71;
    char charVal = 'A';
    bool boolVal = true;
    
    double intToDouble = static_cast<double>(intVal);
    cout << "int " << intVal << " -> double: " << intToDouble << endl;
    
    int doubleToInt = static_cast<int>(doubleVal);
    cout << "double " << doubleVal << " -> int: " << doubleToInt << endl;
    
    float doubleToFloat = static_cast<float>(doubleVal);
    cout << "double " << doubleVal << " -> float: " << doubleToFloat << endl;
    
    double floatToDouble = static_cast<double>(floatVal);
    cout << "float " << floatVal << " -> double: " << floatToDouble << endl;
    
    int charToInt = static_cast<int>(charVal);
    cout << "char '" << charVal << "' -> int: " << charToInt << endl;
    
    char intToChar = static_cast<char>(intVal);
    cout << "int " << intVal << " -> char: '" << intToChar << "'" << endl;
    
    int boolToInt = static_cast<int>(boolVal);
    cout << "bool true -> int: " << boolToInt << endl;
    cout << "bool false -> int: " << static_cast<int>(false) << endl;
    cout << "int 0 -> bool: " << boolalpha << static_cast<bool>(0) << endl;
    cout << "int 2 -> bool: " << static_cast<bool>(2) << endl;
    
    return 0;
}