//
// Created by muharem on 6/28/26.
//
//test comment
#ifndef TEST_HITTABLELIST_H
#define TEST_HITTABLELIST_H
#include "hitTable.h"
#include <memory>
#include <vector>
using std::make_shared;
using std::shared_ptr;

class hitTableList: public hitTable
{
public:
    std::vector<shared_ptr<hitTable>>objs;
    hitTableList();
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
    bool hit(const ray& r, double rayTmin, double rayTmax, hitRecord& rec)const override
    {
        hitRecord tempRec;
        bool hitAnything= false;
        auto closestSoFar=rayTmax;
        for (const auto& obj:objs)
        {
            if (obj->hit(r,rayTmin,closestSoFar,tempRec))
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