#include "datadef.h"
#include "utils.h"
#include <QDebug>
#include <QString>

QString strDrawbackType(int type){
    QString str = "";
    switch(type){
    case DRAWBACK_NONE:
        str = "none";break;
    case DRAWBACK_BROKEN:
        str = "open";break;
    case DRAWBACK_SHORT:
        str = "short"; break;
    case DRAWBACK_GAP:
        str = "mousebite"; break;
    case DRAWBACK_BURR:
        str = "spur";break;
    case DRAWBACK_CROPPER:
        str = "copper"; break;
    case DRAWBACK_HOLE:
        str = "pinhole"; break;
    default:
        str = "undefined";
    }
    return str;
}
