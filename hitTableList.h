//
// Created by muharem on 6/28/26.
//

#ifndef TEST_HITTABLELIST_H
#define TEST_HITTABLELIST_H
#include "hitTable.h"

#include <vector>


class hitTableList: public hitTable
{
public:
    std::vector<shared_ptr<hitTable>>objs;
    hitTableList(){}
    hitTableList(shared_ptr<hitTable>obj)
    {
        add(obj);
    }
    void clear()
    {
        objs.clear();
    }
    void add(shared_ptr<hitTable>obj)
    {
        objs.push_back(obj);

    }
    bool hit(const ray& r, interval rayT, hitRecord& rec)const override
    {

        hitRecord tempRec;
        bool hitAnything= false;
        auto closestSoFar=rayT.max;
        for (const auto& obj:objs)
        {
            if (obj->hit(r,interval(rayT.min,closestSoFar),tempRec))
            {
                hitAnything=true;
                closestSoFar=tempRec.t;
                rec=tempRec;
            }
        }
        return hitAnything;
    }




};

#endif //TEST_HITTABLELIST_H