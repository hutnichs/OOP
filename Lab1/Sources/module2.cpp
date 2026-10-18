#include "module2.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QDialog>
#include <QDialogButtonBox>
#include <QPushButton>


class module2::Impl : public QWidget {

public:
    explicit Impl(QWidget *parent = nullptr) : QWidget(parent) {}

public: signals:
    void textSelected(const QString &text);
};

module2::module2() : pimpl(std::make_unique<Impl>()) {}
module2::~module2() = default;

void module2::open(std::function<void(const QString&)> onTextSelected) {

    QDialog listDialog(pimpl.get());
    listDialog.setWindowTitle("Робота 2");
    listDialog.setMinimumSize(300, 250);

    auto *layout = new QVBoxLayout(&listDialog);
    auto *listBox = new QListWidget(&listDialog);

    listBox->addItems({"ІМ-51","ІМ-52","ІМ-53","ІМ-54","ІМ-55","ІМ-о51","ІП-51","ІП-52","ІП-53","ІП-54","ІП-55","ІП-56","ІО-51","ІО-52","ІО-53","ІО-54","ІО-55","ІО-56"});

    listBox->setCurrentRow(0);
    layout->addWidget(listBox);
    auto *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &listDialog);
    buttonBox->button(QDialogButtonBox::Ok)->setText("Так");
    buttonBox->button(QDialogButtonBox::Cancel)->setText("Відміна");
    layout->addWidget(buttonBox);

    QObject::connect(buttonBox, &QDialogButtonBox::accepted, &listDialog, &QDialog::accept);
    QObject::connect(buttonBox, &QDialogButtonBox::rejected, &listDialog, &QDialog::reject);


    int i = listDialog.exec();
    if(i == QDialog::Accepted){

        QString text = listBox->currentItem()->text();
        if (onTextSelected) {
            onTextSelected(text);
        }
    }
    if(i == QDialog::Rejected){
        return;
    }
}
