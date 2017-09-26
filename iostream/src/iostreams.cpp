#include <fstream>
#include <iostream>
#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "boost/archive/text_iarchive.hpp"

using namespace std;

class Person;

namespace boost
{
    namespace serialization
    {
        template <class archive>
        void serialize(archive &ar, Person &p, unsigned int version);
    }
}

class Person {
    public:
        Person(){}
        ~Person(){}
        Person(int j)
        {
            for (int i = 0; i < 4; i++)
                v.push_back(j);
        }
        int getAge()
        {
            return (age);
        }
        char *getName()
        {
            return (name);
        }
        std::vector<int> getV()
        {
            return (v);
        }
        void setAge(int age)
        {
            this->age = age;
        }
        void setName(std::string name)
        {
            strcpy(this->name, name.c_str());
        }
        int printVector();
        void vectorToMat4();
        void mat4ToVector();
        void printMatrix(std::string s);
        void assignMatrix(int flag);

    private:
        int age;
        char name[8];
        glm::mat4 rot;
        std::vector<int> v;
        template <class archive> friend
        void boost::serialization::serialize(archive &ar, Person &p, unsigned int version);
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
            ar & p.v;
        }
    }
}

/*
** mat4 = {0, 1, 2, 3}
**        {0, 1, 2, 3}
**        {0, 1, 2, 3}
**        {0, 1, 2, 3}
*/

void Person::assignMatrix(int flag)
{
    if (!flag)
    {
        for (int i = 0; i < 4; i ++)
        {
            for (int j = 0; j < 4; j++)
                rot[i][j] = 0;
        } 
    }
    else
    {
        for (int i = 0; i < 4; i ++)
        {
            for (int j = 0; j < 4; j++)
                rot[i][j] = j + i;
        }
    }
}

void Person::printMatrix(std::string s)
{
    for (int i = 0; i < 4; i ++)
    {
        if (i == 1)
            cout << s.c_str() << ".rot = {";
        if (i != 1)
            cout << "         {";
        for (int j = 0; j < 4; j++)
        {
            cout << rot[i][j];
            if (j != 3)
                cout << ", ";
        }
        cout << "}" << endl;
    }
}

void Person::mat4ToVector()
{
    int len = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int  j = 0; j < 4; j++)
        {
            len++;
            v.push_back(rot[i][j]);
        }
    }
    v.push_back(len);
}

void Person::vectorToMat4()
{
    int iv = 0;
    int len = v.back();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0 && iv < len; j < 4; j++)
        {
            rot[i][j] = v[iv++];
        }
    }
}

int Person::printVector()
{
    int i = 0;
    int len = v.back();

    if (!v.size())
    {
        cout << "vector is empty" << endl;
        return (1);
    }
    cout << "v = {";
    while (i < len)
    {
        cout << v[i];
        if (i < (len - 1))
            cout << ", ";
        i++;
    }
    cout << "}" << endl;
    return (0);
}

bool isEmpty(ifstream &iFile)
{
    if (iFile.peek() == ifstream::traits_type::eof())
        return (1);
    return (0);
}

int main(void)
{
    Person p2(0);
    Person p;
    vector<int> vec;
    int arr[4] = {1, 0, 4, 5};
    ofstream ofs("gamedata.zem");
    ifstream ifs("gamedata.zem");

    //============== Person 1 ==================
    //============= assignment ================= 
    p.setAge(19);
    p.assignMatrix(1);
    p.setName("Samuelle");
    p.mat4ToVector();
    //=============== print ==================== 
    p.printMatrix("p1");
    cout << "" << endl;
    p.printVector();
    cout << "" << endl;
    //==========================================
    if (ofs.is_open())
    {
        boost::archive::text_oarchive oa(ofs);
        oa & p;
    }
    //============== Person 2 ==================
    //============= assignment =================    
    p2.setAge(0);
    p2.setName("");
    p2.assignMatrix(0);
    cout << "" << endl;
    // //=============== print ==================== 
    p2.printMatrix("p2");
    cout << "" << endl;
    p2.printVector();
    cout << "" << endl;
    //==========================================

    if (ifs.is_open())
    {
        boost::archive::text_iarchive ia(ifs);
        ia & p2;
    }
    //=============== print ====================
    p2.vectorToMat4();
    p2.printMatrix("p2");
    cout << "" << endl;
    p2.printVector();
    //==========================================
    return (0);
}