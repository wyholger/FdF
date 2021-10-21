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
```
./fdf test_maps/elem.fdf
```
![elem](https://github.com/wyholger/FdF/blob/main/gif/Screen_Shot_1.png?raw=true)
Мной был реализовано плавное перетекание от одного цветка к другому в зависимости от высоты, если эти цвета не заданы заранее в карте.


Так же допускается формат карты с заданными, или частично заданными цветами:
```
cat test_maps/mi.fdf
0,0x00CC00 0,0xFF7400 0,0x009999
0,0xFF0000 0,0xFFFF00 0,0xFF7400 
0,0x009999 0,0xFF0000 0,0x00CC00
```
```
./fdf test_maps/mi.fdf
```
![mi](https://github.com/wyholger/FdF/blob/main/gif/Screen_Shot_2.png?raw=true)
Где за координатой после запятой следует номер цвета в виде 16-ти ричного числа 10,0xffffff или 10,0xFFFFFF (первая пара символов отвечает за значение R, вторая за G, третья за B)


Так же есть возможность вращения карты по трем осям: 
![20_60](https://github.com/wyholger/FdF/blob/main/gif/20_60.gif?raw=true)
Она была реализована с помощью математической теории [матриц] поворота

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

[матриц]:https://ru.wikipedia.org/wiki/%D0%9C%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B0_%D0%BF%D0%BE%D0%B2%D0%BE%D1%80%D0%BE%D1%82%D0%B0#%D0%9C%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B0_%D0%BF%D0%BE%D0%B2%D0%BE%D1%80%D0%BE%D1%82%D0%B0_%D0%B2_%D1%82%D1%80%D1%91%D1%85%D0%BC%D0%B5%D1%80%D0%BD%D0%BE%D0%BC_%D0%BF%D1%80%D0%BE%D1%81%D1%82%D1%80%D0%B0%D0%BD%D1%81%D1%82%D0%B2%D0%B5
