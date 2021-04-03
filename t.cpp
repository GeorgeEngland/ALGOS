#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <functional>
#include <algorithm>
using namespace std;

class WaterSystem {
    public:
    virtual ~WaterSystem(){cleanup();}
    virtual void cleanup(){
        cout<<"ws clean"<<endl;
    }
    
};
class Pump: public WaterSystem{
    public:
    virtual void cleanup(){
        cout<<"pump clean"<<endl;
        WaterSystem::cleanup();
    }
};

class v{
    public:
     ~v(){cout<<"v"<<endl;}
};
class e{
    public:
     ~e(){cout<<"e"<<endl;}
};
class t : public v{
    public:
     ~t(){cout<<"t"<<endl;}
     private:
     e thee;
};

int acc(const vector<int> &v, const unsigned int index){
    if(index>=v.size()){throw std::out_of_range("i too");}
    return v[index];
}
template<typename T, typename U>
bool cam(const T& lhs, const U& rhs){
    return lhs>rhs;
}
int main(){
    vector<int> my = {1,2,3};
    cam(true,false);
    vector<pair<int,int>> pairs{{1,9},{3,4},{1,2},{2,4}};
    vector<int> v{1,2,3,5,2,2,6,2,3};
    sort(pairs.begin(),pairs.end(),[]( auto & a, auto & b)->bool{return a.first<b.first;});
    cout<<"ascending";
    return 0;
}