#include <fstream>
#include <iostream>
#include <string>
#include "boost/archive/text_oarchive.hpp"
#include "boost/archive/text_iarchive.hpp"

using namespace std;

class Person {
    public:
        int age;
        char name[8];
    private:
};

namespace boost
{
    namespace serialization
    {
        template <class archive>
        void serialize(archive &ar, Person &p, unsigned int version)
        {
            ar & p.name;
            ar & p.age;
        }
    }
}

bool isEmpty(ifstream &iFile)
{
    if (iFile.peek() == ifstream::traits_type::eof())
        return (1);
    return (0);
}

int main(void)
{
    Person p;
    Person p2;
    ofstream ofs("gamedata.zem");
    ifstream ifs("gamedata.zem");
    
    p.age = 19;
    strcpy(p.name, "Samuelle");
    // ofs.close();
    // if (!ifs.is_open())
    //     cout << "file failed to open" << endl;
    // else
    // {
    //     if (isEmpty(ifs))
    //         cout << "file is empty" << endl;
    //     else
    //         cout << "file is not empty" << endl;
    // }
    if (ofs.is_open())
    {
        boost::archive::text_oarchive oa(ofs);
        oa & p;
    }
    p2.age = 0;
    strcpy(p2.name, "");
    cout << p2.age << endl;
    if (ifs.is_open())
    {
        boost::archive::text_iarchive ia(ifs);
        ia & p2;
    }
    cout << p2.age << endl;
    return (0);
}