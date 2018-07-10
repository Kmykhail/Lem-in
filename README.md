# Lem-in
Lem-in is a something kind of game about ant farm. Goal of this project is find the shortest path from start room to the end
# How it's work
At the begining program will receive some data:
1) Number of ants:
      - Only positive number;
2) The rooms:
      - The rooms defined by: [name room] [coord_x] [coord_y];
      - Name room will never start with the character L or space;
      - The room's coordinates will always be integers and should not be identical;
3) The links:
      - links are defined by: [name1]-[name2];
4) Comments:
      - Comments "##start" and "##end" are provided to show the start and end room information;
      - We don't care about any other comments.
For a full review see https://github.com/Kmykhail/Lem-in/blob/master/lem-in.en.pdf

<img width="142" alt="example" src="https://user-images.githubusercontent.com/31519926/42514779-df2fce1a-8462-11e8-9d5a-40b43229e54d.png">

# Compiling
```
$> make
```
# Usage
```
$> ./lem-in < maps/[some map]
```
