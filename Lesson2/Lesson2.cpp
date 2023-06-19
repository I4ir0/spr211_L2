#include <iostream>
#include <string>
using namespace std;

class Interests
{
public:
    Interests();     //constructor default
    Interests(string thing);    //constructor with parsms
    ~Interests();   //deconstructor
    string getThing();  //getter
    void setThing(string thing);    //setter

private:
    string thing;
};
class User
{
public:
    User():User{0, "" }//Delegate constructors
    {
        cout << "constructor default: " << typeid(this).name() << endl;
    }
    User(int id, string name):_id{id}, _name{name} //thish->_id=id///
    {
      _interests = nullptr;
      _size = 0;
       cout << "constructor with params: " << typeid(this).name() << endl;
    }
    ~User()
    {
        cout << "destructor: " << this << endl;
        delete[] _interests;

    }
private:
    int _id;
    string _name;
    Interests* _interests;
    int _size;
};
int main()
{
    User user(1,"Alex");


    system("pause");
    return 0;
}

Interests::Interests()
{
    cout << "constructor default: " << typeid(this).name() << endl;
}

Interests::Interests(string thing)
{
    this->thing = thing;
    cout << "constructor with param: " << typeid(this).name() <<  endl;
}

Interests::~Interests()
{
    cout << "deconstructor: " << typeid(this).name() <<  endl;

}

string Interests::getThing()
{
    return thing; //may this->thing
}

void Interests::setThing(string thing)
{
    this->thing = thing;
}
