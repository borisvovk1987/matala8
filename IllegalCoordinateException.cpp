#include"IllegalCoordinateException.h"

std::ostream& operator<<(std::ostream& out ,const IllegalCoordinateException &illegalCord)
{

    out<<illegalCord.m_row<<","<<illegalCord.m_col;
    return out;

}
