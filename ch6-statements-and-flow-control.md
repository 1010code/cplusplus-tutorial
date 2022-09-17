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

當 while 判斷為真，則會執行該區塊內的程式。如果在任何語句執行後，表達式不再為真，則迴圈將結束。

### The do-while loop
do-while 迴圈與剛剛的 while 類似。差別在於 do-while 確保會進入區塊內執行一次，接著再判斷是否結束迴圈。

```c
// echo machine
#include <iostream>
#include <string>
using namespace std;
int main () {
  string str;
  do {
    cout << "Enter text: ";
    getline (cin,str);
    cout << "You entered: " << str << '\n';
  } while (str != "goodbye");
}
```

當語句需要至少執行一次時，例如當檢查迴圈結束的條件是在迴圈語句本身內確定時，通常首選do-while 迴圈而不 是 while 迴圈。在前面的例子中，區塊中的輸入將決定迴圈是否結束。因此，即使用戶想透過輸入 goodbye 來盡快結束迴圈，迴圈中的塊也需要至少執行一次，以提示輸入，而條件實際上只能在執行之後才能確定。

### The for loop
for 迴圈是最常見通用的方法，以下範例透過 for 迴圈執行十次。

```c
// countdown using a for loop
#include <iostream>
using namespace std;
int main () {
  for (int n=10; n>0; n--) {
    cout << n << ", ";
}
  cout << "liftoff!\n";
}
```

### Range-based for loop
for 迴圈還有另一種用法，用於 range 取值，以下範例將一個字串透過迴圈逐一取得字元。

```c
// range-based for loop
#include <iostream>
#include <string>
using namespace std;
int main () {
  string str {"Hello!"};
  for (char c : str)
  {
    cout << "[" << c << "]";
  }
  cout << '\n';
}
```

基於範圍的迴圈通常也會使用 auto 來推斷元素的類型。通常，上面範例也可以寫成:

```c
for (auto c : str)
  cout << "[" << c << "]";
```

## Jump statements
跳躍陳述式允後執行到特定位置的跳轉來改變程式的流程。

### The break statement
break 出現在迴圈中，可以直接中斷跳出迴圈並終止結束。例如，讓我們在它自然結束前停止倒計時:

```c
// break loop example
#include <iostream>
using namespace std;
int main () {
  for (int n=10; n>0; n--)
  {
    cout << n << ", ";
    if (n==3)
    {
      cout << "countdown aborted!";
      break; 
    }
  } 
}
```

## The continue statement
continue 會直接跳過當下迴圈的內容，並且直接重新進入迴圈的下一回合。

```c
// continue loop example
#include <iostream>
using namespace std;
int main () {
  for (int n=10; n>0; n--) {
    if (n==5) continue;
    cout << n << ", ";
}
  cout << "liftoff!\n";
}
```

## The goto statement
goto 允許程式執行到某行突然跳到某個區段。

```c
// goto loop example
#include <iostream>
using namespace std;
int main () {
  int n=10;
mylabel:
  cout << n << ", ";
  n--;
  if (n>0) goto mylabel;
  cout << "liftoff!\n";
}
```


## Another selection statement: switch.
switch 方法有點類似於 if...else。

```c
switch (x) {
  case 1:
    cout << "x is 1";
    break;
  case 2:
    cout << "x is 2";
    break;
  default:
    cout << "value of x unknown";
  }
```

等同於

```c
if (x == 1) {
  cout << "x is 1";
}
else if (x == 2) {
  cout << "x is 2";
}
else {
  cout << "value of x unknown";
}
```