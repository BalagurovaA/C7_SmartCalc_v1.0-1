# SmartCalc v1.0

Реализация приложения калькулятор на языке C.

Помимо базовых арифметических операций, калькулятор обладает возможностью вычисления арифметических выражений с учетом приоритетов, а также некоторыми математическими функциями (синус, косинус, логарифм и т.д.). Помимо вычисления выражений калькулятор так же  поддерживает использование переменной _x_ и построение графика соответствующей функции. В качестве дополнительных улучшений можно присутствуют кредитный и депозитный калькуляторы.

<br> <img src="./view/calc1.png" alt="Differentiated_calc" width="600" />

## Содержание
- [Арифметические операции и математические функции](#арифметические-операции-и-математические-функции)
    - [Дополнительно. Кредитный калькулятор](#дополнительно-кредитный-калькулятор)

- [Технологии](#технологии)
- [Использование](#использование)
- [Разработка](#разработка)
- [Тестирование](#тестирование)

## Арифметические операции и математические функции

- На вход программы могут подаваться как целые числа, так и вещественные числа, записанные через точку;
- Вычисление  производится после полного ввода вычисляемого выражения и нажатия на символ `=`;
- Вычисление произвольных скобочных арифметических выражений в инфиксной нотации;
- Вычисление произвольных скобочных арифметических выражений в инфиксной нотации с подстановкой значения переменной _x_ в виде числа;
- Построение графика функции, заданной с помощью выражения в инфиксной нотации с переменной _x_ (с координатными осями, отметкой используемого масштаба и сеткой с адаптивным шагом);
- Область определения и область значения функций ограничиваются по крайней мере числами от -1000000 до 1000000;
    - Для построения графиков функции указываются отображаемые область определения и область значения;
- Проверяемая точность дробной части - 7 знаков после запятой;
- У пользователя есть возможность ввода до 255 символов;
- Скобочные арифметические выражения в инфиксной нотации должны поддерживать следующие арифметические операции и математические функции:
    - **Арифметические операторы**:

        | Название оператора | Инфиксная нотация <br /> (Классическая) | Префиксная нотация <br /> (Польская нотация) |  Постфиксная нотация <br /> (Обратная польская нотация) |
        | ------ | ------ | ------ | ------ |
        | Скобки | (a + b) | (+ a b) | a b + |
        | Сложение | a + b | + a b | a b + |
        | Вычитание | a - b | - a b | a b - |
        | Умножение | a * b | * a b | a b * |
        | Деление | a / b | / a b | a b \ |
        | Возведение в степень | a ^ b | ^ a b | a b ^ |
        | Остаток от деления | a mod b | mod a b | a b mod |
        | Унарный плюс | +a | +a | a+ |
        | Унарный минус | -a | -a | a- |

        >Оператор умножения содержит обязательный знак `*`.

    - **Функции**:
  
        | Описание функции | Функция |   
        | ---------------- | ------- |  
        | Вычисляет косинус | cos(x) |   
        | Вычисляет синус | sin(x) |  
        | Вычисляет тангенс | tan(x) |  
        | Вычисляет арккосинус | acos(x) | 
        | Вычисляет арксинус | asin(x) | 
        | Вычисляет арктангенс | atan(x) |
        | Вычисляет квадратный корень | sqrt(x) |
        | Вычисляет натуральный логарифм | ln(x) | 
        | Вычисляет десятичный логарифм | log(x) |

### Дополнительно. Кредитный калькулятор

Предусмотри специальный режим «кредитный калькулятор» (за образец можно взять сайты banki.ru и calcus.ru):
 - Вход: общая сумма кредита, срок, процентная ставка, тип (аннуитетный, дифференцированный);
 - Выход: ежемесячный платеж, переплата по кредиту, общая выплата.

<br> <img src="./view/calc3.png" alt="Differentiated_calc" width="600" />|<br> <img src="./view/calc2.png" alt="Differentiated_calc" width="600" />

## Технологии
- С
- Qt
- C++
- Check.h
- Makefile

## Использование 
1. Для установки проекта необходимо склонировать репозиторий, перейти в папку `./C_SmartCalc/src`

2. Скомпилировать и запустить проект: 
```sh
make
```
или 

```sh
make all
```
или
```sh
make rebuld
```
или
```sh
make install
```
При вводе данной команды проект компилируется, запускаются тесты, открывается html страница, отображающая покрытие тестами, а также создается папка `build`, в которой находится рабочее приложение

3. Запуск тестов
```sh
make test
``` 
4. Открыть документацию
```sh
make test
``` 
5. Сделать архив, содержащий в себе папку всего проекта вместе с приложением
```sh
make dist
``` 
6. Удалить приложение
```sh
make uninstall
``` 
7. Отображение покрытия тестами
```sh
make gcov_report
```
8. Запуск unit-тестов
```sh
make check
```
9. Очистка проекта
```sh
make clean
```
## Разработка

### Требования
- `gcc`
- `make`
- `qmake`

- Программа разработана на языке С стандарта C11 с использованием компилятора gcc. 
- Присутсвует использование дополнительных библиотек и модулей QT Creator version 6.2;
- Код программы находится в папке src; 
- Сборка программы настроена с помощью Makefile со стандартным набором целей для GNU-программ: all, install, uninstall, clean, dvi, dist, test, gcov_report;
- Программа разработана в соответствии с принципами структурного программирования;
- Реализация придерживаться Google Style;
- Реализация с графическим пользовательским интерфейсом, на базе любой GUI-библиотеки с API для C89/C99/C11: QT
- Makefile для сборки приложения и тестов


## Тестирование
- Присутствует полное покрытие unit-тестами функций библиотеки c помощью библиотеки `Check.h`
- Unit-тесты проверяют результаты работы реализации путём сравнения ее с реализацией стандартной библиотеки math.h
- Unit-тесты покрывают около 90% каждой функции
- В цели gcov_report формируется отчёт gcov в виде html страницы. Для этого unit-тесты запускаются с флагами gcov

### Причина разработки данного проекта
Учебное задание в Школе 21 от Сбера








