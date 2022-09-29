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
        first_number = enter_a_number();
        action = enter_action();
        if (action == 'q' || action == 'Q')
        {
            break;
        }
        else if (action == 'c' || action == 'C')
        {
            std::cout << "Clear!" << std::endl;
            result = 0;
        }
        else
        {
            second_number = enter_a_number();
            result += calculate(first_number, second_number, action);
        }
    } while (action != 'Q' && action != 'q');

    std::cout << "Last result is " << result;

    return 0;
}


int enter_a_number()
{
    int a;
    std::cout << "Enter a number: ";
    while (!(std::cin >> a))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a number. Try again human: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return a;
}

char enter_action()
{
    char ch;
    std::cout << "Enter an action: ";
    //if (std::cin.rdbuf()->in_avail() != 1))
    std::cin >> ch;
    while (ch != '-' && ch != '+' && ch != '*' && ch != '/' && ch != 'C' && ch != 'c' && ch != 'Q' && ch != 'q')
    {
        std::cout << std::cin.rdbuf()->in_avail();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter right action. Try again: ";
        std::cin >> ch;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return ch;
}

int calculate(int a, int b, char ch)
{
    int res = 0;
    switch (ch)
    {
    case '-': res = a - b; std::cout << a << " - " << b << " = " << res << std::endl; break;
    case '+': res = a + b; std::cout << a << " + " << b << " = " << res << std::endl; break;
    case '*': res = a * b; std::cout << a << " * " << b << " = " << res << std::endl; break;
    case '/': res = a / b; std::cout << a << " / " << b << " = " << res << std::endl; break;
    default: std::cout << "Something goes wrong :(" << std::endl;
    }
    return res;
}