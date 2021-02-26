#include <iostream>
#include <vector>
#include <algorithm>

typedef struct _Box_
{
    int x;
    int y;
    int w;
    int h;
    float confidence;
}Box;

bool SortFunction(Box box1, Box box2)
{
    return box1.confidence > box2.confidence ? true : false;
}

class Solution
{
public:
    std::vector<Box> BoxNms(std::vector<Box> &box_vector, float threshold)
    {
        std::sort(box_vector.begin(), box_vector.end(), SortFunction);
        std::vector<Box> result_vector;
        while(box_vector.size() > 0)
        {
            result_vector.push_back(box_vector[0]);
            int index = 1;
            while(box_vector.size() > index)
            {
                float iou = CalculationIou(box_vector[0], box_vector[index]);
                std::cout << "iou: " << iou << std::endl;
                if(iou > threshold)
                {
                    box_vector.erase(box_vector.begin()+index);
                }    
                else
                {
                    index++;
                }
            }
            box_vector.erase(box_vector.begin()); 
        }
        return result_vector;
    }
    
    float CalculationIou(Box box1, Box box2)
    {
        int x1 = std::max(box1.x, box2.x);
        int y1 = std::max(box1.y, box2.y);
        int x2 = std::min(box1.x+box1.w, box2.x+box2.w);
        int y2 = std::min(box1.y+box1.h, box2.y+box2.h);
        int over_area_w = std::max(0, x2-x1);
        int over_area_h = std::max(0, y2-y1);
        return (over_area_w*over_area_h)*1.0/(box1.w*box1.h+box2.w*box2.h-over_area_w*over_area_h);
    }
};

int main()
{
    std::vector<Box> box_vector;
    Box box1 = {0, 0, 1, 1, 0.8};
    Box box2 = {0, 0, 2, 2, 0.9};
    Box box3 = {1, 1, 2, 2, 0.92};
    Box box4 = {1, 1, 3, 3, 0.88};
    box_vector.push_back(box1);
    box_vector.push_back(box2);
    box_vector.push_back(box3);
    box_vector.push_back(box4);
    Solution solution;
    std::vector<Box> result_vector;
    result_vector = solution.BoxNms(box_vector, 0.1);
    for(auto vec = result_vector.begin(); vec != result_vector.end(); vec++)
    {
        printf("%d %d %d %d %f\n", vec->x, vec->y, vec->w, vec->h, vec->confidence);
    }
    return 0;
}
