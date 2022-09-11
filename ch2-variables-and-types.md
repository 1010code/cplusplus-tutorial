# Variables and types
在上一章節的例子檔中我們輸出了一個 Hello World 句子。然而程式並不僅僅局限於在螢幕上印出簡單的字串。為了更進一步，並能夠編寫執行真正節省我們工作的有用任務的程式，我們需要引入變數的概念。假設我讓你們記住數字5，同時我也讓你們記住數字2。你剛剛在你的記憶中存儲了兩個不同的值(5和2)。現在，如果我讓你給我說的第一個數字加1，你應該在你的記憶中保留數字6(即5+1)和2。然後我們可以，減去這些值，結果應該會得到4。

```
a = 5;
b = 2;
a = a + 1;
result = a - b;
```

然而在 c++ 中每個變數都應該在宣告時添加型態，這些型態也稱為程式語言中的識別字。

## Identifiers
c++ 使用一些識別字來識別操作和數據描述;因此我們創建的變數不能重複這些關鍵字。以下為 c++ 中標准保留關鍵字:

```
alignas, alignof, and, and_eq, asm, auto, bitand, bitor, bool, break, case, catch, char, char16_t, char32_t, class, compl, const, constexpr, const_cast, continue, decltype, default, delete, do, double, dynamic_cast, else, enum, explicit, export, extern, false, float, for, friend, goto, if, inline, int, long, mutable, namespace, new, noexcept, not, not_eq, nullptr, operator, or, or_eq, private, protected, public, register, reinterpret_cast, return, short, signed, sizeof, static, static_assert, static_cast, struct, switch, template, this, thread_local, throw, true, try, typedef, typeid, typename,union, unsigned, using, virtual, void, volatile, wchar_t, while, xor, xor_eq
```

## Fundamental data types
- Character types 字元類型
- Numerical integer types 數字整數類型
- Floating-point types 浮點類型
- Boolean type 布林類型

## Declaration of variables
c++ 是一種強類型語言，要求每個變數在第一次使用之前都要聲明其類型。這將通知編譯器在記憶體中為變數保留的大小以及如何解釋它的值。c++ 中聲明新變數的語法很簡單，只需要在變數名後寫上類型即可(即它的標識字)。

```c
int a;
float mynumber;
```

如果要宣告多個相同類型的變數，則可以透過逗號分隔來宣告。

```c
int a, b, c;
```

以下為一個簡單的數學計算程式，呼應本章節一開始提到的範例：
```c
// operating with variables
#include <iostream>
using namespace std;
int main () {
  // declaring variables:
  int a, b;
  int result;
  // process:
  a = 5;
  b = 2;
  a = a + 1;
  result = a - b;
  // print out the result:
  cout << result;
  // terminate the program:
  return 0; 
}
```

## Initialization of variables
上述例子中的變數被宣告時，在第一次為它們賦值之前，它們都有一個未確定的值。但是變數是可以從被宣告的那一刻起就具有特定的值。這被稱為變數的初始化。在 c++ 中，有三種初始化變數的方法。

- 第一個被稱為 `C -like initialization`(因為它是從C語言繼承而來的)，它在變數初始化的值後面附加一個等號。
```c
int x = 0;
```

- 第二種方法稱為構造函數初始化(由c++語言引入)，將初始值括在圓括號 `()` 之間。
```c
int x (0);
```

- 第三種方法，稱為統一初始化，類似於上面的方法，但使用大括號 `{}` 而不是圓括號(這是在2011年c++標準的修訂版中引入的)
```c
int x {0};
```

因此在c++中，這三種初始化變量的方法都是有效且等價的。

```c
 
// initialization of variables
#include <iostream>
using namespace std;
int main () {
  int a=5;  // initial value: 5
  int b(3);  // initial value: 3
  int c{2};  // initial value: 2
  int result;  // initial value undetermined
  
  a = a + b;
  result = a - c;
  cout << result;
  return 0; 
}
```

> 在使用 macOS 或者 Linux 系統編譯的時候，要附加 c++11 標準，才可以編譯通過。
> gcc xxx.cpp -std=c++11

## Type deduction: auto and decltype