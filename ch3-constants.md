# Constants
常數是具有固定值的的一種變數表達式。在前幾章中，我們已經使用了一些方法來給變數賦值或表示我們希望程序輸出的訊息。常量可以分為:整型、浮點型、字符型、字符串型、布爾型、指標型和用戶定義的文字型。

- Integer Numerals
  - 75         // decimal
  - 0113       // octal
  - 0x4b       // hexadecimal
- Floating Point Numerals
  -  3.14159    // 3.14159
  - 6.02e23    // 6.02 x 10^23
- Character and string literals
  - 字元用單引號 'p'
  - 字串用雙引號 "Hello world"
  - 在c++中，行尾的反斜杠 `\` 被認為是一個行延續字符，它將該行和下一行合併為一行。

```c
 x = "string expressed in \
two lines"
```

等同於：

```c
x = "string expressed in two lines"
```

- Other literals
  - c++ 中有三個關鍵字: true, false 和 nullptr。
  - 前兩個為布林值，最後一個是指標空值

```c
bool foo = true;
bool bar = false;
int* p = nullptr;
```

## Typed constant expressions
通常常數使用的時機是不希望被變動的。例如以下範例 pi 3.14 大家理所當然不變的事實。

```c
#include <iostream>
using namespace std;
const double pi = 3.14159;
const char newline = '\n';
int main ()
{
  double circle;
  circle = 2 * pi * r;
  cout << circle;
  cout << newline;
}
```

## Preprocessor definitions (#define)
另一種命名常數的機制是使用預處理器定義。它們有以下形式。在這個指令之後，程式碼中任何  `identifier` 的出現都被解釋為 `replacement`，替換是任何字符序列。這種替換由預處理器執行，並且發生在程序編譯之前，另外類型或語法的有效性不會以任何方式進行檢查。

```c
#define identifier replacement
```

```c
#include <iostream>
using namespace std;
#define PI 3.14159
#define NEWLINE '\n'
int main () {
  double r=5.0;
  double circle;
  circle = 2 * PI * r;
  cout << circle;
  cout << NEWLINE;
}
```

> 注意，#define行是預處理器指令，因此是單行指令——不像c++語句——不需要在末尾加上分號。