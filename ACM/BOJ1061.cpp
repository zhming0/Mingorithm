//
//  main.cpp
//  BJTU-ACM1061
//
//  Created by  on 11-10-4.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct Rect{
    int x1,y1,x2,y2;
}rect[2];
static bool isTouch(const Rect& r1, const Rect& r2)
{
    if (r1.x2<=r2.x1) return false;
    if (r1.x1>=r2.x2) return false;
    if (r1.y2<=r2.y1) return false;
    if (r1.y1>=r2.y2) return false;
    return true;
}
int main (int argc, const char * argv[])
{
    int x,y,l;
    while (~scanf("%d%d%d",&x,&y,&l)) {
        rect[0].x1=x;
        rect[0].x2=x+l;
        rect[0].y1=y;
        rect[0].y2=y+l;
        scanf("%d%d%d",&x,&y,&l);
        rect[1].x1=x;
        rect[1].x2=x+l;
        rect[1].y1=y;
        rect[1].y2=y+l;
        int ret=(rect[0].x2-rect[0].x1)*(rect[0].y2-rect[0].y1);
        ret+=(rect[1].x2-rect[1].x1)*(rect[1].y2-rect[1].y1);
        if (isTouch(rect[0], rect[1])) {
            Rect tmp;
            tmp.x1=max(rect[0].x1, rect[1].x1);
            tmp.x2=min(rect[0].x2, rect[1].x2);
            tmp.y1=max(rect[0].y1, rect[1].y1);
            tmp.y2=min(rect[0].y2, rect[1].y2);
            ret-=(tmp.x2-tmp.x1)*(tmp.y2-tmp.y1);
        }
        printf("%d\n",ret);
    }
    return 0;
}

