#ifndef DLG_ADD_H
#define DLG_ADD_H
#include <vector>
#include <string>
#include <QDialog>
using namespace std;
namespace Ui {
class dlg_add;
}

class dlg_add : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_add(QWidget *parent = nullptr);
    ~dlg_add();
    
    vector<string> getvs();

    void setType(bool isAdd)
    {
        m_isAdd=isAdd;
    }

private slots:
    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::dlg_add *ui;
    bool m_isAdd;
};



#endif // DLG_ADD_H

