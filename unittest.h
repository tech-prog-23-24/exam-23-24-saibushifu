#ifndef UNITTEST_H
#define UNITTEST_H

#include <QObject>

class UnitTest : public QObject
{
    Q_OBJECT
public:
    explicit  UnitTest(QObject *parent = 0);

private slots:
    void TestCountGenreDrama();
    void TestCountGenreAction();
    void TestCountGenreAdventure();
    void TestCountGenreFantasy();
    void TestCountGenreHorror();

    void TestCountGenreCrime();
    void TestCountGenreAnimation();
    void TestCountGenreRomance();
    void TestCountGenreBiography();
    void TestCountGenreHistory();
};

#endif // UNITTEST_H
