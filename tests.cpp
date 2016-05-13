#include <QCoreApplication>

#include <QtTest/QtTest>

#include <algorithm>
#include <iterator>
#include <vector>

class Tests: public QObject
{
    Q_OBJECT

private slots:
    void sortTest();
    void reverseSortTest();
    void bogoSortTest();
    void findTest();
    void replaceTest();
};

void Tests::sortTest()
{
    std::vector<int> vector;
    vector.push_back(3);
    vector.push_back(1);
    vector.push_back(2);

    std::sort(vector.begin(), vector.end());

    QVERIFY(1 == vector.at(0) && 2 == vector.at(1) && 3 == vector.at(2));
}

bool reverse (int i,int j)
{
    return (i>j);
}

void Tests::reverseSortTest()
{
    std::vector<int> vector;
    vector.push_back(3);
    vector.push_back(1);
    vector.push_back(2);

    std::sort(vector.begin(), vector.end(), reverse);

    QVERIFY(3 == vector.at(0) && 2 == vector.at(1) && 1 == vector.at(2));
}

void Tests::bogoSortTest()
{
    std::vector<int> vector;
    vector.push_back(3);
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(4);

    int timeout = 0;
    while(!std::is_sorted(vector.begin(), vector.end()) && timeout++ < 1000000)
    {
        std::random_shuffle(vector.begin(), vector.end());
    }

    QVERIFY(timeout < 1000000);
    QVERIFY(1 == vector.at(0) && 2 == vector.at(1) && 3 == vector.at(2) && 4 == vector.at(3));
}

void Tests::findTest()
{
    std::vector<int> vector;
    vector.push_back(3);
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(4);

    // find1 looks to see if there is a 2 in the list
    // and find2 should check if there is a 5 in the list
    std::vector<int>::const_iterator find1 = std::find(vector.begin(), vector.end(), 2);
    std::vector<int>::const_iterator find2 = std::find(vector.begin(), vector.end(), 5);

    QVERIFY(vector.end() != find1 && 2 == *find1 && vector.end() == find2);
}

void Tests::replaceTest()
{
    std::vector<int> vector;
    vector.push_back(1);
    vector.push_back(3);
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(2);
    vector.push_back(2);
    vector.push_back(4);

    std::vector<int>::iterator find = std::find(vector.begin(), vector.end(), 2);
    while (vector.end() != find)
    {
        *find = 3;
        find = std::find(vector.begin(), vector.end(), 2);
    }

    int numberOfThrees = std::count(vector.begin(), vector.end(), 3);

    QVERIFY(6 == numberOfThrees && 9 == vector.size());
}


QTEST_MAIN(Tests)
#include "tests.moc"
