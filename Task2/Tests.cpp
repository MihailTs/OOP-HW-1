#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Vector.h"

TEST_CASE("Test basic vector operations"){
    Vector<int> v;
    for(int i = 0; i < 12; i++)
        v.push(i);

    CHECK(v.getSize() == 12);

    v.remove();
    CHECK(v.getElements()[0] == 0);

    v.removeSubarray(2, 4);
    CHECK(v.getSize() == 8);
}

TEST_CASE("Test others"){
    Vector<int> v;
    for(int i = 0; i < 12; i++)
        v.push(i);

    Vector<int> v2;
    for(int i = 20; i < 30; i++)
        v2.push(i);

    Vector<int> v3 = v+v2;
    CHECK(v3.getSize() == 22);
    CHECK(v3.getElements()[20] == 28);

    v3.map([](int x) -> int{return 2*x;});
    CHECK(v3.getElements()[20] == 56);

    Vector<int> v4 = v3.getSubarray(5, 20);
    CHECK(v4.getSize() == 16);
    CHECK(v4[15] == 56);

}