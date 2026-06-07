
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
