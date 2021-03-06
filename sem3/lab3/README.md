## Лабораторная работа 3. Обработка строк.

### :red_circle: Задача 1 

Реализовать указанные строковые функции. При реализации этих функций запрещается использовать любые стандартные функции.

1. strpbrk :white_check_mark:
2. strspn
3. strcspn
4. strchr
5. strrchr
6. strdup
7. strndup

Эта задача подразумевает только реализацию указанных функций и модульных тестов к ним (т.е. никакого отдельного приложения для работы с реализованными функциями можно не писать). 
При этом в модульных тестах нужно сравнить поведение своей функции и соответствующей стандартной.

*Замечание 1.*
Функция `strdup` становится доступной только при указании стандарта gnu99 (т.е. `–std=gnu99`).

*Замечание 2.*
Функция `strndup` в библиотеке компилятора `MinGW` не реализована.

### :red_circle: Задача 2 

Необходимо реализовать следующие функции:

1. Чтения строки из текстового файла. Строка должна читаться целиком (т.е. до символа EOL или EOF) за один проход. Реализация с помощью выделения большого буфера и чтения за один раз не принимается.
2. Замены в строке указанной непустой подстроки произвольной длины на другую подстроку произвольной длины (возможно пустую).

С помощью реализованных функций обработать текстовый файл, в котором выполнить замену всех вхождений указанной подстроки на заданную. Преобразованные строки записать в новый файл.

*Пример.*
В строке "aaaa" заменяем подстроку "aa" на "bbb". После замены получаем "bbbbbb".

Все параметры передаются как аргументы командной строки.
Интересующиеся могут дополнительно реализовать различные опции (например, поиск нечувствительный к регистру символов, обработка только слов и т.п.) и/или нетривиальный алгоритм поиска подстроки в строке (алгоритмы Кнута-Мориса-Прата, Боуера-Мура, Рабина-Карпа).
