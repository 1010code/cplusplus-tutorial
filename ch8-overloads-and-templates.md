# Overloads and templates
## Overloaded functions
這裡要討論函式的多載，也就是相同名稱的函式下透過參數的型態格式不同，並執行相對應的函式內容。以下為例當輸入兩個都是整數時，將會回傳相乘結果，若兩個參數都是浮點數則回傳兩數相除結果。

```c
// overloading functions
#include <iostream>
using namespace std;
int operate (int a, int b)
{
  return (a*b);
}
double operate (double a, double b)
{
  return (a/b);
}
int main () {
  int x=5,y=2;
  double n=5.0,m=2.0;
  cout << operate (x,y) << '\n';
  cout << operate (n,m) << '\n';
  return 0;
}
```

> 無法透過函式返回類型判斷多載

## Function templates 函式模板
首先我們來看以下例子有什麼缺點:

```c
// overloaded functions
#include <iostream>
using namespace std;
int sum (int a, int b)
{
  return a+b; 
}
double sum (double a, double b)
{
  return a+b; 
}
int main () {
  cout << sum (10,20) << '\n';
  cout << sum (1.0,1.5) << '\n';
  return 0;
}
```

當實作多載時函式內容都執行一樣內容時，可以建立一個模板避免重複的程式碼。在本例中，我們使用了 T 作為模板參數名並用了兩次函式模板 sum。第一次使用 int 類型的參數，第二次使用 double 類型的參數。編譯器已經實例化了函式，然後每次調用相應版本的函式。

```c
// function template
#include <iostream>
using namespace std;
template <class T>
T sum (T a, T b)
{
  T result;
  result = a + b;
  return result;
}
int main () {
  int i=5, j=6, k;
  double f=2.0, g=0.5, h;
  k=sum<int>(i,j);
  h=sum<double>(f,g);
cout << k << '\n';
  cout << h << '\n';
  return 0;
}
```

> 編譯器可以根據傳入參數自動去識別類型故 <int> 可省略

接下來在看另一個例子。樣板可以允許多種不同型態的參數，T 與 U 都可以隨意取。下面例子中使用了自動的模板參數推斷。

```c
// function templates
#include <iostream>
using namespace std;
template <class T, class U>
bool are_equal (T a, U b)
{
  return (a==b);
}
int main () {
  if (are_equal(10,10.0))
    cout << "x and y are equal\n";
else
    cout << "x and y are not equal\n";
  return 0;
}
```

因此下面兩種寫法都ㄧ樣：

```c
are_equal(10,10.0)
```

```c
are_equal<int,double>(10,10.0)
```

## Non-type template arguments
若知道型態的可以事先定義寫死。

```c
// template arguments
#include <iostream>
using namespace std;
template <class T, int N>
T fixed_multiply (T val)
{
  return val * N;
}
int main() {
  std::cout << fixed_multiply<int,2>(10) << '\n';
  std::cout << fixed_multiply<int,3>(10) << '\n';
}
```