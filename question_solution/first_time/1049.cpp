// author: Lan_zhijiang
// description: 海上救援队
#include <cstdio>
#include <cstring>
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
struct record {
    int x, y;
    int step;
};
record list[410000];
int map[1100][1100], sx, sy, ex, ey;
bool v[410000], reach = false;

