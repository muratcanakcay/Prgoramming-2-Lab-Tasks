
#include "list.h"

int main()
    {
    int x, c;

    cout << endl << "***** Part I *****" << endl << endl ;

    List L1;
    cout << "Empty list" << endl;
    cout << L1 << endl;
    cout << endl;

    L1.PushBack(5);
    L1.PushBack(10);
    L1.PushBack(-2);
    L1.PushBack(3);
    cout << "L1 list" << endl;
    cout << L1 << endl;

    List L2(L1);
    cout << "L2 list" << endl;
    cout << L2 << endl;
    cout << endl;

    x = L2.Get();
    cout << "x = " << x << endl;
    cout << "L2 list" << endl;
    cout << L2 << endl;
    L1.PushBack(8);
    cout << "L1 list" << endl;
    cout << L1 << endl;
    cout << endl;

    List L3(L2);
    x = L2.Get();
    cout << "x = " << x << endl;
    cout << "L2 list" << endl;
    cout << L2 << endl;
    L3.PushBack(12);
    cout << "L3 list" << endl;
    cout << L3 << endl;
    cout << endl;

    List L4;
    List L5(L4);
    cout << "L5 list" << endl;
    cout << L5 << endl;

    L1 = L3;
    cout << "L1 list" << endl;
    cout << L1 << endl;

    x = L1.Get();
    cout << "x = " << x << endl;
    cout << "L1 list" << endl;
    cout << L1 << endl;
    L3.PushBack(7);
    cout << "L3 list" << endl;
    cout << L3 << endl;
    cout << endl;

    L1 = L5 = L4;
    cout << L1 << endl;
    cout << endl;

    x = L2.Get();
    cout << "x = " << x << endl;
    x = L2.Get();
    cout << "x = " << x << endl;
    x = L2.Get();
    cout << "x = " << x << endl;
    x = L2.Get();
    cout << "x = " << x << endl;
    cout << "L2 list" << endl;
    cout << L2 << endl;
    L2.PushBack(6);
    cout << "L2 list" << endl;
    cout << L2 << endl;

    cout << endl << "***** Part II *****" << endl << endl ;

    cout << "L3 list" << endl;
    cout << L3 << endl;
    cout << "L3.At(0): " << L3.At(0) << endl;
    cout << "L3.At(3): " << L3.At(3) << endl;
    cout << "L3.At(4): " << L3.At(4) << endl;
    cout << "L3.At(5): " << L3.At(5) << endl;
    cout << "L3.At(-1): " << L3.At(-1) << endl;

    cout << endl;

    cout << "L3.Max(): " << L3.Max() << endl;
    cout << "L2.Max(): " << L2.Max() << endl;
    cout << "L4.Max(): " << L4.Max() << endl;

    cout << endl;

    cout << "L4 list" << endl;
    cout << L4 << endl;
    L4.PushFront(3);
    cout << L4 << endl;
    L4.PushBack(5);
    cout << L4 << endl;
    L4.Get();
    L4.PushFront(7);
    cout << L4 << endl;
    L4.PushBack(2);
    cout << L4 << endl;

    cout << endl << "***** Part III *****" << endl << endl ;

    List L31;
    for ( int i=1 ; i<=10 ; ++i )
        L31.PushBack(i);
    cout << L31 << endl;
    cout << L31.SubList(-1,5) << endl;
    cout << L31.SubList(2,-3) << endl;
    cout << L31.SubList(12,5) << endl;
    cout << L31.SubList(5,0) << endl;
    cout << L31.SubList(0,3) << endl;
    cout << L31.SubList(4,5) << endl;
    cout << L31.SubList(7,15) << endl;

    cout << endl << "***** Part IV *****" << endl << endl ;

    List L41;
    List L42(L2);
    List L43(L3);
    L41.Reverse();
    cout << "L41 list" << endl;
    cout << L41 << endl;
    L42.Reverse();
    cout << "L42 list" << endl;
    cout << L42 << endl;
    L43.Reverse();
    cout << "L43 list" << endl;
    cout << L43 << endl;
    L43.PushBack(4);
    cout << "L43 list" << endl;
    cout << L43 << endl;

    cout << endl << "***** Part V *****" << endl << endl ;

    List L51;
    L51.PushBack(15);
    L51.PushBack(5);
    L51.PushBack(7);
    L51.PushBack(10);
    cout << L51 << endl;
    x = L51.GetMax();
    cout << "x = " << x << endl;
    cout << L51 << endl;
    x = L51.GetMax();
    cout << "x = " << x << endl;
    cout << L51 << endl;
    L51.PushBack(3);
    cout << L51 << endl;
    x = L51.GetMax();
    cout << "x = " << x << endl;
    cout << L51 << endl;
    x = L51.GetMax();
    cout << "x = " << x << endl;
    cout << L51 << endl;
    L51.PushBack(6);
    cout << L51 << endl;
    x = L51.GetMax();
    cout << "x = " << x << endl;
    cout << L51 << endl;
    x = L51.GetMax();
    cout << "x = " << x << endl;
    cout << L51 << endl;
    L51.PushBack(8);
    cout << L51 << endl;
    x = L51.GetMax();
    cout << "x = " << x << endl;
    cout << L51 << endl;
    x = L51.GetMax();
    cout << "x = " << x << endl;
    cout << L51 << endl;
    L51.PushBack(2);
    cout << L51 << endl;

    cout << endl << "***** Part VI *****" << endl << endl ;

    List L61;
    L61.PushBack(7);
    L61.PushBack(12);
    L61.PushBack(10);
    L61.PushBack(5);
    L61.PushBack(8);
    L61.PushBack(10);
    L61.PushBack(10);
    L61.PushBack(15);
    L61.PushBack(3);
    cout << L61 << endl;

    c = L61.Remove(3);
    cout << "removed " << c <<" element(s)" << endl;
    L61.PushBack(1);
    cout << L61 << endl;

    c = L61.Remove(7);
    cout << "removed " << c <<" element(s)" << endl;
    cout << L61 << endl;

    c = L61.Remove(5);
    cout << "removed " << c <<" element(s)" << endl;
    cout << L61 << endl;

    c = L61.Remove(10);
    cout << "removed " << c <<" element(s)" << endl;
    cout << L61 << endl;

    cout << endl;

    List L62;
    L62.PushBack(5);
    L62.PushBack(5);
    L62.PushBack(5);
    L62.PushBack(5);
    cout << L62 << endl;
    c = L62.Remove(5);
    cout << "removed " << c <<" element(s)" << endl;
    cout << L62 << endl;
    L62.PushBack(9);
    cout << L62 << endl;

    return 0;
    }
