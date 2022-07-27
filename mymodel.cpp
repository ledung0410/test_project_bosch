#include "mymodel.h"

MyModel::MyModel(QObject *parent) :
    QAbstractListModel(parent)
{
    m_data
        << Data("British shorthair", "qrc:Image/british_shorthair.jpg", "Hello")
        << Data("British longhair", "qrc:Image/british_longhair.jpg", "Hello")
        << Data("Exotic shorthair", "qrc:Image/exotic_shorthair.jpg", "Hello");
}

int MyModel::rowCount( const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return m_data.count();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if ( !index.isValid() )
        return QVariant();

    const Data &data = m_data.at(index.row());
    if ( role == NameRole ){
        return data.name;
    }
    else if ( role == ImgRole )
        return data.img;
    else if ( role == DetailRole )
        return data.detail;
    else
        return QVariant();
}

//--> slide
QHash<int, QByteArray> MyModel::roleNames() const
{
    static QHash<int, QByteArray> mapping {
        {NameRole, "name"},
        {ImgRole, "img"},
        {DetailRole, "detail"}
    };
    return mapping;
}
