#include "module1.h"
#include "module1a.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>

class module1::Impl : public QDialog {
public:
    explicit Impl(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Перший діалог");
        resize(100, 50);

        auto *rozkladka = new QVBoxLayout(this);

        auto *knopkaBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
        knopkaBox->button(QDialogButtonBox::Ok)->setText("Далі >");
        knopkaBox->button(QDialogButtonBox::Cancel)->setText("Відміна");

        rozkladka->addWidget(knopkaBox);

        connect(knopkaBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(knopkaBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    }
};

module1::module1() : pimpl(std::make_unique<Impl>()) {}
module1::~module1() = default;

void module1::open() {

    while(1){

        if (pimpl->exec() == QDialog::Accepted){

            module1a drygiyDialog;

            switch(drygiyDialog.open()){
            case QDialogButtonBox::No:
                break;
            case QDialogButtonBox::Yes:
                return;
            case QDialogButtonBox::Cancel:
                return;
            default:    //Якщо натискать 'x'
                return;
            }
        }
        else{
            return;
        }
    }
}
