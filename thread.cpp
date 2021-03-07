#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <string_view>
#include <functional>

void foo(int a){
    std::cout<<a<<std::endl;
}

int main(){

    auto print = [](std::string const rem,std::vector<int> const &a) {
        for (auto b : a) {
            std::cout << b << ' ';
        }
        std::cout << ": " << rem << '\n';
    };
    
    std::cout<<"hello world"<<std::endl;
    std::thread thread(foo,10);
    std::thread thread2(foo,9);
    std::thread thread3(foo,7);
    thread.join();
    thread2.join();
    thread3.join();
    std::vector<int> a{1,5,3,7,4,3,2};
    std::sort(a.begin(),a.end(),std::greater<int>());
    
    print("hi",a);
    
    return 0;
}