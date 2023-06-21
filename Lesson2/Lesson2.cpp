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
    User() :User{ 0, "" }//Delegate constructors
    {
       // cout << "constructor default: " << typeid(this).name() << endl;
    }
    User(int id, string name) :_id{ id }, _name{ name } //thish->_id=id///
    {
        _interests = nullptr;
        _size = 0;
       // cout << "constructor with params: " << typeid(this).name() << endl;
    }
    ~User()
    {
       // cout << "destructor: " << this << endl;
        delete[] _interests;

    }
    void setInterests(Interests interests)
    {

        //_interests = new Interests[++_size];// + 1 in massive
        Interests* tempInterests = new Interests[_size]; 
        for (size_t i = 0; i < _size; i++)
            tempInterests[i] = _interests[i];

        if (_interests != nullptr)
            delete[] _interests;
        _interests = new Interests[(_size + 1)];
        for (size_t i = 0; i < _size; i++)
            _interests[i] = tempInterests[i];
        _interests[((++_size)-1)] = interests;
       
        delete[] tempInterests;
    }
    void print()
    {
        cout << "id: " << _id << endl;
        cout << "name: " << _name << endl;
        for (size_t i = 0; i < _size; i++)
        {
            cout << "Interest: " << _interests[i].getThing() << endl;
        }
    }
private:
    int _id;
    string _name;
    Interests* _interests;
    int _size;
};
    
    
    
    
    int main()
{
    User Alex(1,"Alex");
    Alex.setInterests(*new Interests("Football"));
    Alex.setInterests(*new Interests("XBOX 360"));
    Alex.setInterests(*new Interests("Developer c++"));
    Alex.print();
    cout << "---------------------" << endl;
    User Bob(2, "Bob");
    Bob.setInterests(*new Interests("Cards"));
    Bob.setInterests(*new Interests("Tenis"));
    Bob.print();
    cout << "---------------------" << endl;
    User Tom(3, "Tom");
    Tom.setInterests(*new Interests("Football"));
    Tom.setInterests(*new Interests("Sony playstation 5"));
    Tom.setInterests(*new Interests("Developer JavaScript"));
    Tom.setInterests(*new Interests("Films"));

    Tom.print();
    cout << "---------------------" << endl;


    system("pause");
    return 0;
}

Interests::Interests()
{
    //cout << "constructor default: " << typeid(this).name() << endl;
}

Interests::Interests(string thing)
{
    this->thing = thing;
   // cout << "constructor with param: " << typeid(this).name() <<  endl;
}

Interests::~Interests()
{
   // cout << "deconstructor: " << typeid(this).name() <<  endl;

}

string Interests::getThing()
{
    return thing; //may this->thing
}

void Interests::setThing(string thing)
{
    this->thing = thing;
}
