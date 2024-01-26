// https://metanit.com/dart/tutorial/

void main() {
  print("Hello METANIT.COM!");
  {
    // так тоже можно
    print("Hello!");
    print("Welcome to Dart!");
  }

  {
    String name = "Tom";
    print(name);
    name = "Bob";
    print(name);
  }

  {
    var name = "Tom"; // типо сам поймет что это String
    print(name);
    //name = 45; // Ошибка!!! name представляет строки, а не целые числа
  }

  {
    dynamic name = "Tom";
    print(name);
    name = 45;
    print(name);
  }

  {
    const String name = "Tom"; // тип указывать не обязательно
    // const String name = "Tom"; // так тоже можно
    print(name); // Tom
    //name =  "Bob";    // Ошибка - значение константы нельзя изменять!
    final name1 = "Tom"; // ре-декларация запрещена
    print(name1); // Tom
    //name =  "Bob";    // Ошибка - значение константы нельзя изменять!
    final today = DateTime.now();
    // final - определяется в момент запуска программы (даже если скомпилирована)
    print(today);
    // const today = DateTime.now();   // ! Ошибка, константы определяются на этапе компиляции
    // print(today);
  }

  {
    // 1 подставить не можем...неявные преобразования как в с++ не работают
    bool yes = true;
    bool no = false;
    print(yes);
    print(no);
  }

  {
    // задавать можно и через var:
    int x = 8; // 64 бит (обычно)
    double x1 = 8.8; // 64 бит
    double x2 = 8; // x = 8.0
    String tom = "Tom"; // UTF-16
    String sam = 'Sam';
    // многострочные строки
    var multiline = '''
Многострочная
строка
    ''';
    print(multiline);
    String text = """
Высокой страсти не имея
Для кода жизни не щадить,
Не мог он джаву от сишарпа,
Как мы ни бились, отличить.
    """;
    print(text);
  }

  {
    // интерполяция:
    String name = "Tom";
    int age = 35;
    String info = "Name: $name  Age: $age";
    print(info);
  }

  {
    // оператор ?
    String name; // нет никакого значения
    // print(name); // ошибка, т.к. name = null (что-то типа None)
    name = "Tom";
    print(name);
    // но если прям очень надо использовать null, то:
    String? name1;
    print(name1); // null
    name1 = "Tom";
    print(name1); // Tom
    name1 = null;
    print(name1); // null
  }

  {
    // оператор ??
    int? num1;
    //int num2 = num1; // ошибка, ибо в num2 нельзя записать null
    num1 = 23;
    int num2 = num1 ?? 0; // записать значение ИЛИ 0 (если null)
    print(num2); // 23
    num1 = null;
    num2 = num1 ?? 0;
    print(num2); // 0
  }

  {
    // Иногда встречаются ситуации, когда переменной надо присвоить значение, если только она равна null
    int? a;
    a = a ?? 10;
    print(a); // 10
    // или
    int? b;
    b ??= 10;
    print(b); // 10
    // еще пример
    int? c = 1;
    c ??= 10;
    print(c); // 1
  }
}
