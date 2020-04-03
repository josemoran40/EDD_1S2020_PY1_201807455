#ifndef LEERJSON_H
#define LEERJSON_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>
#include <iostream>
#include "circulardoble.h"
using namespace std;

class leerJson
{
public:
    leerJson(){


    };



    void jsonExample(QString filename, CircularDoble *&dobles,CircularDoble *&triples, CircularDiccionario *&diccionario, int &dimension ){
        QFile file;
        QString val;
        file.setFileName(filename);
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        val = file.readAll();
        file.close();
        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject jsonObject = d.object();
        //qDebug()<< "Dimension:";
        //qDebug()<< jsonObject.value(QStringLiteral("dimension")).toInt();
        dimension = jsonObject.value(QStringLiteral("dimension")).toInt();
        QJsonObject artista = jsonObject["casillas"].toObject();
        QJsonArray jsonArray3 = artista["dobles"].toArray();
        QJsonArray jsonArray4 = artista["triples"].toArray();

        foreach (const QJsonValue & value, jsonArray3) {
            QJsonObject obj = value.toObject();
            QJsonArray arrayEvento = obj["dobles"].toArray();
            //nombre.append(artista["Name"].toString());
          //  qDebug()<< "Coordenada doble x y ";
           // qDebug()<< obj.value(QStringLiteral("x")).toInt();
            //qDebug()<< obj.value(QStringLiteral("y")).toInt();
            dobles->agregarFinal(obj.value(QStringLiteral("x")).toInt(),obj.value(QStringLiteral("y")).toInt());
        }
        foreach (const QJsonValue & value, jsonArray4) {
            QJsonObject obj = value.toObject();
            QJsonArray arrayEvento = obj["triples"].toArray();
            //nombre.append(artista["Name"].toString());
            //qDebug()<< "Coordenada trple x y ";
            //qDebug()<< obj.value(QStringLiteral("x")).toInt();
            //qDebug()<< obj.value(QStringLiteral("y")).toInt();
            triples->agregarFinal(obj.value(QStringLiteral("x")).toInt(),obj.value(QStringLiteral("y")).toInt());
        }
        QJsonArray jsonArray5 = jsonObject["diccionario"].toArray();
       // qDebug()<< "DICCIONARIO";
        foreach (const QJsonValue & value, jsonArray5) {
            QJsonObject obj = value.toObject();
            QJsonObject palabra = obj["palabra"].toObject();
            //nombre.append(artista["Name"].toString());
         //   qDebug()<< "Palabra de diccionario";
           // qDebug() << obj.value(QStringLiteral("palabra")).toString();
            diccionario->agregarFinal(obj.value(QStringLiteral("palabra")).toString().toUtf8().constData());
        }

    }
};




#endif // LEERJSON_H
