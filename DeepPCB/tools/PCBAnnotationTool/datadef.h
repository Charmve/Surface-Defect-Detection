#ifndef DATADEF
#define DATADEF
#include <QString>

const int DRAWBACK_NONE = 0;
const int DRAWBACK_BROKEN = 1;  // 断路
const int DRAWBACK_SHORT = 2; // 短路
const int DRAWBACK_GAP = 3; // 缺口
const int DRAWBACK_BURR = 4; // 毛刺
const int DRAWBACK_CROPPER = 5; // 露铜
const int DRAWBACK_HOLE = 6;  // 针孔

struct DrawbackInfo{
    int x1_;
    int y1_;
    int x2_;
    int y2_;
    int type_;
    DrawbackInfo(int x1=-1, int y1=-1, int x2=-1, int y2=-1, int type=-1):
        x1_(x1), y1_(y1), x2_(x2), y2_(y2), type_(type){}
    DrawbackInfo(const DrawbackInfo& info):
        x1_(info.x1_), y1_(info.y1_), x2_(info.x2_), y2_(info.y2_), type_(info.type_){}
};


#endif // DATADEF

