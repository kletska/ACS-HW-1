# Первое домашнее задание по десциплине "Архитектура вычислительных систем"

## Автор
Литвинский Семён Алексеевич

Вариант 20

Номер задания 6

Номер функции 2

Оба гитхаба (kletska, montaglue) мои, при необходимости доказательства я предоставлю

## Сборка

1. создать папку `./bin`
2. инициализировать `cmake` командой `cmake .` (0,595s)
3. собрать с помощью `cmake` командой `cmake --build .` (2,387s)
4. в папке `./bin` будет лежать исполняемый файл `task01` 

## Входные данные
Входные данные для элементов контейнера должны быть
словом или числом, при чем, значение совпадать по типу с соответствующим параметром обьекта
и не быть диннее 8 символов, так например:

```
plainnnnn 100 100 100 100      ❌
plain abacaba 100 100 100      ❌
plaan 100 100 100 100          ✅
plain 100 100 100 100          ✅
```

### Ограничение на числа
Допускаются только положительные целые числа.
Диапазон чисел от $1$ (включительно) до $10^9$ (не включительно)

### Ограничение на слова
Слова могут состоять из сторчных и заглавных букв латинскиого алфавита а так же цифр
 
```
plain: 100 100 100 100     ❌
pLain3 100 100 100 100     ✅
```
### неопределенное поведение
Нарушение любого из правил выше выдет к неопределенному поведнию, а имнно снимает с программы любую ответсвенность.

## Невалидные обьекты
Несмотря на достаточно жестки правила, все еще ввод является достаточно свободным, однако, если строка на соответсвует шаблону (таким, как ```plain train ship liner ...```), то поведение программы определенно. Создастся нвалидный обьект, который позже будет проигнорирован.
## key
При невалидном ```key``` программа не считывает дальнейшие поля обьекта.

## ship kind
При невалидном ```ship_kind``` весть обьект ```ship``` становится невалидным.

## Комментарии
Я сократил количество комментариев по сравнению с образцом, ибо большинство из них повторяло содержание кода и не несло ничего нового, что является плохой практикой. Однако, для единсва стиля часть таковых пришлось оствить.

Так же теперь в комментариях содержится достаточно важная информация, большая просьба с ними ознакомиться.