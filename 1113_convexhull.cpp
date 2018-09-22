#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
/*
3 0
0 3
4 0
0 0

*/
struct point{
    double x, y;
    point(){

    }
    point (double _x, double _y){
        x = _x;
        y = _y;
    }
    point operator -(const point &b) const{
        return point(x - b.x, y - b.y);
    }
};

int left_turn(point p1, point p2, point p3){
    double res = (p2.y - p1.y) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.y - p1.y);
    if (res == 0)
        return res;
    else
        return res < 0 ? -1:1;
}

bool cmp(point p1, point p2){
    double res = p1.y * p2.x - p1.x * p2.y;// if res < 0 p1 goes before p2 (counter-clockwise)
    if (res == 0){
        return (p1.x * p1.x + p1.y * p1.y < p2.x * p2.x + p2.y * p2.y);
    }else{
        return (res < 0);
    }
}
double get_hull_length(struct point* p, int N){
    int min_y = p[0].y;
    int min_index = 0;
    for (int i = 0; i < N; i++){
        if (p[i].y < min_y){
            min_y = p[i].y;
            min_index = i;
        }
    }
    swap(p[min_index], p[0]);
    for (int i = 1; i < N; i++){
        p[i] = p[i] - p[0];
    }
    p[0] = p[0] - p[0];
    sort (&p[1], &p[1] + N - 1, cmp);
    // for (int i = 0; i < N; i++){
    //     printf("(%lf, %lf) ", p[i].x, p[i].y);
    // }
    // printf("\n");
    int m = 2;
    for (int i = 2; i < N; i++){
        while (m > 1 && left_turn(p[m - 2], p[m - 1], p[i]) >= 0)
            m--;
        p[m] = p[i];
        m++;
    }
    double distance = 0;
    // printf("%s\n", "Convex Hull:");
    // for(int i = 0; i < m; i++)
    //     printf("(%lf, %lf) ", p[i].x, p[i].y);
    // printf("\n");
    for (int i = 0; i < m; i++){
        distance += sqrt((p[(i + 1)%m].x - p[i].x) * (p[(i + 1)%m].x - p[i].x)\
             +  (p[(i + 1)%m].y - p[i].y) *  (p[(i + 1)%m].y - p[i].y));
    }
    return distance;
}
int main(){
    int N, L;
    while(scanf("%d %d", &N, &L) != EOF){
        struct point* p = new struct point[N];
        for (int i = 0; i < N; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        double length = get_hull_length(p, N);
        double PI=acos(-1.0);
        length += 2 * PI * L;
        printf("%d\n", int(length + 0.5));
    }
    return 0;
}
