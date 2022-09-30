// Calculator.cpp - простой консольный калькулятор

#include <iostream>
#include <limits>

int enter_a_number(); //ввод чисел
char enter_action(); //ввод математического действия
int calculate(int a, int b, char ch); //функция которая будет производить математические действия и возвращать результат 

int main()
{
    int first_number; //первое число для калькулятора 
    int second_number; //второе число для калькулятора
    char action; //матетматическое действие
    int result = 0; //результат математических вычислений

    do
    {
        first_number = enter_a_number(); //Получаем первое число
        action = enter_action(); // Получаем арифметический знак
        if (action == 'q' || action == 'Q') // Проверяем наличие ключевого символва
        {
            break;
        }
        else if (action == 'c' || action == 'C') // Проверяем наличие ключевого символва
        {
            std::cout << "Clear!" << std::endl; // Очищаем результат согласно условию
            result = 0;
        }
        else
        {
            second_number = enter_a_number(); //Получаем второе число
            result += calculate(first_number, second_number, action); // Обновляем результат
        }
    } while (action != 'Q' && action != 'q'); //Повторяем действие пока не получим ключевое значение 

    std::cout << "Last result is " << result; //Выводим результат

    return 0;
}
int enter_a_number()
{
    int a; // Объявляем переменную 
    std::cout << "Enter a number: "; // Вывод сообщения на экран
    while (!(std::cin >> a)) // Получаем данные при вводе, проверяем что бы вводилось число
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //перебирает поток cin до переноса каретки и начинает  принимать новую информацию в поток
        std::cout << "Enter a number. Try again human: "; //выводит сообщение об ошибке
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // перебирает поток cin до переноса каретки и начинает  принимать новую информацию в поток
    return a;
}
char enter_action()
{
    char ch; // Объявляем переменную 
    std::cout << "Enter an action: ";// Вывод сообщения на экран
    std::cin >> ch; // Получаем данные при вводе
    while (ch != '-' && ch != '+' && ch != '*' && ch != '/' && ch != 'C' && ch != 'c' && ch != 'Q' && ch != 'q') // Проверяем правильность введенного значения
    {
        std::cout << std::cin.rdbuf()->in_avail();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //перебирает поток cin до переноса каретки и начинает  принимать новую информацию в поток
        std::cout << "Enter right action. Try again: "; // выводит сообщение об ошибке
        std::cin >> ch; 
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return ch;
}
int calculate(int a, int b, char ch)
{
    int res = 0; // Объявляем переменную 
    switch (ch) // С помощью данной конструкции делаем нужные арифметические действия 
    {
    case '-': res = a - b; std::cout << a << " - " << b << " = " << res << std::endl; break;
    case '+': res = a + b; std::cout << a << " + " << b << " = " << res << std::endl; break;
    case '*': res = a * b; std::cout << a << " * " << b << " = " << res << std::endl; break;
    case '/': res = a / b; std::cout << a << " / " << b << " = " << res << std::endl; break;
    default: std::cout << "Something goes wrong :(" << std::endl;
    }
    return res; // Возвращаем результат
}