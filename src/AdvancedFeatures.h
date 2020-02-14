#include <iostream>
#include <utility>
#include <memory>

namespace AdvancedFeatures{
void move_semantics(){
    std::vector<int> myBigVec(10000000, 2011);
    std::vector<int> myVec;

    std::cout << "size before move: source "<< myBigVec.size() <<", dest "<< myVec.size()<<std::endl;
    //myVec = myBigVec;             // copy semantic
    myVec = std::move(myBigVec);  // move semantic
    std::cout << "size after move: source "<< myBigVec.size() <<", dest "<< myVec.size()<<std::endl;
}
///////////////////////////////////////////////////////
struct UniqInt{
    UniqInt(int i):i_(i){}
    ~UniqInt(){
        cout << "Good bye from " << i_ << endl;
    }
    int i_;
};

void uniq_ptr(){
    using namespace std;
    unique_ptr<UniqInt> uniquePtr1{new UniqInt(1998)};
    cout << uniquePtr1.get() << endl;               // 0x15b5010

    unique_ptr<UniqInt> uniquePtr2{move(uniquePtr1)};
    cout << uniquePtr1.get() << endl;               // 0
    cout << uniquePtr2.get() << endl;               // 0x15b5010
    {
        unique_ptr<UniqInt> localPtr{new UniqInt(2003)};
    }                                               // Good bye from 2003
    uniquePtr2.reset(new UniqInt(2011));              // Good bye from 1998
    UniqInt* myInt= uniquePtr2.release();
    delete myInt;                                   // Good by from 2011

    unique_ptr<UniqInt> uniquePtr3{new UniqInt(2017)};
    unique_ptr<UniqInt> uniquePtr4{new UniqInt(2022)};
    cout << uniquePtr3.get() << endl;               // 0x15b5030
    cout << uniquePtr4.get() << endl;               // 0x15b5010

    swap(uniquePtr3, uniquePtr4);
    cout << uniquePtr3.get() << endl;               // 0x15b5010
    cout << uniquePtr4.get() << endl;               // 0x15b5030
}
///////////////////////////////////////////////////////
class SharedInt{
    public:
        SharedInt(int v):val(v){
            std::cout << "Hello: " << val << std::endl;
        }
        ~SharedInt(){
            std::cout << "Good Bye: " << val << std::endl;
        }
    private:
        int val;
};

void shared_pointer(){
    auto sharPtr= std::make_shared<SharedInt>(1998);        // Hello: 1998
    std::cout << sharPtr.use_count() << std::endl;      // 1

    {
        std::shared_ptr<SharedInt> locSharPtr(sharPtr);
        std::cout << locSharPtr.use_count() << std::endl; // 2
    }
    std::cout << sharPtr.use_count() << std::endl;      // 1

    std::shared_ptr<SharedInt> globSharPtr= sharPtr;
    std::cout << sharPtr.use_count() << std::endl;      // 2

    globSharPtr.reset();
    std::cout << sharPtr.use_count() << std::endl;     // 1
    sharPtr= std::shared_ptr<SharedInt>(new SharedInt(2011));  // Hello:2011                                                   // Good Bye: 1998
    // Good Bye: 1998
    // Good Bye: 2011
} 


void Run(){
    //move_semantics();
    //uniq_ptr();
    shared_pointer();
}


} // end namespace
