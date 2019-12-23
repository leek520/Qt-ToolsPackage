#ifndef MULTICOMBOBOX_H
#define MULTICOMBOBOX_H

#include <QListWidget>
#include <QComboBox>
class MultiComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit MultiComboBox(QWidget* parent=0);
    void addItems(const QStringList &texts);
    void addItem(const QString text);
    bool isSelected(int index);
private slots:
    void stateChanged(int state);
private:
    QListWidget *m_listView;
};
#endif // MULTICOMBOBOX_H
