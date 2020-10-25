# protein-DNA-binding-sites
分析蛋白質-DNA鍵結位置
## Description
利用蛋白質結構與DNA結構以及平移旋轉矩陣將蛋白質轉成適當位置，並計算蛋白質與DNA之間的距離,若距離小於4.5Å,則此胺基酸位置為蛋白質-DNA鍵結位置
## Getting Started
### Prerequisites
* 蛋白質結構檔(PDB format) [點此看範例](https://github.com/tomhsu2000/protein-DNA-binding-sites/tree/main/src)
* DNA結構檔(PDB format) [點此看範例](https://github.com/tomhsu2000/protein-DNA-binding-sites/tree/main/src)
* 平移旋轉矩陣 [點此看範例](https://github.com/tomhsu2000/protein-DNA-binding-sites/tree/main/src)
### Compile & Execute
``` 
$ g++ main.cpp
$ a.exe [蛋白質結構檔] [DNA結構檔] [平移旋轉矩陣]
```
## Roadmap

## Known Bugs
