#include <QCoreApplication>
#include <QTest>
#include <unittest.h>
#include <QDebug>
#include <filmdb.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTest::qExec(new UnitTest, argc, argv);
    qDebug() << "\n";

    FilmDb db;

    // Фильмы жанра экшн и оценкой 7 и выше
    std::cout << "\nAction films with grade 7 and above:\n";
    for (const QString &title : db.get_good_films_of_genre(7, "Action")) {
        std::cout << title.toStdString() << std::endl;
    }

    // Фильмы жанра комедия, 100 и меньше минут
    std::cout << "\nComedy films less than 100 min:\n";
    for (const QString &title : db.get_films_of_genre_less_than(100, "Comedy")) {
        std::cout << title.toStdString() << std::endl;
    }

    // Количество фильмов жанра фэнтези
    int fantasyCount = db.count_genre("Fantasy");
    std::cout << "\nCount of fantasy films: " << fantasyCount << "\n";


    // Фильмы длительностью 90 и меньше минут
    std::cout << "\nFilms less than 90 min:\n";
    for (const QString &title : db.get_films_less_than(90)) {
        std::cout << title.toStdString() << std::endl;
    }


    return a.exec();
}
