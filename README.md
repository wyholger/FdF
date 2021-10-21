# FdF
FdF это мой первый графический проект. Написан на Си, с использованием графической библиотеки mlx.
![FdF](https://github.com/wyholger/FdF/blob/main/gif/qwe.gif?raw=true)
FdF отрисовывает карты заданные ему в аргументе.
Пример формата карты:
```
cat elem.fdf
0  0  0  0  0  0  0  0  0  0
0 10 10 10 10 10 10 10 10  0
0 10 20 15 12 15 17 20 10  0
0 10 15 10 12 15 15 15 10  0
0  5 15 10 12 15 15 13 10  0
0  5 10  5  7 12 12 12 10  0
0  5  7  1  2  7  5  5  7  0
0  3  0  0  1  2  2  2  5  0
0  1  0  0  0  0  0  0  3  0
0  0  0  0  0  0  0  0  0  0
```
Где значения 0, 10, 15... Это значения высоты точки, а позиция этого значения относительно левого и верхнего края это x, y координаты точки.
Так же допускается формат карты с заданными, или частично заданными цветами:
```
cat mi.fdf
-200,0xE13142 -50,0x1E8C8C -200,0xE13142
-50,0xc8c100 100 -50,0xc8c100
-50,0x0007c8 100 -50,0x0007c8
-200,0x45C22A -50,0xBC2979 -200,0x45C22A
```
Где за координатой после запятой следует номер цвета в виде 16-ти ричного числа 10,0xffffff или 10,0xFFFFFF (первая пара символов отвечает за R, вторая за G, третья за B)
## Сборка на macOS
```
git clone https://github.com/wyholger/FdF.git FdF
```
```
cd FdF
```
```
make
```
## Использование 
`./fdf test_maps/42.fdf` или `./fdf [The_path_to_your_map]`
