#ifndef COLLECTION_H
#define COLLECTION_H
#include<QApplication>
#include<QVector>
#include<QPushButton>
#include<QVBoxLayout>

class collection : public QWidget
{
    Q_OBJECT
    QVector<QObject*> widgets;
    QPushButton* add_button;
    QVBoxLayout* m_layout;
    int count;
public:
    collection(QWidget* parent = nullptr);
    ~collection();
    void addNew(QObject* new_object);
private slots:
    void ClickedSLot();
};

#endif // COLLECTION_H
