
## vcpkg 安裝
### 1. clone vcpkg 專案

```sh
git clone https://github.com/Microsoft/vcpkg.git
```

### 2. 執行 bootstrap
輸入以下指令以編譯 vcpkg。或是進入 vcpkg 資料夾右鍵以系統管理員身分執行。

```sh
.\vcpkg\bootstrap-vcpkg.bat
```


### 使用 vcpkg MSBuild
將 vcpkg 整合到 Visual Studio 中，之後 Visual Studio 或其他 IDE 就會自動偵測到 vcpkg 內的套件。

```sh
vcpkg integrate install
```

## Reference
- [vcpkg getting-started](https://vcpkg.io/en/getting-started.html)
- [用 vcpkg 安裝 C 或 C++ 函式庫](https://opensourcedoc.com/windows-programming/use-vcpkg-to-install-gtk-on-windows/)
- [學會vcpkg 套件管理器](https://ithelp.ithome.com.tw/articles/10221612)