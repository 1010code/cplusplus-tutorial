# Name visibility
變數又分為全域變數和區域變數。我們來看以下範例：

```c
int foo;        // global variable
int some_function()
{
  int bar;      // local variable
  bar = 0; 
}
int other_function()
{
  foo = 1;  // ok: foo is a global variable
  bar = 2;  // wrong: bar is not visible from this function
}
```

我們可以得知 `other_function()` 是無法存取到 `some_function()` 裡面的 bar 變數。而 foo 變數卻可以，因為他被宣告在全域。

另外在每個區塊中一個變數名稱只能被定義成一個實體。例如，在同一區域中不能有兩個同名的變數:

```c
int some_function ()
{
  int x;
  x = 0;
  double x;
  x = 0.0;
}
```

以下例子中在不同的區塊被執行將會存取到不同變數內容：

```c
// inner block scopes
#include <iostream>
using namespace std;
int main () {
  int x = 10;
  int y = 20;
  {
    int x;   // ok, inner scope.
    x = 50;  // sets value to inner x
    y = 50;  // sets value to (outer) y
cout << "inner block:\n";
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';
  }
  cout << "outer block:\n";
  cout << "x: " << x << '\n';
  cout << "y: " << y << '\n';
  return 0;
}
```

輸出結果：
```
inner block:
x: 50
y: 50
outer block:
x: 10
y: 50
```

## Namespaces 命名空間
我們可以為變數或函式給予一個命名空間。所謂的命名空間主要是避免名稱的衝突。在本例中，有兩個同名的函式:value。一個在命名空間foo中定義，另一個在bar中定義。兩個函式並各自執行不同的內容。

```c
// namespaces
#include <iostream>
using namespace std;
namespace foo
{
  int value() { return 5; }
}
namespace bar
{
  const double pi = 3.1416;
  double value() { return 2*pi; }
}
int main () {
  cout << foo::value() << '\n';
  cout << bar::value() << '\n';
  cout << bar::pi << '\n';
  return 0;
}
```

執行結果：
```
5
6.2832
3.1416
```

### using
使用 using 可以簡化一些操作，不必在每次呼叫功能時在前面添加命名空間。以下範例在 main 中透過 using 聲明將 x 指向 `first::x`，以及將 y 指向 `second::y`。

```c
 
// using
#include <iostream>
using namespace std;
namespace first
{
int x = 5;
int y = 10; }
namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}
int main () {
  using first::x;
  using second::y;
  cout << x << '\n';
  cout << y << '\n';
  cout << first::y << '\n';
  cout << second::x << '\n';
  return 0;
}
```

輸出結果：
```
5
2.7183
10
3.1416
```

關鍵字 using 也可以作為一個指令來引入整個命名空間:

```c
// using
#include <iostream>
using namespace std;
namespace first
{
  int x = 5;
  int y = 10; 
}
namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}
int main () {
  using namespace first;
  cout << x << '\n';
  cout << y << '\n';
  cout << second::x << '\n';
  cout << second::y << '\n';
  return 0; 
}
```

執行結果：
```
5
10
3.1416
2.7183
```

## The std namespace
std 是 C++ 標準庫的一個命名空間。

```c
std::cout << "Hello world!";
```

## Storage classes 儲存類別
在以下範例中 x y 都沒有給予初值，在全域變數中編譯器將會自動給 0。但是在 main 區塊中可能會是 0 或任意數值。

```c
// static vs automatic storage
#include <iostream>
using namespace std;
int x;
int main () {
  int y;
  cout << x << '\n';
  cout << y << '\n';
  return 0;
}
```