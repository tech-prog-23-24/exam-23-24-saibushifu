#include "filmdb.h"
#include <QDebug>
#include <QMap>
#include <QVariant>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QList>

FilmDb::FilmDb() {
    openDatabase();
}

FilmDb::~FilmDb() {
    closeDatabase();
}

void FilmDb::openDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_PATH);

    if (!db.open()) {
        qDebug() << "Ошибка открытия базы:" << db.lastError().text();
    }
}

void FilmDb::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

QList<QString> FilmDb::executeQuery(const QString &queryString, const QMap<QString, QVariant> &params) {
    QList<QString> result;
    QSqlQuery query(db);
    query.prepare(queryString);

    for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    if (query.exec()) {
        while (query.next()) {
            result.append(query.value(0).toString());
        }
    } else {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
    }

    return result;
}

int FilmDb::executeScalarQuery(const QString &queryString, const QMap<QString, QVariant> &params) {
    QSqlQuery query(db);
    query.prepare(queryString);

    for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    } else {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return 0;
    }
}

QList<QString> FilmDb::get_good_films_of_genre(int rating, QString genre) {
    QString queryString = R"(
        SELECT IMDB.Title
        FROM IMDB
        JOIN genre ON IMDB.Movie_id = genre.Movie_id
        WHERE genre.genre = :genre AND IMDB.Rating >= :rating
    )";
    QMap<QString, QVariant> params;
    params[":genre"] = genre;
    params[":rating"] = rating;

    return executeQuery(queryString, params);
}


QList<QString> FilmDb::get_films_of_genre_less_than(int time, QString genre) {
    QString queryString = R"(
        SELECT IMDB.Title
        FROM IMDB
        JOIN genre ON IMDB.Movie_id = genre.Movie_id
        WHERE genre.genre = :genre AND CAST(SUBSTR(IMDB.Runtime, 1, INSTR(IMDB.Runtime, ' ') - 1) AS INTEGER) <= :time
    )";
    QMap<QString, QVariant> params;
    params[":genre"] = genre;
    params[":time"] = time;

    return executeQuery(queryString, params);
}

QList<QString> FilmDb::get_films_less_than(int time) {
    QString queryString = R"(
        SELECT Title
        FROM IMDB
        WHERE CAST(SUBSTR(Runtime, 1, INSTR(Runtime, ' ') - 1) AS INTEGER) <= :time
    )";
    QMap<QString, QVariant> params;
    params[":time"] = time;

    return executeQuery(queryString, params);
}

int FilmDb::count_genre(QString genre) {
    QString queryString = R"(
        SELECT COUNT(*)
        FROM genre
        WHERE genre = :genre
    )";
    QMap<QString, QVariant> params;
    params[":genre"] = genre;

    return executeScalarQuery(queryString, params);
}

