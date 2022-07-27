#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractListModel>

struct Data {
    Data() {}
    Data(const QString& name, const QString& img, const QString& detail)
        : name(name), img(img), detail(detail){}
    QString name;
    QString img;
    QString detail;
};

class MyModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        NameRole = Qt::UserRole,
        ImgRole,
        DetailRole
    };
    explicit MyModel(QObject *parent = 0);

    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override;
    QHash<int, QByteArray> roleNames() const override;
private:
    QVector< Data > m_data;
};

#endif // MYMODEL_H
