# Сокращатель ссылок

---

## Задание

### Обязательная часть

Добавление новой ссылки |
Получение длинной ссылки по короткому коду
Проверка существования короткого кода
Вывод всех сокращённых ссылок 

### Вариативная часть

Изменение длинной ссылки для существующего кода

---


### 1. Добавление ссылки

Пользователь вводит длинную ссылку и придумывает короткий код сам. Перед сохранением проверяется, что такой код ещё не занят — это выполняет требование вариативного пункта 1.

```python
elif choice == "1":
    url = input("Введите длинную ссылку: ").strip()
    code = input("Введите короткий код: ").strip()
    if code in storage:
        print(f"Код «{code}» уже занят.")
    else:
        storage[code] = url
        print(f"Сохранено: {code} -> {url}")
```

Пример работы:
```
Введите длинную ссылку: https://example.com/articles/python-basics
Введите короткий код: pyth
Сохранено: pyth -> https://example.com/articles/python-basics
```

---

### 2. Получение ссылки по коду

По введённому коду ищется длинная ссылка в словаре. Если код не найден — выводится сообщение об ошибке.

```python
elif choice == "2":
    code = input("Введите короткий код: ").strip()
    if code in storage:
        print(f"{code} -> {storage[code]}")
    else:
        print(f"Код «{code}» не найден.")
```

Пример работы:
```
Введите короткий код: pyth
pyth -> https://example.com/articles/python-basics
```

---

### 3. Вывод всех ссылок

Перебираются все пары из словаря и выводятся на экран. Если словарь пуст — выводится соответствующее сообщение. Проверка существования кода (обязательный пункт 3) встроена в пункты 2 и 4 меню.

```python
elif choice == "3":
    if not storage:
        print("Хранилище пусто.")
    else:
        for code, url in storage.items():
            print(f"{code} -> {url}")
```

Пример работы:
```
pyth -> https://example.com/articles/python-basics
docs -> https://docs.python.org/3/
```

---

### 4. Изменение ссылки (вариативный пункт 9)

Пользователь вводит существующий короткий код, видит текущую ссылку и вводит новую. Если код не найден — выводится ошибка.

```python
elif choice == "4":
    code = input("Введите короткий код: ").strip()
    if code not in storage:
        print(f"Код «{code}» не найден.")
    else:
        print(f"Текущая ссылка: {storage[code]}")
        new_url = input("Введите новую ссылку: ").strip()
        storage[code] = new_url
        print("Ссылка обновлена.")
```

Пример работы:
```
Введите короткий код: pyth
Текущая ссылка: https://example.com/articles/python-basics
Введите новую ссылку: https://example.com/articles/python-advanced
Ссылка обновлена.
```

---

## Полный код

```python
storage = {}

while True:
    print("\n1 — Добавить ссылку")
    print("2 — Получить ссылку по коду")
    print("3 — Показать все ссылки")
    print("4 — Изменить ссылку по коду")
    print("0 — Выход")

    choice = input("\nВыберите действие: ").strip()

    if choice == "0":
        print("До свидания!")
        break

    elif choice == "1":
        url = input("Введите длинную ссылку: ").strip()
        code = input("Введите короткий код: ").strip()
        if code in storage:
            print(f"Код «{code}» уже занят.")
        else:
            storage[code] = url
            print(f"Сохранено: {code} -> {url}")

    elif choice == "2":
        code = input("Введите короткий код: ").strip()
        if code in storage:
            print(f"{code} -> {storage[code]}")
        else:
            print(f"Код «{code}» не найден.")

    elif choice == "3":
        if not storage:
            print("Хранилище пусто.")
        else:
            for code, url in storage.items():
                print(f"{code} -> {url}")

    elif choice == "4":
        code = input("Введите короткий код: ").strip()
        if code not in storage:
            print(f"Код «{code}» не найден.")
        else:
            print(f"Текущая ссылка: {storage[code]}")
            new_url = input("Введите новую ссылку: ").strip()
            storage[code] = new_url
            print("Ссылка обновлена.")

    else:
        print("Неизвестная команда.")
```
