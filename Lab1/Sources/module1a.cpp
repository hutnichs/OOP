#include "module1a.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>

class module1a::Impl : public QDialog {
public:
    explicit Impl(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Другий діалог");
        resize(150,50);

        auto *mijlayout = new QVBoxLayout(this);

        auto *KnopkiBox = new QDialogButtonBox(this);

        QPushButton *nazadButton = KnopkiBox->addButton("< Hазад", QDialogButtonBox::ActionRole);
        QPushButton *takButton = KnopkiBox->addButton("Так", QDialogButtonBox::ActionRole);
        QPushButton *vidminaButton = KnopkiBox->addButton("Відміна", QDialogButtonBox::ActionRole);

        QObject::connect(nazadButton, &QPushButton::clicked, this, [this](){ this->done(QDialogButtonBox::No); });
        QObject::connect(takButton, &QPushButton::clicked, this, [this](){ this->done(QDialogButtonBox::Yes); });
        QObject::connect(vidminaButton, &QPushButton::clicked, this, [this](){ this->done(QDialogButtonBox::Cancel); });

        mijlayout->addWidget(KnopkiBox);
    }
};

module1a::module1a() : pimpl(std::make_unique<Impl>()) {}
module1a::~module1a() = default;

int module1a::open() {
        return pimpl->exec();
}
