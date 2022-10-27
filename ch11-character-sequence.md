# Character sequences
在第二章節中已經介紹 string 複合類型建立一個字串變數。然而他其實是由一個字元型態的陣列所組成。以下為建立一個空間為20個字元的陣列。

```c
char foo [20];
```

我們也可以透過以下方法初始化字元陣列，若是以字元方式初始化必須在尾端結尾加上 `'\0'` 表示結束。

```c
char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
char myword[] = "Hello";
```

一旦變數已被宣告後，若要修改值不可以這樣寫：

```c
// 錯誤寫法
myword = "Bye";
myword[] = "Bye";
```

只能透過陣列索引逐一的修改內容。

```c
// 正確寫法
myword[0] = 'B';
myword[1] = 'y';
myword[2] = 'e';
myword[3] = '\0';
```

## Strings 類型
string 類型與字元陣列是可以互相轉換的。只要加上 `.c_str()` 就能成功的將 string 字串轉換成字元陣列。

```c
char myntcs[] = "some text";
string mystring = myntcs;  // convert c-string to string
cout << mystring;          // printed as a library string
cout << mystring.c_str();  // printed as a c-string
```

> c_str 和 string 的 data 是等價的