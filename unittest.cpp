#include "unittest.h"
#include <QTest>
#include <filmdb.h>


UnitTest::UnitTest(QObject *parent) :
    QObject(parent) {

}
void UnitTest::TestCountGenreDrama()
{
    FilmDb db;
    QVERIFY(db.count_genre("Drama") == 77);
}
void UnitTest::TestCountGenreAction(){
    FilmDb db;
    QVERIFY(db.count_genre("Action") == 33);
}
void UnitTest::TestCountGenreAdventure(){
    FilmDb db;
    QVERIFY(db.count_genre("Adventure") == 43);
}
void UnitTest::TestCountGenreFantasy(){
    FilmDb db;
    QVERIFY(db.count_genre("Fantasy") == 7);
}
void UnitTest::TestCountGenreHorror(){
    FilmDb db;
    QVERIFY(db.count_genre("Horror") == 2);
}
void UnitTest::TestCountGenreCrime(){
    FilmDb db;
    QVERIFY(db.count_genre("Crime") == 11);
}
void UnitTest::TestCountGenreAnimation(){
    FilmDb db;
    QVERIFY(db.count_genre("Animation") == 13);
}
void UnitTest::TestCountGenreRomance(){
    FilmDb db;
    QVERIFY(db.count_genre("Romance") == 13);
}
void UnitTest::TestCountGenreBiography(){
    FilmDb db;
    QVERIFY(db.count_genre("Biography") == 21);
}
void UnitTest::TestCountGenreHistory(){
    FilmDb db;
    QVERIFY(db.count_genre("History") == 6);
}
