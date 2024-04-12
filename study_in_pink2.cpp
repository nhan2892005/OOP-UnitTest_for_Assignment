#include "study_in_pink2.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
//Ở file cpp, để định nghĩa các phương thức ta hiện thực như sau
//Ví dụ class MapElements
MapElement::MapElement(ElementType in_type) 
    : type(in_type) {}

MapElement::~MapElement() 
{
    return;
}

ElementType MapElement::getType() const 
{
    return type;
}

Path::Path() 
    : MapElement(ElementType::PATH) {}

Path::~Path()
{
    return;
}

Wall::Wall()
    : MapElement(ElementType::WALL) {}

Wall::~Wall()
{
    return;
}

FakeWall::FakeWall(int in_req_exp)
    : MapElement(ElementType::FAKE_WALL), req_exp(in_req_exp) {}

FakeWall::~FakeWall()
{
    return;
}

int FakeWall::getReqExp() const 
{
    return req_exp;
}

//..... Các hàm tiếp theo các bạn tự hiện thực
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////