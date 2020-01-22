#include <iostream>

class CRoleSomeMgr
{
public:
    CRoleSomeMgr() { std::cout << "CRoleSomeMgr created" << std::endl; }
    ~CRoleSomeMgr() { std::cout << "CRoleSomeMgr destreyed" << std::endl; }
    int value = 100;
};

class CRole
{
public:
    CRole(CRoleSomeMgr & oSomeMgr) : m_oSomeMgr(oSomeMgr) {}
    ~CRole() { std::cout << "CRole destroyed" << std::endl; }
private:
    CRoleSomeMgr m_oSomeMgr;
};

int main() {
    std::cout << "ref decstruct test" << std::endl;
    CRoleSomeMgr oSomeMgr;
    {
        CRole oRole { oSomeMgr };
        std::cout << "ref decstruct on bracket end" << std::endl;
    }
    std::cout << "some holds " << oSomeMgr.value << std::endl;
    std::cout << "ref decstruct on program end" << std::endl;
}