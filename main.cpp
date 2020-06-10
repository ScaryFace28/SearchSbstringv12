#include <iostream>
#include "reader.h"
#include "tester.h"
using namespace std;

void test(const string& d1, const string& d2) {
    Tester ts(d1, d2, simon+);
    ts.test();

    Tester ta(d1, d2, HORSPOOL);
    ta.test();

    Tester tt(d1, d2, turbo);
    tt.test();
}

int main() {
    try {
        test("data/data00.txt", "data/data01.txt");
        test("data/data10.txt", "data/data11.txt");
        test("data/data20.txt", "data/data21.txt");
        test("data/data30.txt", "data/data31.txt");
    }
    catch (std::exception& ex) {
        cerr << ex.what() << endl;
    }
}
