#include "multicombobox.h"
#include <QLineEdit>
#include <QCheckBox>
MultiComboBox::MultiComboBox(QWidget *parent) :
    QComboBox(parent)
{
    m_listView = new QListWidget();
    //设置数据源到显示控件中
    this->setModel(m_listView->model());
    this->setView(m_listView);
    this->setEditable(true);    //生成QLineEdit
    QLineEdit* lineEdit = this->lineEdit();
    if (lineEdit)
        lineEdit->setReadOnly(true);
}

void MultiComboBox::addItems(const QStringList &texts)
{
    for(int i=0;i<texts.count();i++){
        addItem(texts.at(i));
    }
}

void MultiComboBox::addItem(const QString text)
{
    QListWidgetItem *pItem = new QListWidgetItem(m_listView);
    m_listView->addItem(pItem);
    QCheckBox *pCheckBox = new QCheckBox(this);
    pCheckBox->setText(text);
    m_listView->addItem(pItem);
    m_listView->setItemWidget(pItem, pCheckBox);
    connect(pCheckBox, SIGNAL(stateChanged(int)),
            this, SLOT(stateChanged(int)));
}

bool MultiComboBox::isSelected(int index)
{
    QListWidgetItem *pItem = m_listView->item(index);
    QCheckBox *pCheckBox = dynamic_cast<QCheckBox *>(m_listView->itemWidget(pItem));
    if (pCheckBox)
        return pCheckBox->isChecked();
    else
        return false;
}

void MultiComboBox::stateChanged(int state)
{
    Q_UNUSED(state);
    QString strSel;
    //QCheckBox *pSenderCheckBox = dynamic_cast<QCheckBox *>(sender());
    for (int i=0;i<m_listView->count();i++){
        QListWidgetItem *pItem = m_listView->item(i);
        QCheckBox *pCheckBox = dynamic_cast<QCheckBox *>(m_listView->itemWidget(pItem));
        if (pCheckBox->isChecked())
            strSel.append(pCheckBox->text()).append(";");
    }
    lineEdit()->setText(strSel.left(strSel.size()-1));
    lineEdit()->setToolTip(strSel.left(strSel.size()-1));
}
