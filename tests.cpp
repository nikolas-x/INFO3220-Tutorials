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

    // need to sort the vector

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

    // need to sort the vector in descending order

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
        // shuffle the vector in a random order. If we keep trying we are bound
        // to get it sorted right???
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
    std::vector<int>::const_iterator find1 = vector.end();
    std::vector<int>::const_iterator find2 = vector.end();

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

	// need to update find
    std::vector<int>::const_iterator find = vector.end();
    while (vector.end() != find)
    {
        // repalce all 2s with 3s and then update find
    }

    int numberOfThrees = std::count(vector.begin(), vector.end(), 3);

    QVERIFY(6 == numberOfThrees && 9 == vector.size());
}


QTEST_MAIN(Tests)
#include "tests.moc"
