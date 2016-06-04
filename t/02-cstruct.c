#include <stdio.h>

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
typedef long long int64_t;
#define PF "0x%p"
#else
#define DLLEXPORT extern
#include <stdint.h>
#define PF "%p"
#endif

typedef struct point3d_t {
    int64_t x;
    int64_t y;
    int64_t z;
} Point3D;

typedef struct  {
    char * name;
    int64_t numpoints;
    Point3D * points;
    char * version;
} Point3DList;


DLLEXPORT char *myaddr(Point3D *points) {
    static char buff[20];
    sprintf(buff, PF, points);
    return buff;
}

DLLEXPORT char *shown(Point3D *arr, int idx) {
    static char buff[100];
    sprintf(buff, "x:%lld, y:%lld, z:%lld", arr[idx].x, arr[idx].y, arr[idx].z);
    return buff;
}

DLLEXPORT Point3DList * bunchapoints() {
  static char * name = "My Point3D List";
  static char * version = "0.0.0.0.0.0.0.0";
  static Point3DList list;
  static Point3D points[4];
  for(int i = 0; i <4; i++) {
    points[i].x = points[i].y = points[i].z = i;
  }

  list.name = name;
  list.numpoints = 4;
  list.points = points;
  list.version = version;

  return &list;
}
