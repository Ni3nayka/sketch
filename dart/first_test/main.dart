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
    dynamic name = "Tom"; // если хотим менять тип данных
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
    String info = "Name: $name  Age: $age \n";
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

  {
    int a = 20;
    int b = 8;
    double c = a / b; // 2.5
    print(c);
  }

  {
    // целочисленное деление
    int a = 33;
    int b = 5;
    // double c = a ~/ b; // низя ибо это int
    // int c = a / b; // и так низя ибо это float
    int c = a ~/ b; // 6
    int d = 22 ~/ 4; // 5
    print(c);
    print(d);
  }

  {
    // побитовые операции - такие же как в плюсах, кроме:
    int a = 12; // 0000 1100
    print(~a); //  1111 0011   или -13 - это типо '!' в плюсах
  }

  {
    // логические операции также как в плюсах, и прЕкол: (по поводу ~ и !)
    bool b = false;
    bool c;
    c = !b; // c равно true, если b равно false, иначе c будет равно false
    print(c);
  }

  {
    // краткие математические операции как в плюсах, кроме: (a+=b, a++)
    int c = 10, b = 4;
    //переменной c присваивается результат целочисленного деления c на b
    c ~/= b;
    print(c); // 2
  }

  {
    // логическое if такое же как в плюсах
    // switch-case - можно не использовать break, и вообще в case можно пустое поставить
    // тернарный оператор такой же как в плюсах (а = ...?...:...)
    // https://metanit.com/dart/tutorial/2.8.php

    // for while do...while - все как на плюсах

    // функции как в плюсах, но есть понт: (если в функции одно дейсвие)
    // void hello() => print("Hello!");

    // функции можно вкладывать в другие функции:

    // аргументы по умолчанию:
    void printPerson1(String name, [int age = 22]) {}
    // а если надо в age записать если что null:
    void printPerson2(String name, [int? age]) {}

    // а если надо вызвать по имени:
    void printPerson3({String? name = "undefined", int? age}) {
      // если что, у age будет null
      print("Name: $name");
      if (age != null) {
        print("Age: $age \n");
      }
    }

    printPerson3(age: 35);
    printPerson3(age: 29, name: "Alice");
    printPerson3(name: "Kate");

    // обязательные аргументы в таком случае: (required)
    // void printPerson({required String name, int age = 22}) {}

    // функции:
    // вообще так:
    // int sum(int a, int b) { return a + b; }
    // но можно сократить:
    // int sum(int a, int b) => a + b;
    // и убрать тип функции (сам допедрит по return или их отсутствию (для void)):
    // sum(int a, int b) => a + b;

    // также функциями можно оперировать как объектами: (как в питоне)
    // https://metanit.com/dart/tutorial/3.4.php

    // анонимные функции: (прикольная штука, можно как lambda в питоне использовать)
    // https://metanit.com/dart/tutorial/3.5.php

    // замыкание - грубо говоря локальный static + функция, мегакрутая штука
    // https://metanit.com/dart/tutorial/3.6.php
  }

  {
    // классы:
    // https://metanit.com/dart/tutorial/4.1.php
    // создание объекта класса Person:
    // class Person{ } // пустой класс Person, кстати создаются они только в global пространстве
    // Person tom = Person();
    // self (python) ~= this (Dart)

    // import 'person.dart'; // подключаем файл с классом Person

    // late - отложить инициализацию на потом (и чтобы без null)

    // Person? tom; // склепали null объект
    // tom.age = 38; // ошибка ибо объект null
    // tom?.age = 38; // не выполняется (за счет ? )

    // String? text; // null
    // ... return text!; // типо точно возвращаем String (не null)
  }
}
