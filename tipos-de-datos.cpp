#include<cassert>
//#include<iostream>
//#include<iomanip>
#include<string>
using namespace std::literals;

int main()
{
	assert(2==1+1);
	//prueba de tipo de dato bool
	assert(true);
    assert(false==false);
    assert(true!=false);
    assert(not false);
    assert(not false==true);
    assert(false or true);
    assert(true and true);
    assert(false or true and false==false);
    assert((false or true) and false==false);
    assert(true or true and false);
    //prueba de tipo de dato double
    assert(2.0==1.0+1.0);
    assert(0.1==1.0/10.0);
    assert(1==1.0);
    assert(2.0==1+1.0);
    assert(2==1+1.0);
    //assert(1.0 == 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
    //std::cout << std::setprecision(17) << 1.0/5.0 << '\n';
    //prueba de tipo de dato string
    assert("pacheco"s=="pa"s+"checo"s);
    assert("pacheco"s.length()==7); //length("pacheco")
    //prueba de tipo de dato char
    assert('a'+'p'=="ap"s);
    assert('b'+'e'=="be"s);
}