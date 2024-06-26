#ifndef FILMDB_H
#define FILMDB_H

#define DATABASE_PATH "movieDB.sqlite"

#include <QString>
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>

class FilmDb
{
public:
    FilmDb();
    ~FilmDb();


    QList<QString> get_good_films_of_genre(int rating, QString genre);
    QList<QString> get_films_of_genre_less_than(int time, QString genre);
    QList<QString> get_films_less_than(int time);
    int count_genre(QString genre);

private:
    QSqlDatabase db;

    void openDatabase();
    void closeDatabase();

    QList<QString> executeQuery(const QString &queryString, const QMap<QString, QVariant> &params);
    int executeScalarQuery(const QString &queryString, const QMap<QString, QVariant> &params);
};

#endif // FILMDB_H
