# Statements and flow control
一個程式中會有多行程式碼，每行都以分號(;)做結尾表示陳述句的結束。並且程式執行順序是逐行的依序被執行。但是程式在執行過程中並非每行都會被執行，C++ 提供了流程控制語法可以在指定的的地方跳耀執行符合條件的內容。

## Selection statements: if and else
以下程式碼片段只在 x 變數中存儲的值確實是100時才會印出訊息，如果 x 不等於100，則忽略此語句，不打印任何內容。

```c
if (x == 100)
  cout << "x is 100";
```

如果你想在條件滿足時包含多個要執行的語句，這些語句應該用大括號 `{}` 括起來，形成一個 block:

```c
if (x == 100) {
   cout << "x is ";
cout << x; }
```

帶有 if 的選擇語句還可以通過使用 els e關鍵字引入替代語句來指定在條件未滿足時將發生什麼。如果 x 的值確實為 100，則輸出 `x is 100`，但如果不是 100，僅當不是 100 時，輸出 `x is not 100`。

```c
 if (x == 100)
  cout << "x is 100";
else
  cout << "x is not 100";
```

判斷式也可以很多，透過 `else if` 進行多個判斷。透過連接兩個 `if-else` 結構輸出 x 是正、負還是零。同樣，通過將它們分組到用大括號括起來的塊中:`{}`，也可以在 每個case中執行多個語句。

```c
if (x > 0)
  cout << "x is positive";
else if (x < 0)
  cout << "x is negative";
else
  cout << "x is 0";
```

## teration statements (loops)
迴圈顧名思義是重複執行某段程式 N 次，可以節省重複的程式碼一再出現。程式語言中迴圈不外乎有下面這三種：while、do 和 for。

### The while loop
最簡單的是 while 迴圈。它的語法是:

```c
// custom countdown using while
#include <iostream>
using namespace std;
int main () {
int n = 10;
  while (n>0) {
    cout << n << ", ";
    --n;
}
  cout << "liftoff!\n";
}
```